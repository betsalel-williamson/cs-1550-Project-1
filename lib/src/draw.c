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

void draw_text(int x, int y, const char *text, color_t c) {
    unsigned short *fb = get_frame_buffer();

    int width = 8;
    int height = 16;
    int address = get_address_from_x_y(x, y);
    int temp_address = address;

    for (int i = 0; text[i] != '\0'; ++i) {
        int letter = text[i];
        char byte = iso_font[letter * 16 + i];
        int j;
        for (j = 0; j < height; ++j) {

            int k;

            for (k = 0; k < width; ++k) {

                if (byte & (1 << k)) {
                    fb[temp_address++] = c;
                }
            }

            temp_address = (int) (address + (j * get_horizontal_screen_size()));
        }

    }


}

int x_y_to_buffer(int x, int y) {

}