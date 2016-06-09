//
// Created by School on 6/9/16.
//

#include "syscalls.h"
#include "color.h"

#define SAMPLE_COLOR_BUFFER_SIZE (int) 1280*480
void draw_sample_colors() {
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