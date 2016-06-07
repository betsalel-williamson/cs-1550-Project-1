//
// Created by School on 6/4/16.
//

#include <fcntl.h>
#include <sys/mman.h>
#include "syscalls.h"

void init_graphics() {
    int fd;
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    char *pathname = "/dev/fb0";

    fd = open(pathname, O_WRONLY | O_CREAT | O_TRUNC, mode);

    size_t len = 640;

    int * address = mmap(0, len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    *address = 1;
/* Use data at address. */
}

int open_framebuffer(int options){
    return open("/dev/fb0", options);
}