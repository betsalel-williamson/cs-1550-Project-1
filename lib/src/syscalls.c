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

    struct fb_var_screeninfo screen_info;
    struct fb_fix_screeninfo fixed_info;
    char *buffer = NULL;
    size_t buflen;
    int fd = -1;
    int r = 1;

    fd = open("/dev/fb0", O_RDWR);
    if (fd >= 0)
    {
        if (!ioctl(fd, FBIOGET_VSCREENINFO, &screen_info) &&
            !ioctl(fd, FBIOGET_FSCREENINFO, &fixed_info))
        {
            buflen = screen_info.yres_virtual * fixed_info.line_length;
            buffer = mmap(NULL,
                          buflen,
                          PROT_READ|PROT_WRITE,
                          MAP_SHARED,
                          fd,
                          0);
            if (buffer != MAP_FAILED)
            {
                puts((const char *) buflen);
                /*
                 * TODO: something interesting here.
                 * "buffer" now points to screen pixels.
                 * Each individual pixel might be at:
                 *    buffer + x * screen_info.bits_per_pixel/8
                 *           + y * fixed_info.line_length
                 * Then you can write pixels at locations such as that.
                 */

                r = 0;   /* Indicate success */
            }
            else
            {
                perror("mmap");
            }
        }
        else
        {
            perror("ioctl");
        }
    }
    else
    {
        perror("open");
    }

    /*
     * Clean up
     */
    if (buffer && buffer != MAP_FAILED)
        munmap(buffer, buflen);
    if (fd >= 0)
        close(fd);

//    return r;

//    struct fb_var_screeninfo screen_info;
//    struct fb_fix_screeninfo fixed_info;
//
//    if (ioctl(FRAME_BUFFER_FILE_DESCRIPTOR, FBIOGET_VSCREENINFO, &varInfo) == -1) {
////        ERR("Failed FBIOGET_VSCREENINFO on %s (%s)\n", FBVID_DEVICE,
////            strerror(errno));
////        return FAILURE;
//    }

//    ioctl(FBIOGET_VSCREENINFO);
    clear_screen();
}

void exit_graphics(){
    clear_screen();
}

int open_frame_buffer(int options) {
    return open(FRAME_BUFFER_FILE_DESCRIPTOR, options);
}

#define MS_TO_SLEEP 500

int write_to_frame_buffer(unsigned short *write_buffer, size_t num_bytes) {

    int filedesc = open_frame_buffer(O_WRONLY | O_APPEND);

    int output = filedesc;

    if (filedesc >= 0) {

        if ((write(filedesc, (void *) write_buffer, num_bytes)) != num_bytes) {
            output = -1;
        } else {
            output = (int) num_bytes;
        }
    }

    sleep_ms(MS_TO_SLEEP);

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
    struct timespec req = {0};
    time_t sec = (int) (ms / 1000);
    ms = ms - (sec * 1000);
    req.tv_sec = sec;
    req.tv_nsec = ms * 1000000L;
    while (nanosleep(&req, &req) == -1 && errno == EINTR)
        continue;
}

void clear_screen(){
    const char msg[] = "\033[2J";
    syscall(4, STDOUT_FILENO, msg, sizeof(msg)-1);
}

