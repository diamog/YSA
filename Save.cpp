#include "stdafx.h"

#include "Save.h"
#include "utilities.h"

Save::Save() : Switch(){
  you = NULL;
}

Save::Save(Level* l, float x_, float y_, float w, float h, You* yo,S_CODE save) : 
  Switch(l,x_,y_,w,h,yo) {
  eve = SAVE;
	identity = save;
}

#ifndef COMPILE_NO_SF
void Save::render(sf::RenderWindow& window) {
  
} 
#endif
