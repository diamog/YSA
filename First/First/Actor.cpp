#include "stdafx.h"
#include "Actor.h"

Actor::Actor() {
	x=y=width=height=0;
}
Actor::Actor(float x_,float y_,float w,float h) {
	x = x_;
	y = y_;
	width = w;
	height = h;
}