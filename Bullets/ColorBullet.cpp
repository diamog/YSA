#include "stdafx.h"
#include "../Bullets/ColorBullet.h"

ColorBullet::ColorBullet() : Actor(),Bullet() {
  target=NULL;
}

ColorBullet::ColorBullet(Level* l,float x_, float y_, float w, float h,
			 std::string t,ColorBoss* b, int c) : 
  Actor(l,x_,y_,w,h),Bullet(l,x_,y_,w,h,t) {
  target=b;
  color=c;
#ifndef COMPILE_NO_SF
  shape.setFillColor(sf::Color(color*(type=="red"),color*(type=="green"),
                            color*(type=="blue")));
#endif
}

void ColorBullet::act() {
  float cx,cy;
  getObjectCenter(this,cx,cy);
  float bx,by;
  getObjectCenter(target,bx,by);
  float vel=1*frame_diff;
  if (fabs(cx-bx)<5) ;
  else if (cx<bx)
    x+=vel;
  else
    x-=vel;
  if (fabs(cy-by)<5) ;
  else if (cy<by)
    y+=vel;
  else
    y-=vel;
}

