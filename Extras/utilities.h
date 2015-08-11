#ifndef __UTILITIES__H__
#define __UTILITIES__H__

#include "../Actor.h"
#include "../Mover.h"
#include "Line.h"
#include "Circle.h"
#include "achievements.h"
#include "../Codes.h"
#include <iostream>
#include <vector>
#include <list>

bool isRectangularHit(Actor* a1,Actor* a2);

bool isLineHit(Line l1, Line l2);

bool isCircleLineHit(Circle c1,Line l1);

bool testLines(Actor* a1,Actor* a2);

bool testCircles(Actor* circle,Actor* lines);

int getApproachDirection(Actor* a1, Actor* a2);

void getObjectCenter(Actor* a,float& cx,float& cy);

void loadAchievements();

void saveAchievements();

bool hasAchievement(A_CODE ach);

void buildAchievement(A_CODE ach);

void renderAchievements(sf::RenderWindow& window);

void setupText(sf::Text& text,sf::Font& f,std::string s,int size, sf::Color c,
	       double x, double y, int num_chars=-1);

void setRectPos(sf::RectangleShape& s, sf::Text& t);

int getRandInt(int low, int high);

float getRand(float low,float high);

#endif
