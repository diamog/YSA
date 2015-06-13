#include "stdafx.h"
#include "Level.h"

Level::Level() {
  you = NULL;
  x=y=0;
}

Level::Level(You* yo) {
  you = yo;
  x=y=0;
  
}

void Level::setup() {
	makePlatforms();
  makeEnemies();
  makeCollectables();
  makeSwitches();
}

Level::~Level() {
  for (unsigned int i=0;i<actors.size();i++)
    delete actors[i];
}
void Level::act() {
  for (unsigned int i =0;i<actors.size();i++)
    actors[i]->act();
}

void Level::render(sf::RenderWindow& window) {
  for (unsigned int i=0;i<actors.size();i++)
    actors[i]->render(window);
}
