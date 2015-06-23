#include "stdafx.h"
#include "../Bullets/ColorBullet.h"

ColorBullet::ColorBullet() : Bullet(), Actor() {
  target=NULL;
}

ColorBullet::ColorBullet(Level* l,float x_, float y_, float w, float h,
			 std::string t,ColorBoss* b, int c) : Bullet(l,x_,y_,w,h,t), 
  Actor(l,x_,y_,w,h) {
  target=b;
  color=c;
#ifndef COMPILE_NO_SF
  shape.setFillColor(sf::Color(color*(type=="red"),color*(type=="green"),
                            color*(type=="blue")));
#endif
}

#ifndef COMPILE_NO_SF
void ColorBullet::act(sf::Event& event) {
  float cx,cy;
  getObjectCenter(this,cx,cy);
  float bx,by;
  getObjectCenter(target,bx,by);
  if (fabs(cx-bx)<5) ;
  else if (cx<bx)
    x+=1;
  else
    x-=1;
  if (fabs(cy-by)<5) ;
  else if (cy<by)
    y+=1;
  else
    y-=1;
}

#endif
