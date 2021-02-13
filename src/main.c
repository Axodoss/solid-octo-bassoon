#include <gb/gb.h>

#include "types.h"

#include "assets.c"
#include "ending.c"
#include "game.c"
#include "intro.c"
#include "splash.c"

INTERNAL void Reset()
{
	GameContext.MainLoop = EnterSplash;
	GameContext.Input = GameContext.LastInput = joypad();

	// TODO: entity, player, etc.
}

void main()
{
	Reset();

	while (1)
	{
		GameContext.LastInput = GameContext.Input;
		GameContext.Input = joypad();

		GameContext.MainLoop();
	}
}