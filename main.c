//
// Created by Betsalel Williamson on 6/4/16.
//

#include <stdio.h>
#include "syscalls.h"

int main(int argc, char **argv) {

    unsigned short buffer[2000] = {};
    for (int i = 0; i < 2000; ++i) {
        buffer[i] = 0x9999;
    }

//    puts("\033[2J");

    write_to_frame_buffer(buffer, 2000);

    return 0;
}