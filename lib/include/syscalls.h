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

unsigned char * read_frame_buffer(size_t buffer_size);

unsigned char * read_frame_buffer_with_offset(size_t buffer_size, off_t offset, off_t pa_offset);

int write_to_frame_buffer(unsigned short *write_buffer, size_t num_bytes);

void exit_graphics();// ioctl

void clear_screen();// write

char getkey();// select, read

void sleep_ms(long ms);// nanosleep

#define rgb(r,g,b) ((((31*(r+4))/255)<<11) | (((63*(g+2))/255)<<5) | ((31*(b+4))/255))

typedef unsigned short color_t;

void draw_pixel(int x, int y, color_t color);

void draw_rect(int x1, int y1, int width, int height, color_t c);

void draw_text(int x, int y, const char *text, color_t c);

#ifdef __cplusplus
}
#endif

#endif //PROJECT1_SYSCALLS_H
