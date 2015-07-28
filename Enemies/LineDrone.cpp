#include "stdafx.h"
#include "LineDrone.h"
#include "../Extras/utilities.h"
#include <cmath>
LineDrone::LineDrone() : Actor(),Drone() {}

LineDrone::LineDrone(Level* l, float x_,float y_, You* yo, int d) 
  : Actor(l,x_,y_,35,35), Drone(l,x_,y_,yo,d) {}


void LineDrone::hitDetector(int adir) {
  dir*=-1;
}
