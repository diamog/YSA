#include "stdafx.h"
#include "utilities.h"
#include <fstream>
#include <cmath>
#include "MersenneTwister.h"
#include "ReaderClass.h"

float getPI() {return 3.1415926535;}

bool isRectangularHit(Actor* a1,Actor* a2) {
  return a1->getX1()<=a2->getX2() && 
    a1->getX2()>=a2->getX1() &&
    a1->getY1()<=a2->getY2() && 
    a1->getY2()>=a2->getY1();
}

bool isLineHit(Line l1, Line l2) {
  float x1 = l1.p1.first;
  float x2 = l2.p1.first;
  float y1 = l1.p1.second;
  float y2 = l2.p1.second;
  bool isUp1 = x1==l1.p2.first;
  bool isUp2 = x2==l2.p2.first;
  float x;
  float m2=0;
  float y;
  float m1;
  if (isUp1&&isUp2)
    if (x1==x2)
      x=x1;
    else
      return false;
  else if (isUp1) {
    x=x1;
    m2 = l2.m();
  }
  else if (isUp2) {
    x=x2;
    m1=l1.m();
  }
  else {
    m1 = l1.m();
    m2 = l2.m();
    if (m1==m2)
      return false;
    x = (y2-y1+m1*x1-m2*x2)/(m1-m2);
  }
  if (m2==0)
    y = m1*(x-x1)+y1;
  else
    y = m2*(x-x2)+y2;
  return l1.isOn(x,y)&&l2.isOn(x,y);
}

bool isCircleLineHit(Circle c1, Line l) {
  float x1 = l.p1.first;
  float x2 = l.p2.first;
  float y1 = l.p1.second;
  float y2 = l.p2.second;
  float cx = c1.p.first;
  float cy = c1.p.second;
  float cr = c1.rad;
 
  float a = pow(x2-x1,2)+pow(y2-y1,2);
  float b = 2*((x2-x1)*(x1-cx) + (y2-y1)*(y1-cy));
  float c = pow(x1-cx,2)+pow(y1-cy,2)-pow(cr,2);

  float disc = b*b-4*a*c;

  if (disc<0)
    return false;
  disc = sqrt(disc);
  float t1 = (-b-disc)/(2*a);
  float t2 = (-b+disc)/(2*a);
  
  return (t1>=0&&t1<=1)||(t2>=0&&t2<=1);
}

bool testLines(Actor* a1,Actor* a2) {
  std::vector<Line> l1 = a1->getLines();
  std::vector<Line> l2 = a2->getLines();
  for (unsigned int i=0;i<l1.size();i++)
    for (unsigned int j=0;j<l2.size();j++)
      if (isLineHit(l1[i],l2[j]))
        return true;
  return false;
}

bool testCircles(Actor* circle,Actor* lines) {
  std::vector<Circle> cs = circle->getCircles();
  std::vector<Line> ls = lines->getLines();
  for (unsigned int i=0;i<cs.size();i++)
    for (unsigned int j=0;j<ls.size();j++)
      if (isCircleLineHit(cs[i],ls[j]))
        return true;
  return false;
}

int getApproachDirection(Actor* a1, Actor* a2) {
  if (a1->getLastY2()<=a2->getLastY1() && a1->getY2()>=a2->getY1()) //Landing
    return 2;
	
  if (a1->getLastY1()>=a2->getLastY2() && a1->getY1()<=a2->getY2()) //Ceiling
    return 0;
  if (a1->getLastX2() <= a2->getLastX1() && a1->getX2()>= a2->getX1()) //Right wall
    return 1;
  if (a1->getLastX1() >= a2->getLastX2() && a1->getX1()<=a2->getX2()) //Left wall
    return 3;
  return -1;
}

void getObjectCenter(Actor* a,float& cx,float& cy) {
  cx = (a->getX1()+a->getX2())/2;
  cy = (a->getY1()+a->getY2())/2;
}

Achievements achieves;
std::list<Achievement*> achievements;

