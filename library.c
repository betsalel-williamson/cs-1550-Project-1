//
// Created by School on 6/10/16.
//

#include <fcntl.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <linux/fb.h>
#include <sys/termios.h>

#include "library.h"
#include "iso_font.h"

void color_whole_screen(color_t color) {

    int h = (int) get_horizontal_screen_size(), v = (int) get_vertical_screen_size();

    int y;
    for (y = 0; y < v; ++y) {
        int x;
        for (x = 0; x < h; ++x) {
            draw_pixel(x, y, color);
        }
    }


    sleep_ms(1500);
}

#define SAMPLE_COLOR_BUFFER_SIZE (int) 640*480

void draw_sample_colors() {

    unsigned short buffer[SAMPLE_COLOR_BUFFER_SIZE] = {};
    int i;
    for (i = 0; i < SAMPLE_COLOR_BUFFER_SIZE; ++i) {
        buffer[i] = Black;
    }
    write_to_frame_buffer(buffer, SAMPLE_COLOR_BUFFER_SIZE);

    for (i = 0; i < SAMPLE_COLOR_BUFFER_SIZE; ++i) {
        buffer[i] = Navy;
    }
    write_to_frame_buffer(buffer, SAMPLE_COLOR_BUFFER_SIZE);

    for (i = 0; i < SAMPLE_COLOR_BUFFER_SIZE; ++i) {
        buffer[i] = DarkGreen;
    }
    write_to_frame_buffer(buffer, SAMPLE_COLOR_BUFFER_SIZE);

    for (i = 0; i < SAMPLE_COLOR_BUFFER_SIZE; ++i) {
        buffer[i] = DarkCyan;
    }
    write_to_frame_buffer(buffer, SAMPLE_COLOR_BUFFER_SIZE);

    for (i = 0; i < SAMPLE_COLOR_BUFFER_SIZE; ++i) {
        buffer[i] = Maroon;
    }
    write_to_frame_buffer(buffer, SAMPLE_COLOR_BUFFER_SIZE);

    for (i = 0; i < SAMPLE_COLOR_BUFFER_SIZE; ++i) {
        buffer[i] = Purple;
    }
    write_to_frame_buffer(buffer, SAMPLE_COLOR_BUFFER_SIZE);

    for (i = 0; i < SAMPLE_COLOR_BUFFER_SIZE; ++i) {
        buffer[i] = Olive;
    }
    write_to_frame_buffer(buffer, SAMPLE_COLOR_BUFFER_SIZE);

    for (i = 0; i < SAMPLE_COLOR_BUFFER_SIZE; ++i) {
        buffer[i] = LightGrey;
    }
    write_to_frame_buffer(buffer, SAMPLE_COLOR_BUFFER_SIZE);

    for (i = 0; i < SAMPLE_COLOR_BUFFER_SIZE; ++i) {
        buffer[i] = DarkGrey;
    }
    write_to_frame_buffer(buffer, SAMPLE_COLOR_BUFFER_SIZE);

    for (i = 0; i < SAMPLE_COLOR_BUFFER_SIZE; ++i) {
        buffer[i] = Blue;
    }
    write_to_frame_buffer(buffer, SAMPLE_COLOR_BUFFER_SIZE);

    for (i = 0; i < SAMPLE_COLOR_BUFFER_SIZE; ++i) {
        buffer[i] = Green;
    }
    write_to_frame_buffer(buffer, SAMPLE_COLOR_BUFFER_SIZE);

    for (i = 0; i < SAMPLE_COLOR_BUFFER_SIZE; ++i) {
        buffer[i] = Cyan;
    }
    write_to_frame_buffer(buffer, SAMPLE_COLOR_BUFFER_SIZE);

    for (i = 0; i < SAMPLE_COLOR_BUFFER_SIZE; ++i) {
        buffer[i] = Red;
    }
    write_to_frame_buffer(buffer, SAMPLE_COLOR_BUFFER_SIZE);

    for (i = 0; i < SAMPLE_COLOR_BUFFER_SIZE; ++i) {
        buffer[i] = Magenta;
    }
    write_to_frame_buffer(buffer, SAMPLE_COLOR_BUFFER_SIZE);

    for (i = 0; i < SAMPLE_COLOR_BUFFER_SIZE; ++i) {
        buffer[i] = Yellow;
    }
    write_to_frame_buffer(buffer, SAMPLE_COLOR_BUFFER_SIZE);

    for (i = 0; i < SAMPLE_COLOR_BUFFER_SIZE; ++i) {
        buffer[i] = White;
    }
    write_to_frame_buffer(buffer, SAMPLE_COLOR_BUFFER_SIZE);

    for (i = 0; i < SAMPLE_COLOR_BUFFER_SIZE; ++i) {
        buffer[i] = Orange;
    }
    write_to_frame_buffer(buffer, SAMPLE_COLOR_BUFFER_SIZE);

    for (i = 0; i < SAMPLE_COLOR_BUFFER_SIZE; ++i) {
        buffer[i] = GreenYellow;
    }
    write_to_frame_buffer(buffer, SAMPLE_COLOR_BUFFER_SIZE);
}

