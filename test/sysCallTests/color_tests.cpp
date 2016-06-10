//
// Created by School on 6/8/16.
//

#include "color.h"
#include "gtest/gtest.h"
#include "library.h"

TEST(Color_tests, Black_test) {
    ASSERT_EQ(Black, rgb(0, 0, 0));
}

TEST(Color_tests, Navy_test) {
    ASSERT_EQ(Navy, rgb(0, 0, 128));
}

TEST(Color_tests, DarkGreen_test) {
    ASSERT_EQ(DarkGreen, rgb(0, 128, 0));
}

TEST(Color_tests, DarkCyan_test) {
    ASSERT_EQ(DarkCyan, rgb(0, 128, 128));
}

TEST(Color_tests, Maroon_test) {
    ASSERT_EQ(Maroon, rgb(128, 0, 0));
}

TEST(Color_tests, Purple_test) {
    ASSERT_EQ(Purple, rgb(128, 0, 128));
}

TEST(Color_tests, Olive_test) {
    ASSERT_EQ(Olive, rgb(128, 128, 0));
}

TEST(Color_tests, LightGrey_test) {
    ASSERT_EQ(LightGrey, rgb(192, 192, 192));
}

TEST(Color_tests, DarkGrey_test) {
    ASSERT_EQ(DarkGrey, rgb(128, 128, 128));
}

TEST(Color_tests, Blue_test) {
    ASSERT_EQ(Blue, rgb(0, 0, 255));
}

TEST(Color_tests, Green_test) {
    ASSERT_EQ(Green, rgb(0, 255, 0));
}

TEST(Color_tests, Cyan_test) {
    ASSERT_EQ(Cyan, rgb(0, 255, 255));
}

TEST(Color_tests, Red_test) {
    ASSERT_EQ(Red, rgb(255, 0, 0));
}

TEST(Color_tests, Magenta_test) {
    ASSERT_EQ(Magenta, rgb(255, 0, 255));
}

TEST(Color_tests, Yellow_test) {
    ASSERT_EQ(Yellow, rgb(255, 255, 0));
}

TEST(Color_tests, White_test) {
    ASSERT_EQ(White, rgb(255, 255, 255));
}

TEST(Color_tests, Orange_test) {
    ASSERT_EQ(Orange, rgb(255, 165, 0));
}

TEST(Color_tests, GreenYellow_test) {
    ASSERT_EQ(GreenYellow, rgb(173, 255, 47));
}
