#ifndef __LEVELS__H__
#define __LEVELS__H__

#include "../Level.h"
#include "Secret1.h"
#include "Boss3_2.h"
#include "Boss3_1.h"
#include "Level14.h"
#include "Level13.h"
#include "Level12.h"
#include "Level11.h"
#include "Level10.h"
#include "Boss2.h"
#include "Level9.h"
#include "Level8.h"
#include "Level7.h"
#include "Level6.h"
#include "Level5.h"
#include "Level4.h"
#include "Boss1.h"
#include "Level3.h"
#include "Level2.h"
#include "Level1.h"

Level* loadLevel(You* you, S_CODE save) {
  if (save == GAME_START)
    return makeLevel1(you,100,550,MISC_1);
  else if (save == ROOM_1)
    return makeLevel1(you,0,0,LOAD_1);
  else if (save == ROOM_2) 
    return makeLevel2(you,0,0,LOAD_1);
  else if (save == ROOM_3) 
    return makeLevel3(you,0,0,LOAD_1);
  else if (save == VERT_EASY) 
    return makeLevel3(you,0,0,LOAD_2);
  else if (save == CROSS_ROADS) 
    return makeLevel4(you,0,0,LOAD_1);
  else if (save == SPLIT_EASY)
    return makeLevel4(you,0,0,LOAD_2);
  else if (save == REVERSE_ROOM) 
    return makeLevel6(you,0,0,LOAD_1);
  else if (save == PRE_WALL_KICK) 
    return makeLevel7(you,0,0,LOAD_1);
  else if (save == PRE_KICK_HALL) 
    return makeLevel8(you,0,0,LOAD_1);
  else if (save == WALL_KICK_1) 
    return makeLevel9(you,0,0,LOAD_1);
  else if (save == WALL_KICK_2)
    return makeLevel9(you,0,0,LOAD_2);
  else if (save == WALL_KICK_3)
    return makeLevel9(you,0,0,LOAD_3);
  else if (save == BOTTOM_PIT)
    return makeLevel11(you,0,0,LOAD_1);
  else if (save == THIN_EYE)
    return makeLevel12(you,0,0,LOAD_1);
  else if (save == PRE_BOSS_2)
    return makeLevel14(you,0,0,LOAD_1);
  else
    throw "NO SUCH SAVE!!!";
  return NULL;
}

Level* makeLevel(You* you, Level* level, L_CODE l, ENT_CODE ent) {
  if (l==START) {
    return makeLevel1(you,you->getX1()+level->getX(),you->getY1()+level->getY(),ent);
  }
  else if (l==DIE) {
    return makeLevel2(you,you->getX1()+level->getX(),you->getY1()+level->getY(),ent);
  }
  else if (l==MOVING) {
    return makeLevel3(you,you->getX1()+level->getX(),you->getY1()+level->getY(),ent);
  }
  else if (l==COLOR) {
    return makeBoss1(you,you->getX1()+level->getX(),you->getY1()+level->getY(),ent);
  }
  else if (l==SPLIT) {
    return makeLevel4(you,you->getX1()+level->getX(),you->getY1()+level->getY(),ent);
  }
  else if (l==FOLLOW) {
    return makeLevel5(you,you->getX1()+level->getX(),you->getY1()+level->getY(),ent);
  }
  else if (l==REVERSE) {
    return makeLevel6(you,you->getX1()+level->getX(),you->getY1()+level->getY(),ent);
  }
  else if (l==KICK) {
    return makeLevel7(you,you->getX1()+level->getX(),you->getY1()+level->getY(),ent);
  }
  else if (l==CLIMB) {
    return makeLevel8(you,you->getX1()+level->getX(),you->getY1()+level->getY(),ent);
  }
  else if (l==COLLECTOR) {
    return makeLevel9(you,you->getX1()+level->getX(),you->getY1()+level->getY(),ent);
  }
  else if (l==PUMPKIN) {
    return makeBoss2(you,you->getX1()+level->getX(),you->getY1()+level->getY(),ent);
  }
  else if (l==FALL) {
    return makeLevel10(you,you->getX1()+level->getX(),you->getY1()+level->getY(),ent);
  }
  else if (l==EYE) {
    return makeLevel11(you,you->getX1()+level->getX(),you->getY1()+level->getY(),ent);
  }
  else if (l==RISING_EYE) {
    return makeLevel12(you,you->getX1()+level->getX(),you->getY1()+level->getY(),ent);
  }
  else if (l==PUZZLE) {
    return makeLevel13(you,you->getX1()+level->getX(),you->getY1()+level->getY(),ent);
  }
  else if (l==PREBOSS2) {
    return makeLevel14(you,you->getX1()+level->getX(),you->getY1()+level->getY(),ent);
  }
  else if (l==CLOUD) {
    return makeBoss3_1(you,you->getX1()+level->getX(),you->getY1()+level->getY(),ent);
  }
  else if (l==CLOUD2) {
    return makeBoss3_2(you,you->getX1()+level->getX(),you->getY1()+level->getY(),ent);
  }

  else if (l==SECRET_1) {
    return makeSecret1(you,you->getX1()+level->getX(),you->getY1()+level->getY(),ent);
  }

  return NULL;
}
#endif 
