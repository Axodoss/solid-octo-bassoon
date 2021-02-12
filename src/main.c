#include <gb/gb.h>

#include "types.h"

const unsigned char SmileTile[] =
{
  0x7E,0x7E,0xFF,0x81,0xFF,0xA5,0xFF,0x81,
  0xFF,0x81,0xFF,0xBD,0xFF,0x81,0x7E,0x7E
};

void main()
{
	set_sprite_data(0, 2, SmileTile);
	set_sprite_tile(0, 0);
	move_sprite(0, 88, 78);
	SHOW_SPRITES;

	while (1)
	{
		UINT8 input = joypad();

		//i8 move_x = (input & J_RIGHT) - (input & J_LEFT);
		//i8 move_y = (input & J_DOWN) - (input & J_UP);

		i8 move_x = 0, move_y = 0;
		if (input & J_LEFT) move_x--;
		if (input & J_RIGHT) move_x++;
		if (input & J_UP) move_y--;
		if (input & J_DOWN) move_y++;

		delay(10);

		scroll_sprite(0, move_x, move_y);
	}
}