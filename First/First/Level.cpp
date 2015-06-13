#include "stdafx.h"
#include "Level.h"

Level::Level() {
  you = NULL;
  x=y=0;
}

Level::Level(You* yo, float enterx, float entery, ENT_CODE ent) {
  you = yo;
  x=y=0;
  makePlatforms();
  makeEnemies();
  makeCollectables();
  makeSwitches();
}

Level::~Level() {
  for (unsinged int i=0;i<actors.size();i++)
    delete actors[i];
}
Level::act() {
  for (unsigned int i =0;i<actors.size();i++)
    actors[i]->act();
}

Level::render(sf::RenderWindow& window) {
  for (unsigned int i=0;i<actors.size();i++)
    actors[i]->render(window);
}
