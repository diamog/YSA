#ifndef __UTILITIES__H__
#define __UTILITIES__H__

#include "../Actor.h"
#include "../Mover.h"
#include <iostream>

bool isRectangularHit(Actor* a1,Actor* a2);

int getApproachDirection(Actor* a1, Actor* a2);

void getObjectCenter(Actor* a,float& cx,float& cy);

#endif
