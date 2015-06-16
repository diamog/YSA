#ifndef COMPILE_NO_VB
#include "stdafx.h"
#endif
#include "Save.h"
#include "utilities.h"

Save::Save() : Switch(){
  you = NULL;
}

Save::Save(Level* l, float x_, float y_, float w, float h, You* yo) : 
  Switch(l,x_,y_,w,h) {
  you = yo;
  eve = SAVE;
}

#ifndef COMPILE_NO_SF
void Save::render(sf::RenderWindow& window) {
  
} 
#endif
