//
// Created by School on 6/4/16.
//

#ifndef PROJECT1_SYSCALLS_H
#define PROJECT1_SYSCALLS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/types.h>

void init_graphics();// open, ioctl, mmap

size_t get_screen_size();
size_t get_horizontal_screen_size();
size_t get_vertical_screen_size();


int open_frame_buffer(int);

unsigned short * get_frame_buffer();

unsigned short * read_frame_buffer(size_t buffer_size);

unsigned short * read_frame_buffer_with_offset(size_t buffer_size, off_t offset, off_t pa_offset);

int write_to_frame_buffer(unsigned short *write_buffer, int num_bytes);

void exit_graphics();// ioctl

void clear_screen();// write

char getkey();// select, read

void sleep_ms(long ms);// nanosleep

struct singleton;

struct singleton* get_instance();

#ifdef __cplusplus
}
#endif

#endif //PROJECT1_SYSCALLS_H
