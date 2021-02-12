#include <gb/gb.h>

#include "types.h"

// 8x8
unsigned char SmileTile[] =
{
  0x7E,0x7E,0x81,0xFF,0xA5,0xFF,0x81,0xFF,
  0x81,0xFF,0xBD,0xFF,0x81,0xFF,0x7E,0x7E
};

void main()
{
	//DISPLAY_ON;

	set_sprite_data(0, 2, SmileTile);
	set_sprite_tile(0, 0);
	move_sprite(0, 88, 78);
	SHOW_SPRITES;


	while (1)
	{
		delay(1000);
		scroll_sprite(0, 10, 0);
	}
}