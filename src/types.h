
#ifndef __TYPES_H
#define __TYPES_H

#define MAX_ENTITY 16

#define INTERNAL static inline

typedef char i8;
typedef short i16;

typedef unsigned char u8;
typedef unsigned short u16;

typedef void (*EmptyCallback)();

typedef struct
{
	i16 Health;

	i16 Position[2];
	i16 Velocity[2];
	i16 Acceleration[2];

	// size, collision callback, sprite, etc.

} entity_t;

typedef struct
{
	u8 EntityId;

} player_t;

typedef struct
{
	EmptyCallback MainLoop;

	UINT8 Input;
	UINT8 LastInput;

	entity_t Entities[MAX_ENTITY];
	u8 NumberOfEntities;

	player_t Player;

} game_context_t;

static game_context_t GameContext;

void EnterSplash();
void EnterMainMenu();
void EnterIntro();
void EnterGameLoop();
void EnterEnding();

#endif