//
// Created by School on 6/4/16.
//

#ifndef PROJECT1_SYSCALLS_H
#define PROJECT1_SYSCALLS_H

#ifdef __cplusplus
extern "C" {
#endif

void init_graphics();// open, ioctl, mmap

int open_frame_buffer(int);

void exit_graphics();// ioctl

void clear_screen();// write

char getkey();// select, read

void sleep_ms(long ms);// nanosleep

typedef unsigned short color_t;

void draw_pixel(int x, int y, color_t color);

void draw_rect(int x1, int y1, int width, int height, color_t c);

void draw_text(int x, int y, const char *text, color_t c);

//#include <stdio.h>
//
//void print_buffer(unsigned char * buffer, int buffer_size) {
//    int i;
//
//    // printf("0x"); -- uncomment if you want to start with "0x"
//
//    for (i = 0; i < buffer_size; i++) {
//        printf("%02x", (unsigned int) (buffer[i]));
//        if (i % 4 == 3) printf(" ");    // groups of 8: makes more readable
//        // uncomment if you want "all one line"
//        if (i % 32 == 31) printf("\n"); // ditto
//    }
//
//    printf("\n");
//}

#ifdef __cplusplus
}
#endif

#endif //PROJECT1_SYSCALLS_H
