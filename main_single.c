#include <sys/param.h>
#include "library.h"

/**
 * Handle quit to correctly exit and restore state on CTR-C.
 */
void sig_handler(int signo) {

    exit_graphics();

    if (signo == SIGINT) {
        return;
    }
}

int main(int argc, char **argv) {
    signal(SIGINT, sig_handler);

    init_graphics();

    draw_sample_colors();

    draw_rect(20, 20, 100, 40, Orange);

    sleep_ms(1000);

    draw_text(40, 40, "abc", Red);

    draw_text(636, 476, "def", Orange);

    sleep_ms(5000);

    exit_graphics();

    return 1;
}