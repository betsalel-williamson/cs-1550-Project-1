//
// Created by Betsalel Williamson on 6/4/16.
//

#include <stdio.h>
#include <signal.h>
#include <sys/param.h>
#include <stdlib.h>
#include "syscalls.h"
#include "color.h"

void draw_sample();

/**
 * Handle quit to correctly exit and restore state on CTR-C.
 */
void sig_handler(int signo) {
    printf("\n\nProcessing received signal: %d\n", signo);

    exit_graphics();

    if (signo == SIGINT)
    {
        exit(EXIT_SUCCESS);
    }
    // else
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    signal(SIGINT, sig_handler);

    init_graphics();

    draw_sample_colors();

    exit_graphics();

    exit(EXIT_SUCCESS);
}

# define SAMPLE_BUFFER_SIZE 1280*240
void draw_sample() {
    unsigned short buffer[SAMPLE_BUFFER_SIZE] = {};
    int i;
    for (i = 0; i < SAMPLE_BUFFER_SIZE; ++i) {
        buffer[i] = rgb(255, 255, 255);
    }

//    puts("\033[2J");

    write_to_frame_buffer(buffer, SAMPLE_BUFFER_SIZE);
}