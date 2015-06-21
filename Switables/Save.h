#include "Switch.h"
#include "../Codes.h"
#include "../You.h"

#ifndef __SAVE__H__
#define __SAVE__H__

class Save : public Switch {
public:
  Save();
  Save(Level* l, float x_, float y_, float w, You* yo, S_CODE num);

  S_CODE getSave() {return identity;}

  #ifndef COMPILE_NO_SF
  void render(sf::RenderWindow& window);
  #endif
protected:
	S_CODE identity;	
#ifndef COMPILE_NO_SF
	sf::CircleShape shape;
#endif

};

#endif
