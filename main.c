//
// Created by Betsalel Williamson on 6/4/16.
//

#include <stdio.h>
#include "syscalls.h"

int main(int argc, char **argv) {

    unsigned short buffer[10] = {0x0123,0x0123,0x0123,0x0123,0x0123,0x0123,0x0123,0x0123,0x0123,0x0123};

    puts("\033[2J");

    write_to_frame_buffer(buffer, 1);

    return 0;
}