/* Defined codes for entrances 
   North, south, east, west are when entering from that side of the screen
 */
#ifndef __CODES__H__
#define __CODES__H__

typedef enum ENTRANCE_CODE {
  LOAD_4, 
  LOAD_3, 
  LOAD_2, 
  LOAD_1, 
  NORTH,
  EAST,
  SOUTH,
  WEST,
  PORTAL_1,
  PORTAL_2,
  PORTAL_3,
  MISC_1,
  MISC_2,
  MISC_3,
  MISC_4,
}  ENT_CODE;

/* Defined codes for events acted upon a level

 */
typedef enum EVENT_CODE {
  SAVE,
  GREEN,
  PURPLE,
  ORANGE,
  EYE_1,
  EYE_2,
  EYE_3, 
  COLLECT_1,
  COLLECT_2,
  COLLECT_3,
  COLLECT_4,
  COLLECT_5,
  RED_1,
  RED_2,
  RED_3,
  RED_4,
  RED_5,
  SPEECH,
  END_SPEECH,
  EXTRA,
  PORTALE_1, 
  PORTALE_2,
  PORTALE_3,
  MISCE_1,
  MISCE_2,
  MISCE_3,
  MISCE_4,
  MISCE_5,
  MISCE_6,
  KILL,
  NOTHING
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
  PRE_KICK_HALL,
  WALL_KICK_1,
  WALL_KICK_2,
  WALL_KICK_3,
  BOSS_SPLIT
  
} S_CODE;

typedef enum LEVEL_CODE {
  NONE,
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
  PUMPKIN,
  SECRET_1,
  SECRET_2
} L_CODE;
#endif
