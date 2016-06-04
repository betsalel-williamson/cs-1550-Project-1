//
// Created by Merlin on 16/11/15.
//

#include "gtest/gtest.h"

TEST(BasicTest, TrueTest ){
    EXPECT_EQ(true,true);
}


TEST(BasicTest, FailTest ){
    EXPECT_EQ(false, false);
}


TEST(BasicTest, EQTest){
    EXPECT_EQ(6,6);
}

