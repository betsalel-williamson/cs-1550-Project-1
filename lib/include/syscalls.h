//
// Created by School on 6/4/16.
//

#ifndef PROJECT1_SYSCALLS_H
#define PROJECT1_SYSCALLS_H

#ifdef __cplusplus
extern "C" {
#endif

void init_graphics();// open, ioctl, mmap

int get_screen_size();

int open_frame_buffer(int);

unsigned char *read_frame_buffer(size_t buffer_size);

unsigned char *read_frame_buffer_with_offset(size_t buffer_size, off_t offset, off_t pa_offset);

int write_to_frame_buffer(unsigned short *write_buffer, size_t num_bytes);

void exit_graphics();// ioctl

void clear_screen();// write

char getkey();// select, read

void sleep_ms(long ms);// nanosleep

#ifdef __cplusplus
}
#endif

#endif //PROJECT1_SYSCALLS_H
