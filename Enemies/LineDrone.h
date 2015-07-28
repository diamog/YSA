#include "Drone.h"

#ifndef __LINEDRONE__H__
#define __LINEDRONE__H__

class LineDrone : public Drone {
 public:
  LineDrone();
  LineDrone(Level* l, float x_,float y_, You* yo,int d);
  

  void hitDetector(int adir);
};

#endif
