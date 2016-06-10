//
// Created by School on 6/10/16.
//

#ifndef MAIN_LIBRARY_H
#define MAIN_LIBRARY_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

typedef unsigned short color_t;

#define rgb(r, g, b) ((((31*(r+4))/255)<<11) | (((63*(g+2))/255)<<5) | ((31*(b+4))/255))
// #define rgb(r, g, b) (((r >>= 3)<<11) | ((g >>= 2)<<5) | (b >>= 3))

/* some RGB color definitions                                                 */
#define Black           rgb(   0,   0,   0) /*0x0000*/
#define Navy            rgb(   0,   0, 128) /*0x000F*/
#define DarkGreen       rgb(   0, 128,   0) /*0x03E0*/
#define DarkCyan        rgb(   0, 128, 128) /*0x03EF*/
#define Maroon          rgb( 128,   0,   0) /*0x7800*/
#define Purple          rgb( 128,   0, 128) /*0x780F*/
#define Olive           rgb( 128, 128,   0) /*0x7BE0*/
#define LightGrey       rgb( 192, 192, 192) /*0xC618*/
#define DarkGrey        rgb( 128, 128, 128) /*0x7BEF*/
#define Blue            rgb(   0,   0, 255) /*0x001F*/
#define Green           rgb(   0, 255,   0) /*0x07E0*/
#define Cyan            rgb(   0, 255, 255) /*0x07FF*/
#define Red             rgb( 255,   0,   0) /*0xF800*/
#define Magenta         rgb( 255,   0, 255) /*0xF81F*/
#define Yellow          rgb( 255, 255,   0) /*0xFFE0*/
#define White           rgb( 255, 255, 255) /*0xFFFF*/
#define Orange          rgb( 255, 165,   0) /*0xFD20*/
#define GreenYellow     rgb( 173, 255,  47) /*0xAFE5*/

void draw_sample_colors();

void color_whole_screen(color_t color);

void draw_pixel(int x, int y, color_t color);

int get_address_from_x_y(int horizontal, int vertical);

void draw_rect(int x1, int y1, int width, int height, color_t c);

void draw_text(int x, int y, const char *text, color_t c);

void init_graphics();// open, ioctl, mmap

size_t get_frame_buffer_len();

size_t get_horizontal_screen_size();

size_t get_vertical_screen_size();

int open_file_descriptor();

unsigned short *get_frame_buffer();

int write_to_frame_buffer(unsigned short *write_buffer, int num_bytes);

void exit_graphics();// ioctl

void clear_screen();// write

char getkey();// select, read

void sleep_ms(long ms);// nanosleep

struct singleton;

struct singleton *get_instance();

void destruct_instance(struct singleton *pSingleton);

#ifdef __cplusplus
}
#endif

#endif //MAIN_LIBRARY_H
