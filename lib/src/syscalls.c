//
// Created by School on 6/4/16.
//

#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdint.h>
#include <time.h>
#include <errno.h>
#include <sys/ioctl.h>
#include "syscalls.h"

#include <linux/fb.h>
#include <stdio.h>

#define FRAME_BUFFER_FILE_DESCRIPTOR "/dev/fb0"

struct singleton {
    char sharedData[256];
    unsigned char *frame_buffer;
    void *addr;
    size_t len;
    int prot;
    int flags;
    int fildes;
    off_t off;
};

struct singleton *get_instance() {
    static struct singleton *instance = NULL;

    if (instance == NULL) {
        instance = mmap(NULL, sizeof(struct singleton), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, 0, 0);
        int fd = open_frame_buffer(O_RDWR);
        instance->prot = PROT_READ | PROT_WRITE;
        instance->flags = MAP_SHARED;
        instance->len = get_screen_size();
        instance->frame_buffer = mmap(NULL, instance->len,
                                      instance->prot,
                                      instance->flags, fd, 0);
        close(fd);
    }

    return instance;
}

void init_graphics() {
    clear_screen();
}

size_t get_screen_size() {

    return get_horizontal_screen_size() * get_vertical_screen_size();
}

static size_t _h = (size_t) -1;

size_t get_horizontal_screen_size() {
    size_t buflen = (size_t) -1;
    if (_h == -1) {
        struct fb_fix_screeninfo fixed_info;
        char *buffer = NULL;

        int fd = -1;
        int r = 1;

        fd = open_frame_buffer(O_RDWR);
        if (fd >= 0) {
            if (!ioctl(fd, FBIOGET_FSCREENINFO, &fixed_info)) {
                buflen = fixed_info.line_length;
            }
            else {
                perror("open");
            }

            if (fd >= 0) {
                if (close(fd) != 0) {
                    buflen = (size_t) -1;
                }
            }

        }
    } else {
        buflen = _h;
    }

    return buflen;
}

static size_t _v = (size_t) -1;

size_t get_vertical_screen_size() {
    size_t buflen = (size_t) -1;

    if (_v == -1) {
        struct fb_var_screeninfo screen_info;
        char *buffer = NULL;

        int fd = -1;
        int r = 1;

        fd = open_frame_buffer(O_RDWR);
        if (fd >= 0) {
            if (!ioctl(fd, FBIOGET_VSCREENINFO, &screen_info)) {
                buflen = screen_info.yres_virtual;
            }
            else {
                perror("open");
            }

            if (fd >= 0) {
                if (close(fd) != 0) {
                    buflen = (size_t) -1;
                }
            }
        }
    } else {
        buflen = _v;
    }

    return buflen;
}

void exit_graphics() {
    clear_screen();
}

int open_frame_buffer(int options) {
    return open(FRAME_BUFFER_FILE_DESCRIPTOR, options);
}

#define MS_TO_SLEEP 500

int write_to_frame_buffer(unsigned short *write_buffer, int num_bytes) {

    int filedesc = open_frame_buffer(O_WRONLY | O_APPEND);

    int output = filedesc;

    if (filedesc >= 0) {

        if ((write(filedesc, (void *) write_buffer, (size_t) num_bytes)) != num_bytes) {
            output = -1;
        } else {
            output = (int) num_bytes;
        }
    }

    sleep_ms(MS_TO_SLEEP);

    if (close(filedesc) != 0) {
        output = -1;
    }

    return output;
}

unsigned char *read_frame_buffer_with_offset(size_t buffer_size, off_t offset, off_t pa_offset) {
    struct singleton *instance = get_instance();
    return instance->frame_buffer;
//
//    int fd = open_frame_buffer(O_RDONLY);
//
//    return mmap(NULL, buffer_size + offset - pa_offset, PROT_READ,
//                MAP_SHARED, fd, pa_offset);
}

unsigned char *read_frame_buffer(size_t buffer_size) {

    return read_frame_buffer_with_offset(buffer_size, 0, 0);
}


unsigned char *get_frame_buffer() {
    struct singleton *instance = get_instance();
    return instance->frame_buffer;
}

// implementation from http://cc.byexamples.com/2007/05/25/nanosleep-is-better-than-sleep-and-usleep/
void sleep_ms(long ms) {
    struct timespec request = {0};

    time_t sec = (int) (ms / 1000);
    ms = ms - (sec * 1000);

    request.tv_sec = sec;
    request.tv_nsec = ms * 1000000L;

    while (nanosleep(&request, &request) == -1 && errno == EINTR)
        continue;
}

void clear_screen() {
    const char msg[] = "\033[2J";
    syscall(4, STDOUT_FILENO, msg, sizeof(msg) - 1);
}


char getkey() {
    return 'a';
};

