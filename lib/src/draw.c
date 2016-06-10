//
// Created by School on 6/9/16.
//

#include <stddef.h>
#include <lib/include/iso_font.h>
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
//        return -1;
        return 0;
    }

    if (vertical > get_vertical_screen_size()) {
//        return -1;
        return 0;
    }

    int address = 0;

    address += horizontal;

    address += (vertical - 1) * get_horizontal_screen_size();

    // revert to index logic
    address -= 1;

    return address;
}

void draw_rect(int x1, int y1, int width, int height, color_t c) {
    unsigned short *fb = get_frame_buffer();

    int address = get_address_from_x_y(x1, y1);
    int temp_address = address;

    int i;
    for (i = 0; i < height; ++i) {

        int j;

        for (j = 0; j < width; ++j) {

            fb[temp_address++] = c;

        }

        temp_address = (int) (address + (i * get_horizontal_screen_size()));
    }
}

void increment_x_y(int *x, int *y) {
    int my_x = *x;
    int my_y = *y;

    int go_to_next_row = 0;
    if (my_x + 8 > get_horizontal_screen_size()) {
        go_to_next_row = 1;
    }

    int go_to_next_col = 0;
    if (my_y + 16 > get_vertical_screen_size()) {
        go_to_next_col = 1;
    }

    if (go_to_next_row) {
        *x = 0;
    } else {
        *x += 8;
    }

    if (go_to_next_col) {
        *y = 0;
    }
}

void draw_text(int x, int y, const char *text, color_t c) {
    unsigned short *fb = get_frame_buffer();
    if (x+8 > get_horizontal_screen_size()) {
//        return -1;
        x = 0;

        draw_text(0, (int) (get_vertical_screen_size() - 32), "error; x text out of bounds", Red);
    }

    if (y+16 > get_vertical_screen_size()) {
//        return -1;
        y =  0;

        draw_text(0, (int) (get_vertical_screen_size() - 16), "error; y text out of bounds", Red);
    }

    int width = 8;
    int height = 16;
    int address = get_address_from_x_y(x, y);
    int temp_address = address;

    int i;
    for (i = 0; text[i] != '\0'; ++i, increment_x_y(&x, &y), address = get_address_from_x_y(x, y)) {
        int letter = text[i];

        int j;
        for (j = 0; j < height; ++j) {
            char byte = iso_font[letter * 16 + j];

            int k;
            for (k = 0; k < width; ++k, ++temp_address) {

                if (byte & (1 << k)) {
                    fb[temp_address] = c;
                }
            }

            temp_address = (int) (address + (j * get_horizontal_screen_size()));
        }
    }
}

