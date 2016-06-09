//
// Created by School on 6/9/16.
//

#include "draw.h"
#include "syscalls.h"

void draw_pixel(int x, int y, color_t color) {
    unsigned char * fb = get_frame_buffer();

    int address = get_address_from_x_y(x,y);

    fb[address] = (unsigned char) color;
}


int get_address_from_x_y(int x, int y) {
    return (int) (x + (y * get_horizontal_screen_size()));
}

void draw_rect(int x1, int y1, int width, int height, color_t c) {

}

void draw_text(int x, int y, const char *text, color_t c) {

}

int x_y_to_buffer(int x, int y) {

}