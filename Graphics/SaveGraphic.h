#include "../Actor.h"

#ifndef __SAVEGRAPHIC_H__
#define __SAVEGRAPHIC_H__

class SaveGraphic : public Actor {
 public:
  SaveGraphic() : Actor() {};
  SaveGraphic(Level* l,bool isC);
  void act() {};
#ifndef COMPILE_NO_SF
  void render(sf::RenderWindow& window);
#endif
 private:
  int alpha;
  Level* mylevel;
  bool isColor;
#ifndef COMPILE_NO_SF
  sf::RectangleShape shape;
#endif
};
#endif