void loadAchievements() {
  std::ifstream in_str(".ach32948880225704");
  if (!in_str)
    return;
  float ver;
  in_str>>ver;
  size_t num;
  in_str>>num;
  for (size_t i=0;i<num;i++) {
    int val;
    in_str>>val;
    if (ver<.3) {
      int diff=0;
      if (val>START_ACHIEVE)
	diff++;
      if (val>DIE_1000-diff)
	diff+=6;
      if (val>KILL_EVERY-diff)
	diff++;
      if (val>LOOP_EYE-diff)
	diff+=2;
      if (val>PERFECT_CLOUD)
	diff--;
      val+=diff;
    }
    
    achieves.insert(static_cast<A_CODE>(val));
  }
}
void saveAchievements() {
  std::ofstream out_str(".ach32948880225704");
#ifndef PREVERSION
  out_str<<0.3<<"\n\n";
#else
  out_str<<0.25<<"\n\n";
#endif

  out_str<<achieves.size()<<"\n\n";
  Achievements::iterator itr;
  for (itr=achieves.begin();itr!=achieves.end();itr++) {
    int val = *itr;
#ifdef PREVERSION
    int diff=0;
    if (val>START_ACHIEVE)
      diff++;
    if (val>DIE_1000-diff)
      diff+=6;
    if (val>KILL_EVERY-diff)
      diff++;
    if (val>LOOP_EYE-diff)
      diff+=2;
    if (val>PERFECT_CLOUD)
      diff--;
    val-=diff;
    
#endif
    out_str<<val<<" ";
  }
}
bool hasAchievement(A_CODE ach) {
  return achieves.find(ach)!=achieves.end();
}

void buildAchievement(A_CODE ach) {
  if (hasAchievement(ach))
    return;
  achieves.insert(ach);
  achievements.push_back(new Achievement(ach));
}

void renderAchievements(sf::RenderWindow& window) {
  while(achievements.size()>0&&(*achievements.begin())->getAlpha()<=0) {
    delete *achievements.begin();
    achievements.pop_front();
  }
  if (achievements.size()==0)
    return;
  std::list<Achievement*>::iterator itr;
  for (itr=achievements.begin();itr!=achievements.end();itr++)
    (*itr)->render(window);
}

void setupText(sf::Text& text,sf::Font& f,std::string s,int size, sf::Color c,
	       double x, double y, int num_chars) {
  text.setFont(f);
  text.setString(s);
  text.setCharacterSize(size);
  text.setColor(c);
  text.setOrigin(0,0);
  text.setPosition(0,0);
  if (num_chars==-1) {
    float width = text.findCharacterPos(s.size()).x-text.findCharacterPos(0).x;
    text.setOrigin(width/2,0);
  }
  else 
    text.setOrigin(text.findCharacterPos(num_chars).x,0);
  text.setPosition(x,y);
}

void setupRect(sf::RectangleShape& shape,float x1, float y1, float x2, float y2,
	       sf::Color col,sf::Color out, int out_size) {
  shape.setPosition(x1,y1);
  shape.setSize(sf::Vector2f(x2-x1,y2-y1));
  shape.setFillColor(col);
  shape.setOutlineColor(out);
  shape.setOutlineThickness(out_size);
}

void setRectPos(sf::RectangleShape& s, sf::Text& t) {
  s.setPosition(t.findCharacterPos(0)-sf::Vector2f(5,0));
  s.setSize(t.findCharacterPos(t.getString().getSize())-t.findCharacterPos(0)+
	    sf::Vector2f(10,t.getCharacterSize()+10));
  
}

MTRand mtr;

int getRandInt(int low, int high) {
  return mtr.randInt(high-low)+low;
}

float getRand(float low, float high) {
  return mtr.rand(high-low)+low;
}

Reader reader;

void addGraphic(std::string name,std::string file_name) {
  reader.registerGraphics(name,file_name);
}
void addFont(std::string name,std::string file_name) {
  reader.registerFont(name,file_name);
}
void addSong(std::string name,std::string file_name, bool repeat) {
  reader.registerSong(name,file_name,repeat);
}

const sf::Texture& getGraphic(std::string name) {
  return reader.getGraphics(name);
}
const sf::Font& getFont(std::string name) {
  return reader.getFont(name);
}
sf::Music* getSong(std::string name) {
  return reader.getSong(name);
}

void destroySongs() {
  reader.destroy();
}
