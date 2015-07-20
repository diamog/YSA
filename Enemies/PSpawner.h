#ifndef __PSPAWNER__H__
#define __PSPAWNER__H__

#include <cmath>
#include "PBullet.h"
#include "../Extras/utilities.h"

class PSpawner : public PBullet {
public:
  PSpawner();
  PSpawner(Level* l,float x_, float y_,You* yo,float angle,std::vector<PBullet*>* b);
  void act();
protected:
  std::vector<PBullet*>* bullets;

};

#endif
