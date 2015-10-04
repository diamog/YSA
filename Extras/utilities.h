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
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

float getPI();

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

void setupRect(sf::RectangleShape& shape,float x1, float y1, float x2, float y2,
	       sf::Color col,sf::Color out, int out_size);

void setRectPos(sf::RectangleShape& s, sf::Text& t);


int getRandInt(int low, int high);

float getRand(float low,float high);

void addGraphic(std::string name,std::string file_name);

const sf::Texture& getGraphic(std::string name);

void addFont(std::string name,std::string file_name);

const sf::Font& getFont(std::string name);

void addSong(std::string name,std::string file_name, bool repeat);

sf::Music* getSong(std::string name);

void destroySongs();
#endif
