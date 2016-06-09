//
// Created by School on 6/8/16.
//

#include "color.h"
#include "gtest/gtest.h"
#include "library.h"

TEST(ColorTest, Black_test) {
    ASSERT_EQ(Black, rgb(0, 0, 0));
}

TEST(ColorTest, Navy_test) {
    ASSERT_EQ(Navy, rgb(0, 0, 128));
}

TEST(ColorTest, DarkGreen_test) {
    ASSERT_EQ(DarkGreen, rgb(0, 128, 0));
}

TEST(ColorTest, DarkCyan_test) {
    ASSERT_EQ(DarkCyan, rgb(0, 128, 128));
}

TEST(ColorTest, Maroon_test) {
    ASSERT_EQ(Maroon, rgb(128, 0, 0));
}

TEST(ColorTest, Purple_test) {
    ASSERT_EQ(Purple, rgb(128, 0, 128));
}

TEST(ColorTest, Olive_test) {
    ASSERT_EQ(Olive, rgb(128, 128, 0));
}

TEST(ColorTest, LightGrey_test) {
    ASSERT_EQ(LightGrey, rgb(192, 192, 192));
}

TEST(ColorTest, DarkGrey_test) {
    ASSERT_EQ(DarkGrey, rgb(128, 128, 128));
}

TEST(ColorTest, Blue_test) {
    ASSERT_EQ(Blue, rgb(0, 0, 255));
}

TEST(ColorTest, Green_test) {
    ASSERT_EQ(Green, rgb(0, 255, 0));
}

TEST(ColorTest, Cyan_test) {
    ASSERT_EQ(Cyan, rgb(0, 255, 255));
}

TEST(ColorTest, Red_test) {
    ASSERT_EQ(Red, rgb(255, 0, 0));
}

TEST(ColorTest, Magenta_test) {
    ASSERT_EQ(Magenta, rgb(255, 0, 255));
}

TEST(ColorTest, Yellow_test) {
    ASSERT_EQ(Yellow, rgb(255, 255, 0));
}

TEST(ColorTest, White_test) {
    ASSERT_EQ(White, rgb(255, 255, 255));
}

TEST(ColorTest, Orange_test) {
    ASSERT_EQ(Orange, rgb(255, 165, 0));
}

TEST(ColorTest, GreenYellow_test) {
    ASSERT_EQ(GreenYellow, rgb(173, 255, 47));
}
