/* Defined codes for entrances 
   North, south, east, west are when entering from that side of the screen
 */
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
  SAVE_4 = -4,
  SAVE_3 = -3,
  SAVE_2 = -2,
  SAVE_1 = -1,
  GREEN = 0,
  PURPLE = 1,
  ORANGE = 2,
  EYE_1 = 3,
  EYE_2 = 4,
  EYE_3 = 5,
  COLLECT_1 = 6,
  COLLECT_2 = 7,
  COLLECT_3 = 8,
  COLLECT_4 = 9,
  COLLECT_5 = 10,
  RED_1 = 11,
  RED_2 = 12,
  RED_3 = 13,
  RED_4 = 14,
  RED_5 = 15,
  SPEECH_1 = 16,
  SPEECH_2 = 17,
  SPEECH_3 = 18,
  SPEECH_4 = 19,
  MISCE_1 = 20,
  MISCE_2 = 21,
  MISCE_3 = 22,
  MISCE_4 = 23,
  MISCE_5 = 24
} EVE_CODE;
