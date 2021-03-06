#include "stdafx.h"
#include "SpeechBubble.h"
#include "Level.h"
#ifndef COMPILE_NO_SF
SpeechBubble::SpeechBubble() : Actor() {
  message = "";
  index = 0;
  start_index=0;
  tick=0;
  total_tick=0;
}

SpeechBubble::SpeechBubble(Level* l, std::string s,sf::Color c,float y_,EVE_CODE e) : Actor(l,0,500,700,100) {
  if (y_>300)
    y=0;
  message = s;
  index = 0;
  start_index = 0;
  total_tick=0;
  col = c;
  eve = e;
  tick=0;
  isPaused=false;
  font.loadFromFile("Fonts/arial.ttf");
  text.setFont(font);
  text.setString("");
  text.setCharacterSize(25);
  text.setColor(col);
  text.setPosition(x+10,y+10);

  next_text.setFont(font);
  next_text.setString("Press any key to continue\n");
  next_text.setCharacterSize(12);
  next_text.setColor(sf::Color(0,0,0));
  next_text.setPosition(x+10,getY2()-22);

  shape.setFillColor(sf::Color(0,0,150,255/2));
  shape.setPosition(x,y);
  shape.setSize(sf::Vector2f(width,height));
}
void SpeechBubble::windowEvent(sf::Event& event) {
  if (event.type==sf::Event::KeyPressed) {
    if (event.key.code==sf::Keyboard::S) {
      isPaused=true;
      level->sendEvent(eve,this);
      return;      
    }
    if (total_tick<250/frame_diff)
      return;
 
    if (isPaused) {
      isPaused=false;
      start_index+=index+2;
      index=0;
      if (start_index>=message.size()-1) {
	level->sendEvent(eve,this);
      }
    }
    else {
      isPaused=true;
      while(message[start_index+index]!=';')
	index++;
    }
  } 
}

void SpeechBubble::render(sf::RenderWindow& window) {
  total_tick++;
  if (!isPaused) {
    tick++;
    if (tick>=15/frame_diff) {
      tick=0;
      index++;
    }
  }
  text.setString((message.substr(start_index,index)).c_str());
  unsigned int limit = 60;
  if (index>limit) {
    limit = message.find_last_of(' ',start_index+limit);
    int dist = limit-start_index;
    text.setString(((message.substr(start_index,dist))+'\n'+message.substr(limit+1,index-dist-1)).c_str());
  }
  window.draw(shape);
  window.draw(text);
  window.draw(next_text);
  if (message[start_index+index]==';') {
    isPaused=true;
  }  
}

#endif
