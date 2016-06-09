//
// Created by School on 6/8/16.
//

#include "gtest/gtest.h"
#include "syscalls.h"

TEST(BasicTest, Black_test) {
    ASSERT_EQ(Black, rgb(0, 0, 0));
}

TEST(BasicTest, Navy_test) {
    ASSERT_EQ(Navy, rgb(0, 0, 128));
}

TEST(BasicTest, DarkGreen_test) {
    ASSERT_EQ(DarkGreen, rgb(0, 128, 0));
}

TEST(BasicTest, DarkCyan_test) {
    ASSERT_EQ(DarkCyan, rgb(0, 128, 128));
}

TEST(BasicTest, Maroon_test) {
    ASSERT_EQ(Maroon, rgb(128, 0, 0));
}

TEST(BasicTest, Purple_test) {
    ASSERT_EQ(Purple, rgb(128, 0, 128));
}

TEST(BasicTest, Olive_test) {
    ASSERT_EQ(Olive, rgb(128, 128, 0));
}

TEST(BasicTest, LightGrey_test) {
    ASSERT_EQ(LightGrey, rgb(192, 192, 192));
}

TEST(BasicTest, DarkGrey_test) {
    ASSERT_EQ(DarkGrey, rgb(128, 128, 128));
}

TEST(BasicTest, Blue_test) {
    ASSERT_EQ(Blue, rgb(0, 0, 255));
}

TEST(BasicTest, Green_test) {
    ASSERT_EQ(Green, rgb(0, 255, 0));
}

TEST(BasicTest, Cyan_test) {
    ASSERT_EQ(Cyan, rgb(0, 255, 255));
}

TEST(BasicTest, Red_test) {
    ASSERT_EQ(Red, rgb(255, 0, 0));
}

TEST(BasicTest, Magenta_test) {
    ASSERT_EQ(Magenta, rgb(255, 0, 255));
}

TEST(BasicTest, Yellow_test) {
    ASSERT_EQ(Yellow, rgb(255, 255, 0));
}

TEST(BasicTest, White_test) {
    ASSERT_EQ(White, rgb(255, 255, 255));
}

TEST(BasicTest, Orange_test) {
    ASSERT_EQ(Orange, rgb(255, 165, 0));
}

TEST(BasicTest, GreenYellow_test) {
    ASSERT_EQ(GreenYellow, rgb(173, 255, 47));
}
