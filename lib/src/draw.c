//
// Created by School on 6/9/16.
//

#include <stddef.h>
#include "draw.h"
#include "library.h"

void draw_pixel(int x, int y, color_t color) {
    unsigned short *fb = get_frame_buffer();

    int address = get_address_from_x_y(x, y);

    fb[address] = color;
}


int get_address_from_x_y(int horizontal, int vertical) {
    // using index logic.
    // convert to counting logic
    horizontal += 1;
    vertical += 1;

    if (horizontal > get_horizontal_screen_size()) {
        return -1;
    }

    if (vertical > get_vertical_screen_size()) {
        return -1;
    }

    int address = 0;

    address += horizontal;

    address += (vertical - 1) * get_horizontal_screen_size();

    // revert to index logic
    address -= 1;

    return address;
}

void draw_rect(int x1, int y1, int width, int height, color_t c) {

}

void draw_text(int x, int y, const char *text, color_t c) {

}

int x_y_to_buffer(int x, int y) {

}