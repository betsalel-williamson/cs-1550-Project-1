//
// Created by School on 6/9/16.
//

#include <lib/include/draw.h>
#include "syscalls.h"
#include "color.h"

void color_whole_screen(color_t color) {
    int h = (int) get_horizontal_screen_size(), v = (int) get_vertical_screen_size();

    int y;
    for (y = 0; y < v; ++y) {
        int x;
        for (x = 0; x < h; ++x) {
            draw_pixel(x, y, color);
        }
    }


    sleep_ms(1500);
}

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