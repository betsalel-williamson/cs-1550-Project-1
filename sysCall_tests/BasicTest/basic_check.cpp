//
// Created by Merlin on 16/11/15.
//

#include <fcntl.h>
#include "gtest/gtest.h"

TEST(BasicTest, Open_zeroth_framebuffer){
    // opening this file will work

    int filedesc = open("/dev/fb0", O_WRONLY | O_APPEND);
    printf("Opened filedesc: %d\n", filedesc);

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

#define BUFFER_SIZE 1024

TEST(BasicTest, Read_from_zeroth_framebuffer){
    int filedesc = open("/dev/fb0", O_RDONLY);
    printf("Opened filedesc: %d\n", filedesc);

    unsigned char *readbuffer = (unsigned char*) malloc(BUFFER_SIZE);

    ssize_t bytesRead;
    if ((bytesRead = read(filedesc,(void *)readbuffer,BUFFER_SIZE)) < 0){
        printf("Bytes read: %d\n", (int) bytesRead);
        FAIL() << "Failed to read";
    }

    ASSERT_EQ(bytesRead, BUFFER_SIZE);
    printf("Bytes read: %d\n", (int) bytesRead);

    int ii;

    // printf("0x"); -- uncomment if you want to start with "0x"

    for(ii = 0; ii < BUFFER_SIZE; ii++) {
        printf("%02x", (unsigned int)(readbuffer[ii]));
        if(ii%4 == 3) printf(" ");    // groups of 8: makes more readable
        // uncomment if you want "all one line"
        if(ii%32 == 31) printf("\n"); // ditto
    }

    printf("\n");
}