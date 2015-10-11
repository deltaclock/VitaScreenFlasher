#include <psp2/ctrl.h>
#include <psp2/kernel/processmgr.h>
#include <vita2d.h>

#define EXIT_COMBO (PSP2_CTRL_START | PSP2_CTRL_SELECT)

#define RED     RGBA8(255,   0,   0, 255)
#define GREEN   RGBA8(  0, 255,   0, 255)
#define BLUE    RGBA8(  0,   0, 255, 255)
#define YELLOW  RGBA8(255, 255,   0, 255)

int main()
{
    vita2d_init();

    SceCtrlData pad;

    while(1) {
        sceCtrlPeekBufferPositive(0, &pad, 1);

        if (pad.buttons == EXIT_COMBO) {
            break;
        }

        vita2d_start_drawing();
        vita2d_clear_screen();
        vita2d_draw_rectangle(0, 0, 960, 544, RED);
        vita2d_end_drawing();
        vita2d_swap_buffers();

        vita2d_start_drawing();
        vita2d_clear_screen();
        vita2d_draw_rectangle(0, 0, 960, 544, GREEN);
        vita2d_end_drawing();
        vita2d_swap_buffers();

        vita2d_start_drawing();
        vita2d_clear_screen();
        vita2d_draw_rectangle(0, 0, 960, 544, BLUE);
        vita2d_end_drawing();
        vita2d_swap_buffers();

        vita2d_start_drawing();
        vita2d_clear_screen();
        vita2d_draw_rectangle(0, 0, 960, 544, YELLOW);
        vita2d_end_drawing();
        vita2d_swap_buffers();
    }

    vita2d_fini();

    return 0;
}
