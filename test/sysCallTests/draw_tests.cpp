//
// Created by School on 6/9/16.
//

#include "gtest/gtest.h"
#include "draw.h"
#include "color.h"
#include "syscalls.h"

TEST(DrawTests, Draw_pixel) {
    // when called to draw pixel at 0,0
    draw_pixel(0, 0, White);

    // then pixel is drawn, reading framebuffer will show that something was drawn
    unsigned char * buffer = read_frame_buffer(2);

    ASSERT_EQ(0xff, buffer[0]);
    ASSERT_EQ(0xff, buffer[1]);
}
