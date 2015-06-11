#ifndef __PLATFORM__H__
#define __PLATFORM__H__

#include "You.h"
#include "Actor.h"

class Platform : public Actor {
public:
	Platform();
	Platform(float x_,float y_,float w,float h,You* yo);

	void act();
	void render(sf::RenderWindow& window);

private:
	
	bool isUp,isLeft,isRight,isDown;
	You* you;
	sf::RectangleShape shape;

};

#endif