
#ifndef __TYPES_H
#define __TYPES_H

#define MAX_ENTITIES 32
#define MAX_PARTICLES 16

#define UPGRADE_WEAPON1 0
#define UPGRADE_WEAPON2 1
#define UPGRADE_WEAPON3 2
#define UPGRADE_WEAPON4 4
#define UPGRADE_SHIELD 8
#define UPGRADE_RES1 16
#define UPGRADE_RES2 32

#define INTERNAL static inline

typedef INT8 i8;
typedef INT16 i16;

typedef UINT8 u8;
typedef UINT16 u16;

typedef void (*EmptyCallback)();

// static entity information
typedef struct
{
	u16 Health;
	// TODO: sprite + animation
	// TODO: behaviour
} entity_definition_t;

// enemy, powerup, trigger
typedef struct
{
	u8 Type;
	u16 Health;
	i16 Position[2];
} entity_t;

// bullet, debry, explosion
typedef struct
{
	u8 Type;
	i16 Position[2];

	// velocity, behaviour, damage
} particle_t;

// our hero
typedef struct
{
	u8 Health;

	i16 Position[2];
	i16 Velocity[2];
	i16 Acceleration[2];

	u8 FireDisabled; // weapon fire counter, 0 = player can fire the weapon

	u16 Upgrades;
	u16 State; // airborn, ...
} player_t;

// all the global values in the game in a single object
typedef struct
{
	EmptyCallback UpdateFunction;

	u8 Input;
	u8 LastInput;

	entity_t Entities[MAX_ENTITIES];
	u8 NumberOfEntities;

	particle_t Particles[MAX_PARTICLES];
	u8 NumberOfParticles;

	player_t Player;

	u16 StateVariable; // used by splash, main menu, intro and ending to determine the animation state, etc.

} game_context_t;

static game_context_t GameContext;

void EnterSplash();
void EnterMainMenu();
void EnterIntro();
void EnterGameLoop();
void EnterEnding();

#endif