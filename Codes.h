/* Defined codes for entrances 
   North, south, east, west are when entering from that side of the screen
 */
#ifndef __CODES__H__
#define __CODES__H__

typedef enum ENTRANCE_CODE {
  LOAD_4 = -4,
  LOAD_3 = -3,
  LOAD_2 = -2,
  LOAD_1 = -1,
  NORTH = 0,
  EAST = 1,
  SOUTH = 2,
  WEST = 3,
  PORTAL_1 = 4,
  PORTAL_2 = 5,
  PORTAL_3 = 6,
  MISC_1 = 7,
  MISC_2 = 8,
  MISC_3 = 9,
  MISC_4 = 10
}  ENT_CODE;

/* Defined codes for events acted upon a level

 */
typedef enum EVENT_CODE {
  SAVE = -1,
  GREEN = 0,
  PURPLE = 1,
  ORANGE = 2,
  EYE_1 = 3,
  EYE_2 = 4,
  EYE_3 = 5,
  COLLECT = 6,
  RED_1,
  RED_2,
  RED_3,
  RED_4,
  RED_5,
  SPEECH,
  MISCE_1,
  MISCE_2,
  MISCE_3,
  MISCE_4,
  MISCE_5
} EVE_CODE;

typedef enum SAVE_CODE {
  GAME_START,
  ROOM_1,
  ROOM_2,
  ROOM_3,
  CROSS_ROADS,
  BOTTOM_PIT,
  THIN_EYE,
  PRE_BOSS_2,
  REVERSE_ROOM,
  PRE_WALL_KICK,
  WALL_KICK_1,
  WALL_KICK_2,
  WALL_KICK_3,
  BOSS_SPLIT,
  
} S_CODE;

typedef enum LEVEL_CODE {
	START,
	DIE,
	MOVING,
	COLOR,
	SPLIT,
	FALL,
	EYE,
	RISING_EYE,
	PUZZLE,
	PREBOSS2,
	CLOUD,
	FOLLOW,
	REVERSE,
	KICK,
	CLIMB,
	COLLECTOR,
	PUMPKIN
} L_CODE;
#endif
