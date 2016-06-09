//
// Created by School on 6/4/16.
//

#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdint.h>
#include <time.h>
#include "syscalls.h"

void init_graphics() {
    //
}

int open_frame_buffer(int options) {
    return open("/dev/fb0", options);
}

#define MS_TO_SLEEP 1500
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

unsigned char * read_frame_buffer_with_offset(size_t buffer_size, off_t offset, off_t pa_offset);

unsigned char *read_frame_buffer_with_offset(size_t buffer_size, off_t offset, off_t pa_offset) {
    int fd = open_frame_buffer(O_RDONLY);

    return mmap(NULL, buffer_size + offset - pa_offset, PROT_READ,
                MAP_SHARED, fd, pa_offset);
}

unsigned char *read_frame_buffer(size_t buffer_size) {
    int fd = open_frame_buffer(O_RDONLY);

    return read_frame_buffer_with_offset(buffer_size,0,0);
}

void sleep_ms(long ms){
    nanosleep((const struct timespec *) (ms * 1000000), NULL);
}
