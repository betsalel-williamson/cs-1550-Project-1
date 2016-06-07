//
// Created by Merlin on 16/11/15.
//

#include <fcntl.h>
#include "gtest/gtest.h"

TEST(BasicTest, Open_zeroth_framebuffer){
    // opening this file will work

    int filedesc = open("/dev/fb0", O_WRONLY | O_APPEND);
    printf("Opened filedesc: %d", filedesc);

    ASSERT_GT(filedesc,0);
}

TEST(BasicTest, Write_to_zeroth_framebuffer){

    int filedesc = open("/dev/fb0", O_WRONLY | O_APPEND);

    if(filedesc < 0){
        FAIL()  << "Failed to open";
    }

    int writebuffer[1] = {1};
    ssize_t bytesWritten;

    if((bytesWritten = write(filedesc,(void *) writebuffer, 1)) != 1)
    {
        FAIL() << "Failed to write";
    }
    ASSERT_EQ(bytesWritten, 1);
}

TEST(BasicTest, Read_from_zeroth_framebuffer){
    int filedesc = open("/dev/fb0", O_WRONLY | O_APPEND);
    printf("Opened filedesc: %d", filedesc);

    int readbuffer[1] = {0};
    ssize_t bytesRead;
    if ((bytesRead = read(filedesc,readbuffer,1)) == -1){
        FAIL() << "Failed to read";
    }

    ASSERT_EQ(bytesRead, 1);
}