/* Defined codes for entrances 
   North, south, east, west are when entering from that side of the screen
 */
#ifndef __CODES__H__
#define __CODES__H__

typedef enum DIFFICULTY_CODE {
  EASY,
  MEDIUM,
  HARD,
  IMPOSSIBLE
} DIFF_CODE;

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
  MISC_4
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
  END_HINT,
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
  GAME_START,      //IMPOSSIBLE
  ROOM_1,          //MEDIUM
  ROOM_2,          //MEDIUM
  ROOM_3,          //HARD
  CROSS_ROADS,     //HARD
  BOTTOM_PIT,      //MEDIUM
  THIN_EYE,        //MEDIUM
  PRE_BOSS_2,      //HARD
  REVERSE_ROOM,    //MEDIUM
  PRE_WALL_KICK,   //HARD
  PRE_KICK_HALL,   //MEDIUM
  WALL_KICK_1,     //MEDIUM
  WALL_KICK_2,     //MEDIUM
  WALL_KICK_3,     //HARD
  VERT_EASY,       //EASY
  SPLIT_EASY,      //EASY
  WALL_EASY,       //EASY
  COLLECT_EASY,    //EASY
  FALL_EASY,       //EASY
  EYE_EASY,        //EASY
  PUZZLE_EASY,     //EASY
  TOWER_START,     //HARD
  TOWER_EASY,      //EASY
  TOWER_MIDDLE,    //MEDIUM
  TOWER_EASY2,     //EASY
  TOWER_TOP,       //HARD
  CHALLENGE_1,     //HARD
  DARK_1,          //HARD
  PRE_COLOR_2,     //HARD
  KICK_1,          //HARD
  BACKGROUND_1,    //HARD
  PRE_FINAL,       //HARD
  NOT_SAVE         //Achievement
  
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
  CLOUD2,
  FOLLOW,
  REVERSE,
  KICK,
  CLIMB,
  COLLECTOR,
  PUMPKIN,
  SECRET_1,
  SECRET_2,
  ELEVATOR,
  TOWEREND,
  FINALROOM
} L_CODE;

typedef enum ACHIEVEMENT_CODES {
  //General 
  START_ACHIEVE,
  SAVE_1, //save the game
  DIE_1, //die 1 time
  DIE_10, //die 10 times
  DIE_50, //die 50 times
  DIE_100,  //die 100 times
  DIE_300, //die 300 times
  DIE_500, //die 500 times
  DIE_999, //die 999 times
  DIE_1000, //die 1000 times
  KILL_1, //Kill an enemy
  KILL_EVERY, //Kill each type of enemy at least once
  NO_HINTS, //Dont grab a single hint
  NO_SAVE, //Dont save up to boss1
  EVIL_SAVE, //Have the reverser hit the save point
  LOOP_EYE, //Have the eye in an infinite loop 
  GET_SECRET_1, //get first secret
  GET_SECRET_2, //get second secret
  //Difficulties
  BEAT_EASY, //beat easy mode
  BEAT_MEDIUM, //beat medium mode
  BEAT_HARD, //beat hard mode
  BEAT_IMPOSSIBLE, //beat impossible mode you crazy lunatic
  //Extras
  EXTRA_1, //collect 1 extra
  EXTRA_5, //collect 5 extras
  EXTRA_10, //collect 10 extras
  EXTRA_20, //collect 20 extras
  EXTRA_ALL, //collect all the extras
  //Color Boss 1
  BEAT_COLOR, //beat the color boss
  HARD_COLOR, //beat the color boss on hard
  TIME_COLOR, //beat the color boss in a certain time
  OCD, //beat the color boss by depleting one color at a time
  //Cloud Boss
  BEAT_CLOUD,
  HARD_CLOUD,
  TIME_CLOUD,
  PERFECT_CLOUD, //beat the first phase of the cloud without ever missing the small eye
  //Pumpkin Boss
  BEAT_HEADS,
  TIME_HEADS,
  MURDER_HEADS, //remove 5 or more stems in one hit on the heads
  BEAT_PUMPKIN,
  HARD_PUMPKIN,
  END_ACHIEVEMENTS,
  //Cat Virus
  BEAT_CAT,
  HARD_CAT,
  TIME_CAT,
  //Fire Wall
  BEAT_WALL,
  HARD_WALL,
  TIME_WALL,
  //Color Boss 2
  BEAT_COLOR2,
  HARD_COLOR2,
  TIME_COLOR2,
  NO_HANDICAP_COLOR2,
  //Final Head Boss
  BEAT_HEAD,
  HARD_HEAD,
  TIME_HEAD,
  //END_ACHIEVEMENTS,

  //Boss Rush
  BEAT_ALL,
  BEAT_ALL_HARD,
  TIME_ALL,
  //Hell Mode
  HELL_EASY,
  HELL_MEDIUM,
  HELL_HARD,
  HELL_IMPOSSIBLE,
  //Hall of memories
  EASY_HALL,
  MEDIUM_HALL,
  HARD_HALL,
  IMPOSSIBLE_HALL,
  //END_ACHIEVEMENTS
} A_CODE;
#endif
