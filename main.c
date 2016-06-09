//
// Created by Betsalel Williamson on 6/4/16.
//

#include <stdio.h>
#include "syscalls.h"

void draw_sample();
void draw_sample_colors(int ms_to_sleep);

int main(int argc, char **argv) {

    draw_sample_colors(700);

    return 0;
}

# define SAMPLE_BUFFER_SIZE 2000
void draw_sample() {
    unsigned short buffer[SAMPLE_BUFFER_SIZE] = {};
    int i;
    for (i = 0; i < SAMPLE_BUFFER_SIZE; ++i) {
        buffer[i] = rgb(255, 255, 255);
    }

//    puts("\033[2J");

    write_to_frame_buffer(buffer, SAMPLE_BUFFER_SIZE);
}


# define SAMPLE_COLOR_BUFFER_SIZE 32768
void draw_sample_colors(int ms_to_sleep) {
    unsigned short buffer[SAMPLE_COLOR_BUFFER_SIZE] = {};
    int i;
    for (i = 0; i < SAMPLE_COLOR_BUFFER_SIZE; ++i) {
        buffer[i] = Black;
    }

    write_to_frame_buffer(buffer, SAMPLE_COLOR_BUFFER_SIZE);
    for (i = 0; i < SAMPLE_COLOR_BUFFER_SIZE; ++i) {
        buffer[i] = Navy;
    }

    write_to_frame_buffer(buffer, SAMPLE_COLOR_BUFFER_SIZE);
    for (i = 0; i < SAMPLE_COLOR_BUFFER_SIZE; ++i) {
        buffer[i] = DarkGreen;
    }

    write_to_frame_buffer(buffer, SAMPLE_COLOR_BUFFER_SIZE);
    for (i = 0; i < SAMPLE_COLOR_BUFFER_SIZE; ++i) {
        buffer[i] = DarkCyan;
    }

    write_to_frame_buffer(buffer, SAMPLE_COLOR_BUFFER_SIZE);
    for (i = 0; i < SAMPLE_COLOR_BUFFER_SIZE; ++i) {
        buffer[i] = Maroon;
    }

    write_to_frame_buffer(buffer, SAMPLE_COLOR_BUFFER_SIZE);
    for (i = 0; i < SAMPLE_COLOR_BUFFER_SIZE; ++i) {
        buffer[i] = Purple;
    }

    write_to_frame_buffer(buffer, SAMPLE_COLOR_BUFFER_SIZE);
    for (i = 0; i < SAMPLE_COLOR_BUFFER_SIZE; ++i) {
        buffer[i] = Olive;
    }

    write_to_frame_buffer(buffer, SAMPLE_COLOR_BUFFER_SIZE);
    for (i = 0; i < SAMPLE_COLOR_BUFFER_SIZE; ++i) {
        buffer[i] = LightGrey;
    }

    write_to_frame_buffer(buffer, SAMPLE_COLOR_BUFFER_SIZE);
    for (i = 0; i < SAMPLE_COLOR_BUFFER_SIZE; ++i) {
        buffer[i] = DarkGrey;
    }

    write_to_frame_buffer(buffer, SAMPLE_COLOR_BUFFER_SIZE);
    for (i = 0; i < SAMPLE_COLOR_BUFFER_SIZE; ++i) {
        buffer[i] = Blue;
    }

    write_to_frame_buffer(buffer, SAMPLE_COLOR_BUFFER_SIZE);
    for (i = 0; i < SAMPLE_COLOR_BUFFER_SIZE; ++i) {
        buffer[i] = Green;
    }

    write_to_frame_buffer(buffer, SAMPLE_COLOR_BUFFER_SIZE);
    for (i = 0; i < SAMPLE_COLOR_BUFFER_SIZE; ++i) {
        buffer[i] = Cyan;
    }

    write_to_frame_buffer(buffer, SAMPLE_COLOR_BUFFER_SIZE);
    for (i = 0; i < SAMPLE_COLOR_BUFFER_SIZE; ++i) {
        buffer[i] = Red;
    }

    write_to_frame_buffer(buffer, SAMPLE_COLOR_BUFFER_SIZE);
    for (i = 0; i < SAMPLE_COLOR_BUFFER_SIZE; ++i) {
        buffer[i] = Magenta;
    }

    write_to_frame_buffer(buffer, SAMPLE_COLOR_BUFFER_SIZE);
    for (i = 0; i < SAMPLE_COLOR_BUFFER_SIZE; ++i) {
        buffer[i] = Yellow;
    }

    write_to_frame_buffer(buffer, SAMPLE_COLOR_BUFFER_SIZE);
    for (i = 0; i < SAMPLE_COLOR_BUFFER_SIZE; ++i) {
        buffer[i] = White;
    }

    write_to_frame_buffer(buffer, SAMPLE_COLOR_BUFFER_SIZE);
    for (i = 0; i < SAMPLE_COLOR_BUFFER_SIZE; ++i) {
        buffer[i] = Orange;
    }

    write_to_frame_buffer(buffer, SAMPLE_COLOR_BUFFER_SIZE);
    for (i = 0; i < SAMPLE_COLOR_BUFFER_SIZE; ++i) {
        buffer[i] = GreenYellow;
    }

    write_to_frame_buffer(buffer, SAMPLE_COLOR_BUFFER_SIZE);
}