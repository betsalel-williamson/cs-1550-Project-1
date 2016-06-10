//
// Created by School on 6/7/16.
//

#include <fcntl.h>
#include <sys/mman.h>
#include "library.h"
#include "gtest/gtest.h"
#include "mother.h"

#define BYTES_TO_READ 32

TEST(Mmap_tests, Mmap_read) {

    unsigned short *fb = get_frame_buffer();
    mother::print_buffer(fb, BYTES_TO_READ);

}