void draw_pixel(int x, int y, color_t color) {
    unsigned short *fb = get_frame_buffer();

    int address = get_address_from_x_y(x, y);

    fb[address] = color;
}

int get_address_from_x_y(int horizontal, int vertical) {
    // using index logic.
    // convert to counting logic
    horizontal += 1;
    vertical += 1;

    if (horizontal > get_horizontal_screen_size()) {
//        return -1;
        return 0;
    }

    if (vertical > get_vertical_screen_size()) {
//        return -1;
        return 0;
    }

    int address = 0;

    address += horizontal;

    address += (vertical - 1) * get_horizontal_screen_size();

    // revert to index logic
    address -= 1;

    return address;
}

void draw_rect(int x1, int y1, int width, int height, color_t c) {
    unsigned short *fb = get_frame_buffer();

    int address = get_address_from_x_y(x1, y1);
    int temp_address = address;

    int i;
    for (i = 0; i < height; ++i) {

        int j;

        for (j = 0; j < width; ++j) {

            fb[temp_address++] = c;

        }

        temp_address = (int) (address + (i * get_horizontal_screen_size()));
    }
}

void increment_x_y(int *x, int *y) {
    int my_x = *x;
    int my_y = *y;

    int go_to_next_row = 0;
    if (my_x + 8 > get_horizontal_screen_size()) {
        go_to_next_row = 1;
    }

    int go_to_next_col = 0;
    if (my_y + 16 > get_vertical_screen_size()) {
        go_to_next_col = 1;
    }

    if (go_to_next_row) {
        *x = 0;
    } else {
        *x += 8;
    }

    if (go_to_next_col) {
        *y = 0;
    }
}

void draw_text(int x, int y, const char *text, color_t c) {
    unsigned short *fb = get_frame_buffer();
    if (x + 8 > get_horizontal_screen_size()) {
//        return -1;
        x = 0;

        draw_text(0, (int) (get_vertical_screen_size() - 32), "error; x text out of bounds", Red);
    }

    if (y + 16 > get_vertical_screen_size()) {
//        return -1;
        y = 0;

        draw_text(0, (int) (get_vertical_screen_size() - 16), "error; y text out of bounds", Red);
    }

    int width = 8;
    int height = 16;
    int address = get_address_from_x_y(x, y);
    int temp_address = address;

    int i;
    for (i = 0; text[i] != '\0'; ++i, increment_x_y(&x, &y), address = get_address_from_x_y(x, y)) {
        int letter = text[i];

        int j;
        for (j = 0; j < height; ++j) {
            char byte = iso_font[letter * 16 + j];

            int k;
            for (k = 0; k < width; ++k, ++temp_address) {

                if (byte & (1 << k)) {
                    fb[temp_address] = c;
                }
            }

            temp_address = (int) (address + (j * get_horizontal_screen_size()));
        }
    }
}

