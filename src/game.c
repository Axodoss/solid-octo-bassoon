
INTERNAL void RunGamePause()
{
	// TODO: game pause loop
}

INTERNAL void RunGameLoop()
{
	// TODO: main game loop

	
	//i8 move_x = (GameContext.Input & J_RIGHT) - (GameContext.Input & J_LEFT);
	//i8 move_y = (GameContext.Input & J_DOWN) - (GameContext.Input & J_UP);

	i8 move_x = 0, move_y = 0;
	if (GameContext.Input & J_LEFT) move_x--;
	if (GameContext.Input & J_RIGHT) move_x++;
	if (GameContext.Input & J_UP) move_y--;
	if (GameContext.Input & J_DOWN) move_y++;

	delay(10);

	scroll_sprite(0, move_x, move_y);
}

INTERNAL void EnterGamePause()
{
	// TODO: enter game pause
}

void EnterGameLoop()
{
	// TODO: enter game loop

	set_sprite_data(0, 2, SmileTile);
	set_sprite_tile(0, 0);
	move_sprite(0, 88, 78);
	SHOW_SPRITES;

	GameContext.MainLoop = RunGameLoop;
}