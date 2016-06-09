//
// Created by School on 6/9/16.
//

#ifndef MAIN_DRAW_H
#define MAIN_DRAW_H

#include "color.h"

#ifdef __cplusplus
extern "C" {
#endif

void draw_pixel(int x, int y, color_t color);
int get_address_from_x_y(int horizontal, int vertical);

void draw_rect(int x1, int y1, int width, int height, color_t c);

void draw_text(int x, int y, const char *text, color_t c);

#ifdef __cplusplus
}
#endif

#endif //MAIN_DRAW_H
