//
// Created by School on 6/9/16.
//

#include "gtest/gtest.h"
#include "draw.h"
#include "color.h"
#include "library.h"
#include "mother.h"

#define BYTES_TO_READ 32

TEST(DrawTests, Draw_white_pixel) {
    // when called to draw pixel at 0,0
    draw_pixel(0, 0, White);

    mother::print_buffer(read_frame_buffer(BYTES_TO_READ), BYTES_TO_READ);

    // then pixel is drawn, reading framebuffer will show that something was drawn
    unsigned char * buffer = read_frame_buffer(2);

    ASSERT_EQ(0xff, buffer[0]);
    ASSERT_EQ(0xff, buffer[1]);
}


TEST(DrawTests, Get_address_from_x_y) {
    ASSERT_EQ(0, get_address_from_x_y(0,0));

    ASSERT_EQ(639, get_address_from_x_y(639,0));

    ASSERT_EQ(-1, get_address_from_x_y(640,0));

    ASSERT_EQ(640, get_address_from_x_y(0,1));

    ASSERT_EQ(480*640, get_address_from_x_y(0,479));

    ASSERT_EQ(-1, get_address_from_x_y(0,480));

}

TEST(DrawTests, Draw_blue_pixel) {
    // when called to draw pixel at 0,0
    draw_pixel(0, 0, Blue);

    mother::print_buffer(read_frame_buffer(BYTES_TO_READ), BYTES_TO_READ);

    // then pixel is drawn, reading framebuffer will show that something was drawn
    unsigned char * buffer = read_frame_buffer(2);

    ASSERT_EQ(0x1f, buffer[0]);
    ASSERT_EQ(0x00, buffer[1]);
}


TEST(DrawTests, Color_whole_screen_test) {

    color_whole_screen(White);

}

