#include <string.h>
#include <stdlib.h>

#include <tonc.h>

#include "menu_bg.h"

#define N_BUTTON 10

#define BUTTON_A 0
#define BUTTON_B 1
#define BUTTON_SELECT 2
#define BUTTON_START 3
#define BUTTON_RIGHT 4
#define BUTTON_LEFT 5
#define BUTTON_UP 6
#define BUTTON_DOWN 7
#define BUTTON_R 8
#define BUTTON_L 9

#define N_MAIN_OPTIONS 4

void set_background() {
	// Load palette
	memcpy(pal_bg_mem, menu_bgPal, menu_bgPalLen);
	// Load tiles into CBB 0
	memcpy(&tile_mem[1][0], menu_bgTiles, menu_bgTilesLen);
	// Load map into SBB 30
	memcpy(&se_mem[28][0], menu_bgMap, menu_bgMapLen);

	REG_BG2CNT = BG_CBB(1) | BG_SBB(28) | BG_8BPP | BG_REG_64x32;

	// Init BG 0 for text on screen entries.
	tte_init_se_default(0, BG_CBB(0)|BG_SBB(31));
}

volatile unsigned int *BUTTONS = (volatile unsigned int *)0x04000130;

int pressed[N_BUTTON];
void check_buttons_state() {
	for (int i = 0; i < N_BUTTON; i++) {
		pressed[i] = ((*BUTTONS) & (1 << i));
	}
}

bool was_pressed(int button) {
	return pressed[button] && !((*BUTTONS) & (1 << button));
}

void add_option(int idx, char **options, const char *option) {
	options[idx] = malloc(strlen(option));
	strcpy(options[idx], option);
}

int selected[N_MAIN_OPTIONS];

void write_options(int n_options, char **options) {
	int x = 15, y = 35;

	for (int i  = 0; i < n_options; i++, y+=15) {
		char position[20];
		sprintf(position, "#{P:%d,%d}", x, y);

		tte_write(position);

		if (selected[i]) {
			char *selected_option = malloc(sizeof(options[i]) + strlen(" SELEC"));
			strcpy(selected_option, options[i]);
			strcpy(selected_option + strlen(options[i]), " SELEC");
			tte_write(selected_option);
		} else {
			tte_write(options[i]);
		}
	}
}

int main()
{
	REG_DISPCNT = DCNT_MODE0 | DCNT_BG2 | DCNT_BG0;
	set_background();

	memset(pressed, 0, sizeof(pressed));

	char **main_options = malloc(N_MAIN_OPTIONS * sizeof(char *));

	add_option(0, main_options, "NOVA AVENTURA");
	add_option(1, main_options, "CONTINUAR AVENTURA");
	add_option(2, main_options, "OPCOES");
	add_option(3, main_options, "SAIR");

	memset(selected, 0, sizeof(selected));

	int count = 0;
	while(1){
		vid_vsync();
		key_poll();

		tte_erase_screen();

		write_options(N_MAIN_OPTIONS, main_options);
		
		if (was_pressed(BUTTON_DOWN)) {
			selected[count++] = 0;
			count %= N_MAIN_OPTIONS;
		}

		if (was_pressed(BUTTON_UP)) {
			selected[count--] = 0;
			count += N_MAIN_OPTIONS;
			count %= N_MAIN_OPTIONS;
		}

		check_buttons_state();
		selected[count] = 1;
	}

	return 0;
}
