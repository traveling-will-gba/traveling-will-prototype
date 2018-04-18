#include <string.h>

#include "toolbox.h"
#include "input.h"
#include "menu_bg.h"

int main()
{
	// Load palette
	memcpy(pal_bg_mem, menu_bgPal, menu_bgPalLen);
	// Load tiles into CBB 0
	memcpy(&tile_mem[0][0], menu_bgTiles, menu_bgTilesLen);
	// Load map into SBB 30
	memcpy(&se_mem[30][0], menu_bgMap, menu_bgMapLen);

	// set up BG0 for a 8bpp 64x32t map, using
	//   using charblock 0 and screenblock 31
	REG_BG0CNT= BG_CBB(0) | BG_SBB(30) | BG_8BPP | BG_REG_64x32;
	REG_DISPCNT= DCNT_MODE0 | DCNT_BG0;

	// Scroll around some
	REG_BG0HOFS = 0;
	REG_BG0VOFS = 0;

	while(1)
	{
		vid_vsync();
		key_poll();
	}

	return 0;
}
