#ifndef __LEVELS__H__
#define __LEVELS__H__

#include "Level.h"
#include "Level1.h"

Level* loadLevels(You* you, S_CODE save) {
  if (save == GAME_START)
    return makeLevel1(you,0,0,MISC_1);
  else if (save == ROOM_1)
    return makeLevel1(you,0,0,LOAD_1);
  else if (save == ROOM_2) ;
  else if (save == ROOM_3) ;
}

#endif 
