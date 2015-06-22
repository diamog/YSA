

#include "stdafx.h"

#include "Detector.h"
#include "Extras/utilities.h"

Detector::Detector() : Actor() {
  actors = NULL;
}
Detector::Detector(Level* l, float x_,float y_,float w,float h,std::vector<Actor*>* acts) : Actor(l,x_,y_,w,h){
  actors = acts;
}

#ifndef COMPILE_NO_SF
void Detector::act(sf::Event& event) {
	for (unsigned int i=0;i<actors->size();i++)
		if (isRectangularHit(this,(*actors)[i])) {
			(*actors)[i]->hitDetector(getApproachDirection((*actors)[i],this));
		}
}

void Detector::render(sf::RenderWindow& window) {
	sf::CircleShape shape(width/2);
	shape.setPosition(x,y);
	shape.setFillColor(sf::Color(255,255,255));
	window.draw(shape);
}


#endif
