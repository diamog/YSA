#include "stdafx.h"

#include "Switch.h"
#include "../Extras/utilities.h"
#include "../Level.h"
#include "../Enemies/Reverser.h"
Switch::Switch() : Actor(){
  you = NULL;
}

Switch::Switch(Level* l, float x_, float y_, float w, float h, You* yo) : 
  Actor(l,x_,y_,w,h) {
  you = yo;
}

void Switch::act() {
  if (you->getDead())
    return;
  if (isRectangularHit(you,this)) {
    activate();
    level->sendEvent(eve,this);
  }
  if (rev!=NULL) {
    if (isRectangularHit(rev,this)) {
      if (eve==SAVE)
	buildAchievement(EVIL_SAVE);
      else {
	activate();
	level->sendEvent(eve,this);
      }
    }
  }
}
