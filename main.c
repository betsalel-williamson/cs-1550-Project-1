//
// Created by Betsalel Williamson on 6/4/16.
//

#include <stdio.h>
#include "syscalls.h"

void draw_sample();

int main(int argc, char **argv) {

    draw_sample();

    return 0;
}

void draw_sample() {
    unsigned short buffer[2000] = {};
    int i;
    for (i = 0; i < 2000; ++i) {
        buffer[i] = rgb(255, 255, 255);
    }

//    puts("\033[2J");

    write_to_frame_buffer(buffer, 2000);
}