//
// Created by Merlin on 16/11/15.
//

#include <fcntl.h>
#include "gtest/gtest.h"

TEST(BasicTest, Get_Zeroth_Framebuffer){
    // opening this file will work

    int filedesc = open("/dev/fb0", O_WRONLY | O_APPEND);
    printf("Opened filedesc: %d", filedesc);

    ASSERT_GT(filedesc,0);
}

TEST(BasicTest, Write_To_Zeroth_Framebuffer){

    int filedesc = open("/dev/fb0", O_WRONLY | O_APPEND);

    if(filedesc < 0){
        FAIL();
    }

    int writebuffer[1] = {1};
    ssize_t bytesWritten;

    if((bytesWritten = write(filedesc,(void *) writebuffer, 1)) != 1)
    {
        FAIL();
    }
    ASSERT_EQ(bytesWritten, 1);

    int readbuffer[1] = {0};
    ssize_t bytesRead;
    if ((bytesRead = read(filedesc,readbuffer,1)) != 1){
        FAIL();
    }

    ASSERT_EQ(bytesRead, 1);
}


TEST(BasicTest, FailTest ){
    EXPECT_EQ(false, false);
}


TEST(BasicTest, EQTest){
    EXPECT_EQ(6,6);
}

