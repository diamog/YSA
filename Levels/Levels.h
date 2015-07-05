#ifndef __LEVELS__H__
#define __LEVELS__H__

#include "../Level.h"
#include "Level6.h"
#include "Level5.h"
#include "Level4.h"
#include "Boss1.h"
#include "Level3.h"
#include "Level2.h"
#include "Level1.h"

Level* loadLevel(You* you, S_CODE save) {
  if (save == GAME_START)
    return makeLevel1(you,100,500,MISC_1);
  else if (save == ROOM_1)
    return makeLevel1(you,0,0,LOAD_1);
  else if (save == ROOM_2) 
    return makeLevel2(you,0,0,LOAD_1);
  else if (save == ROOM_3) 
    return makeLevel3(you,0,0,LOAD_1);
  else if (save == CROSS_ROADS) 
    return makeLevel4(you,0,0,LOAD_1);
  else if (save == REVERSE_ROOM) 
    return makeLevel6(you,0,0,LOAD_1);
  else
    throw "NO SUCH LEVEL!!!";
  return NULL;
}

Level* makeLevel(You* you, L_CODE l, ENT_CODE ent) {
  if (l==START) {
    return makeLevel1(you,you->getX1(),you->getY1(),ent);
  }
  else if (l==DIE) {
    return makeLevel2(you,you->getX1(),you->getY1(),ent);
  }
  else if (l==MOVING) {
    return makeLevel3(you,you->getX1(),you->getY1(),ent);
  }
  else if (l==COLOR) {
    return makeBoss1(you,you->getX1(),you->getY1(),ent);
  }
  else if (l==SPLIT) {
    return makeLevel4(you,you->getX1(),you->getY1(),ent);
  }
  else if (l==FOLLOW) {
    return makeLevel5(you,you->getX1(),you->getY1(),ent);
  }
  else if (l==REVERSE) {
    return makeLevel6(you,you->getX1(),you->getY1(),ent);
  }

  return NULL;
}
#endif 
