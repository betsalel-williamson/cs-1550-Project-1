//
// Created by Betsalel Williamson on 6/4/16.
//

#include <stdio.h>
#include "syscalls.h"

int main(int argc, char **argv) {

    write_to_frame_buffer({(unsigned short *) 0xffff}, 1);
    puts("hello");
    return 0;
}