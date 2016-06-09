//
// Created by School on 6/9/16.
//

#include "draw.h"
#include "syscalls.h"

void draw_pixel(int x, int y, color_t color) {
    int horizontal = x, vertical = y;

    unsigned char *fb = get_frame_buffer();

    int address = get_address_from_x_y(horizontal, vertical);

    fb[address] = (unsigned char) color;
    fb[address+1] = (unsigned char) color;
}


int get_address_from_x_y(int horizontal, int vertical) {
    return (int) (vertical + (horizontal * get_horizontal_screen_size()));
}

void draw_rect(int x1, int y1, int width, int height, color_t c) {

}

void draw_text(int x, int y, const char *text, color_t c) {

}

int x_y_to_buffer(int x, int y) {

}