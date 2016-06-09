//
// Created by School on 6/9/16.
//

#include "draw.h"
#include "syscalls.h"

static unsigned char *_fb = (unsigned char *) -1;

void draw_pixel(int x, int y, color_t color) {
    int horizontal = x, vertical = y;
    unsigned char *fb;

    if (_fb == (unsigned char *) -1) {
        fb = get_frame_buffer();
    } else {
        fb = _fb;
    }

    int address = get_address_from_x_y(horizontal, vertical);

    fb[address] = (unsigned char) color;
    fb[address + 1] = (unsigned char) color >> 8;
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