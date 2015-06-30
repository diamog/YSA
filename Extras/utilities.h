#ifndef __UTILITIES__H__
#define __UTILITIES__H__

#include "../Actor.h"
#include "../Mover.h"
#include "Line.h"
#include <iostream>
#include <vector>

bool isRectangularHit(Actor* a1,Actor* a2);

bool isLineHit(Line l1, Line l2);

bool testLines(Actor* a1,Actor* a2);

int getApproachDirection(Actor* a1, Actor* a2);

void getObjectCenter(Actor* a,float& cx,float& cy);

#endif
