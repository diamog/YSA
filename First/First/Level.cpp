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

Level::act() {
  for (unsigned int i =0;i<actors.size();i++)
    actors[i]->act();
}

Level::render() {
  for (unsigned int i=0;i<actors.size();i++)
    actors[i]->render();
}
