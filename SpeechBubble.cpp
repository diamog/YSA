#include "stdafx.h"
#include "SpeechBubble.h"

#ifndef COMPILE_NO_SF
SpeechBubble::SpeechBubble() : Actor() {
  message = "";
  index = 0;
  start_index=0;
  tick=0;
}

SpeechBubble::SpeechBubble(Level* l, std::string s,sf::Color c,EVE_CODE e) : Actor(l,0,500,700,100) {
  message = s;
  index = 0;
  start_index = 0;
  col = c;
  eve = e;
  tick=0;

  font.loadFromFile("../YSA_VB/YSA/Fonts/arial.ttf");
  text.setFont(font);
  text.setString("");
  text.setCharacterSize(15);
  text.setColor(col);
  text.setPosition(x+10,y+10);

  next_text.setFont(font);
  next_text.setString("Press any key to continue\n");
  next_text.setCharacterSize(12);
  next_text.setColor(sf::Color(0,0,0));
  next_text.setPosition(x+10,getY2()-22);

  shape.setFillColor(sf::Color(0,0,150,255/2));
  shape.setPosition(x,y);
  shape.setSize(width,height);
}
void windowEvent(sf::Event& event) {
  while (window.pollEvent(event)) {
    if (event.type==sf::Event::KeyPressed) {
      if (isPaused) {
	isPaused=false;
	start_index+=index+2;
	index=0;
	if (start_index>=message.size()-1) {
	  level->sendEvent(END_SPEECH,this);
	}
      }
      else {
	isPaused=true;
	while(message[start_index+index+1]!=';')
	  index++;
      }
    } 
  }
}

void render(sf::RenderWindow& window) {
  if (!isPaused) {
    tick++;
    if (tick>=30) {
      tick=0;
      index++;
    }
  }
  text.setFont(message.subStr(start_index,index));
  window.draw(shape);
  window.draw(text);
  window.draw(next_text);
  if (message[start_index+index+1]==';') {
    isPaused=true;
  }  
}

#endif
