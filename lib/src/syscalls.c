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

void init_graphics() {
    clear_screen();
}

int get_screen_size() {

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

    close(filedesc);

    return output;
}

unsigned char *read_frame_buffer_with_offset(size_t buffer_size, off_t offset, off_t pa_offset);

unsigned char *read_frame_buffer_with_offset(size_t buffer_size, off_t offset, off_t pa_offset) {
    int fd = open_frame_buffer(O_RDONLY);

    return mmap(NULL, buffer_size + offset - pa_offset, PROT_READ,
                MAP_SHARED, fd, pa_offset);
}

unsigned char *read_frame_buffer(size_t buffer_size) {
    int fd = open_frame_buffer(O_RDONLY);

    return read_frame_buffer_with_offset(buffer_size, 0, 0);
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

