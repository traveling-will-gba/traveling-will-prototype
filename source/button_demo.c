#ifndef BUTTON_HANDLER_H
#define BUTTON_HANDLER_H

#define REG_DISPCNT *(unsigned long *)0x4000000
#define MODE_3 0x3
#define BG2_ENABLE 0x400

#define set_mode(mode) REG_DISPCNT = (mode)

#define BLUE 0x0000FF

unsigned short *vid_mem = (unsigned short *)0x6000000;

int main()
{
    int x, y;
    unsigned short color;
    set_mode(MODE_3 | BG2_ENABLE);

    while (1)
    {
        check_buttons_states();

        for(int i=0;i<=9;i++){
            if (button_pressed(1 << i)) {
                vid_mem[50 * 240 + i * 10] = BLUE;
            } else {
                vid_mem[50 * 240 + i * 10] = 0;
            }
        }
    }

    return 0;
}

#endif