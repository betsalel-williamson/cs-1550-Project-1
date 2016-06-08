//
// Created by School on 6/4/16.
//

#include <fcntl.h>
#include <sys/mman.h>
#include <stdio.h>
#include "syscalls.h"

void init_graphics() {

    puts("Hello");

}

int open_frame_buffer(int options) {
    return open("/dev/fb0", options);
}

unsigned char * read_frame_buffer(size_t buffer_size, off_t offset, off_t pa_offset) {
    int fd = open_frame_buffer(O_RDONLY);

    return  mmap(NULL, buffer_size + offset - pa_offset, PROT_READ,
                 MAP_SHARED, fd, pa_offset);
}