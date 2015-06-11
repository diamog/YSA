#include "stdafx.h"
#include "Mover.h"


Mover::Mover() : Actor() {
	lastx=lasty=0;
}

Mover::Mover(float x_,float y_,float w,float h) : Actor(x_,y_,w,h) {
	lastx=lasty=0;
}

void Mover::act() {
	lastx = x;
	lasty = y;
}
