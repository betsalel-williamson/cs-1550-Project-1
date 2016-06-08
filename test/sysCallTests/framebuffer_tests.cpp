//
// Created by Merlin on 16/11/15.
//

#include <fcntl.h>
#include "syscalls.h"
#include "gtest/gtest.h"
#include "mother.h"

TEST(BasicTest, Open_zeroth_framebuffer) {
    // opening this file will work

    int filedesc = open_frame_buffer(O_WRONLY | O_APPEND);
    printf("Opened filedesc: %d\n", filedesc);

    ASSERT_GT(filedesc, 0);
}

TEST(BasicTest, Write_to_zeroth_framebuffer) {

    int filedesc = open_frame_buffer(O_WRONLY | O_APPEND);

    if (filedesc < 0) {
        FAIL() << "Failed to open";
    }

    int writebuffer[1] = {5};
    ssize_t bytesWritten;

    if ((bytesWritten = write(filedesc, (void *) writebuffer, 1)) != 1) {
        FAIL() << "Failed to write";
    }
    ASSERT_EQ(bytesWritten, 1);
}
