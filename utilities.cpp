#include "stdafx.h"
#include "utilities.h"


bool isRectangularHit(Actor* a1,Actor* a2) {
  return	a1->getX1()<a2->getX2() && 
    a1->getX2()>a2->getX1() &&
    a1->getY1()<a2->getY2() && 
    a1->getY2()>a2->getY1();
}

int getApproachDirection(Mover* a1, Actor* a2) {
  if (a1->getLastY2()<a2->getY1() && a1->getY2()>a2->getY1()) //Landing
    return 2;
	
  if (a1->getLastY1()>a2->getY2() && a1->getY1()<a2->getY2()) //Ceiling
    return 0;
  if (a1->getX2() > a2->getX1() && a1->getX1()< a2->getX1()) //Right wall
    return 1;
  if (a1->getX1() < a2->getX2() && a1->getX2()>a2->getX2()) //Left wall
    return 3;
  return -1;
}
