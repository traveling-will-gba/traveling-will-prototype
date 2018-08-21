
//{{BLOCK(menu_bg)

//======================================================================
//
//	menu_bg, 256x256@8, 
//	+ palette 256 entries, not compressed
//	+ 340 tiles (t|f reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x32 
//	Total size: 512 + 21760 + 2048 = 24320
//
//	Time-stamp: 2018-08-21, 19:53:54
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.15
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_MENU_BG_H
#define GRIT_MENU_BG_H

#define menu_bgTilesLen 21760
extern const unsigned int menu_bgTiles[5440];

#define menu_bgMapLen 2048
extern const unsigned short menu_bgMap[1024];

#define menu_bgPalLen 512
extern const unsigned short menu_bgPal[256];

#endif // GRIT_MENU_BG_H

//}}BLOCK(menu_bg)
