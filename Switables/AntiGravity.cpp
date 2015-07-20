#include "stdafx.h"
#include "AntiGravity.h"

AntiGravity::AntiGravity() : Switch(){
  isOn=false;
}

AntiGravity::AntiGravity(Level* l, float x_, float y_, float w, float h,You* yo) : 
  Switch(l,x_,y_,w,h,yo) {
  eve=NOTHING;
  isOn=true;
}

void AntiGravity::activate() {
  if (isOn)
    you->antiGravity();
  isOn=false;
}