struct singleton {
    char sharedData[256];
    unsigned short *frame_buffer;
    void *addr;
    size_t len;
    int prot;
    int flags;
    int fildes;
    off_t off;
    size_t horizontal;
    size_t vertical;
};

struct termio original_termio;

#define FRAME_BUFFER_FILE_DESCRIPTOR "/dev/fb0"

struct singleton *get_instance() {
    static struct singleton *instance = NULL;

    if (instance == NULL) {

        // get map for struct
        instance = mmap(NULL, sizeof(struct singleton), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, 0, 0);

        instance->fildes = open(FRAME_BUFFER_FILE_DESCRIPTOR, O_RDWR);//| O_WRONLY | O_APPEND
        instance->prot = PROT_READ | PROT_WRITE;
        instance->flags = MAP_SHARED;

        // get horizontal and vertical
        struct fb_fix_screeninfo fixed_info;
        struct fb_var_screeninfo screen_info;

        if (!ioctl(instance->fildes, FBIOGET_FSCREENINFO, &fixed_info)) {
            instance->horizontal = (fixed_info.line_length / 2);
        }

        if (!ioctl(instance->fildes, FBIOGET_VSCREENINFO, &screen_info)) {
            instance->vertical = screen_info.yres_virtual;
        }

        instance->len = instance->horizontal * instance->vertical * 2;

        instance->frame_buffer = (unsigned short *) mmap(NULL, instance->len,
                                                         instance->prot,
                                                         instance->flags, instance->fildes, 0);

    }

    return instance;
}


void destruct_instance(struct singleton *pSingleton) {

    if (close(pSingleton->fildes) != 0) {
        // error
    }
    // unmap memory
}

void init_graphics() {
    //Settings for stdin (source: svgalib):
    int fd = 0;
    struct termio zap;
    ioctl(fd, TCGETA, &original_termio);
    zap = original_termio;
    zap.c_cc[VMIN] = 0;
    zap.c_cc[VTIME] = 0;
    zap.c_lflag = 0;
    ioctl(fd, TCSETA, &zap);
//    clear_screen();
    color_whole_screen(White);

}

size_t get_frame_buffer_len() {
    struct singleton *instance = get_instance();
    return instance->len;
}

size_t get_horizontal_screen_size() {
    struct singleton *instance = get_instance();
    return instance->horizontal;
}

size_t get_vertical_screen_size() {
    struct singleton *instance = get_instance();
    return instance->vertical;
}

void exit_graphics() {
    //Restore original stdin
    int fd = 0;
    ioctl(fd, TCSETA, &original_termio);

    clear_screen();
    struct singleton *instance = get_instance();
    destruct_instance(instance);
}


int open_file_descriptor() {
    struct singleton *instance = get_instance();
    return instance->fildes;
}

#define MS_TO_SLEEP 500

int write_to_frame_buffer(unsigned short *write_buffer, int num_bytes) {

    unsigned short *fb = get_frame_buffer();

    int i;
    for (i = 0; i < num_bytes; ++i) {
        fb[i] = write_buffer[i];
    }

    sleep_ms(MS_TO_SLEEP);

    return i;
}

unsigned short *get_frame_buffer() {
    struct singleton *instance = get_instance();
    return instance->frame_buffer;
}

// implementation from http://cc.byexamples.com/2007/05/25/nanosleep-is-better-than-sleep-and-usleep/
void sleep_ms(long ms) {
    struct timespec request = {0};

    time_t sec = (int) (ms / 1000);
    ms = ms - (sec * 1000);

    request.tv_sec = sec;
    request.tv_nsec = ms * 1000000L;

    while (nanosleep(&request, &request) == -1 && errno == EINTR)
        continue;
}

void clear_screen() {
    const char msg[] = "\033[2J";
    syscall(4, STDOUT_FILENO, msg, sizeof(msg) - 1);
}


char getkey() {
    int fd = 0;

    char c = '\0';
    int e = (int) read(fd, &c, 1);
    if (e == 0) c = '\0';

    return c;
};
