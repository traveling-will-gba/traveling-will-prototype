#ifndef BUTTON_HANDLER_H
#define BUTTON_HANDLER_H

#define BUTTON_A 1
#define BUTTON_B 2
#define BUTTON_SELECT 4
#define BUTTON_START 8
#define BUTTON_RIGHT 16
#define BUTTON_LEFT 32
#define BUTTON_UP 64
#define BUTTON_DOWN 128
#define BUTTON_R 256
#define BUTTON_L 512

volatile unsigned int *BUTTONS = (volatile unsigned int *)0x04000130;
int buttons[10];

void check_buttons_states()
{
    buttons[0] = !((*BUTTONS) & BUTTON_A);
    buttons[1] = !((*BUTTONS) & BUTTON_B);
    buttons[2] = !((*BUTTONS) & BUTTON_SELECT);
    buttons[3] = !((*BUTTONS) & BUTTON_START);
    buttons[4] = !((*BUTTONS) & BUTTON_RIGHT);
    buttons[5] = !((*BUTTONS) & BUTTON_LEFT);
    buttons[6] = !((*BUTTONS) & BUTTON_UP);
    buttons[7] = !((*BUTTONS) & BUTTON_DOWN);
    buttons[8] = !((*BUTTONS) & BUTTON_R);
    buttons[9] = !((*BUTTONS) & BUTTON_L);
}

int button_pressed(int button) {
    switch(button) {
        case BUTTON_A: return buttons[0];
        case BUTTON_B: return buttons[1];
        case BUTTON_SELECT: return buttons[2];
        case BUTTON_START: return buttons[3];
        case BUTTON_RIGHT: return buttons[4];
        case BUTTON_LEFT: return buttons[5];
        case BUTTON_UP: return buttons[6];
        case BUTTON_DOWN: return buttons[7];
        case BUTTON_R: return buttons[8];
        case BUTTON_L: return buttons[9];
    }

    return 0;
}

#endif