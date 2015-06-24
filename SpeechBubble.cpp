#include "stdafx.h"
#include "SpeechBubble.h"

#ifndef COMPILE_NO_SF
SpeechBubble::SpeechBubble() : Actor() {
  message = "";
  index = 0;
  start_index=0;
}

SpeechBubble::SpeechBubble(Level* l, std::string s,sf::Color c) : Actor(l,0,500,700,100) {
  message = s;
  index = 0;
  start_index = 0;
  col = c;
  font.loadFromFile("../YSA_VB/YSA/Fonts/arial.ttf");
  text.setFont(font);
  text.setString("");
  text.setCharacterSize(15);
  text.setColor(col);
  text.setPosition(10,510);
  
  shape.setFillColor(sf::Color(0,0,150,255/2));
  shape.setPosition(x,y);
  shape.setSize(width,height);
}
void windowEvent(sf::Event& event) {
  while (window.pollEvent(event)) {
    if (event.type==sf::Event::KeyPressed) {
      if (isPaused) {
	isPaused=false;
	start_index=index;
	index=0;
	if (start_index>=message.size()-1) {
	  level->sendEvent(END_SPEECH,this);
	}
      }
      else {
	isPaused=true;
	while(message[index]!='.'&&message[index]!='?'&&message[index]!='!')
	  index++;
      }
    } 
  }
}
void render(sf::RenderWindow& window) {
  if (!isPaused)
    index++;
  text.setFont(message.subStr(start_index,index));
  window.draw(shape);
  window.draw(text);
  if (message[start_index+index]=='.'||message[start_index+index]=='?'||
      message[start_index+index]=='!') {
    isPaused=true;
  }
    
  
}
#endif
