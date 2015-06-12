#ifndef __ACTOR__H__
#define __ACTOR__H__

#include <SFML/Graphics.hpp>
#include <iostream>


class Actor {
public:
	Actor();
	Actor(float x_,float y_,float w,float h);


	virtual float getX1() const {return x;}
	virtual float getX2() const {return x+width;}
	virtual float getY1() const {return y;}
	virtual float getY2() const {return y+height;}

	virtual void act() = 0;
	virtual void render(sf::RenderWindow& window) = 0;

protected:
	float x,y;
	float width,height;
};

#endif
