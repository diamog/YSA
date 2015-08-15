// First.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

#include <iostream>
#include <fstream>
#ifndef COMPILE_NO_SF
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#endif
#include "You.h"
#include "Codes.h"
#include "Levels/Levels.h"
#include <cstdlib>
#include <time.h>
#include "Extras/Line.h"
#include "Extras/utilities.h"
#include "Menus/StartMenu.h"
#include "Menus/FileMenu.h"
#include "Menus/FileMenu2.h"
#include "Menus/PauseMenu.h"

void loadInFiles();

int main() {
  
  srand(time(NULL));
  //Definition of Window
  int width = 700;
  int height = 600;
  loadAchievements();
#ifndef COMPILE_NO_SF
  sf::RenderWindow window(sf::VideoMode(width, height), "YSA Version 0.2.5");
  sf::Music* song = NULL;
  window.setFramerateLimit(60);
#endif
  loadInFiles();
  int menu=0;
  StartMenu start_menu; 

  // Definition of you
  bool* isDead = new bool;
  *isDead = false;
  You* you1 = new You(200,height-400.0f,20,20,isDead);
  you1->setDifficulty(MEDIUM);
  you1->load(".7sdf43sdf2ds0598dsf432odhj");
  You* you2 = new You(200,height-400.0f,20,20,isDead);
  you2->setDifficulty(HARD);
  you2->load(".9sdf43sdf2ds0598dsf432odhj");
  You* you3 = new You(200,height-400.0f,20,20,isDead);
  you3->setDifficulty(EASY);
  you3->load(".8sdf43sdf2ds0598dsf432odhj");
  FileMenu file_menu(you1,you2,you3);
  FileMenu2 file_menu2;
  PauseMenu pause_menu;
  You* you = NULL;
  Level* level = NULL;
  bool isInFocus=true;
#ifndef COMPILE_NO_SF
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
      if (event.type == sf::Event::LostFocus) {
	isInFocus=false;
	if (menu==-1&&!you->isPause()) {
	  you->pause();
	  pause_menu.setYou(you);
	}
      }
      if (event.type== sf::Event::GainedFocus) {
	isInFocus=true;
      }
      if (event.type==sf::Event::KeyPressed&&
	  event.key.code == sf::Keyboard::Escape)
	window.close();
      if (menu==-1) {
	if (event.type == sf::Event::KeyPressed) {
	  if(event.key.code ==sf::Keyboard::R&&((!you->isPause()&& !you->isPauseM())||*isDead)) {
	    *isDead=false;
	    you->reload();
	    delete level;
	    level = loadLevel(you,you->getSave());
	  }
	  if (event.key.code == sf::Keyboard::W&&*isDead==false&&!you->isPause()&& !you->isPauseM()) {
	    you->warp();
	    level->warp();
	  }
	  if (event.key.code ==sf::Keyboard::O) {
	    you->print();
	  }
	  if (event.key.code ==sf::Keyboard::P&&!*isDead&&!you->isPauseM()&&!you->isPauseC()) {
	    pause_menu.setYou(you);
	    you->pause();
	  }
	  if (event.key.code == sf::Keyboard::Num0) {
	    you->save(GAME_START);
	  }
	  if (event.key.code == sf::Keyboard::Num1) {
	    you->save(ROOM_1);
	  }
	  if (event.key.code==sf::Keyboard::Num2) {
	    you->save(CROSS_ROADS);
	    you->beatBoss1();
	  }
	  if (event.key.code==sf::Keyboard::Num3) {
	    you->save(ROOM_3);
	  }
	  if (event.key.code==sf::Keyboard::Num5) {
	    you->save(WALL_KICK_3);
	  }
	  if (event.key.code==sf::Keyboard::Num4) {
	    you->save(PRE_BOSS_2);
	  }

	}
	level->windowEvent(event);
	
      }
    }
    if (menu==-1) {
      if (!you->boss1()&&!level->isBoss())  {
	if (!song) {
	  song=getSong("Colorless");
	  song->play();
	}
      }
      else {
	if (song)
	  song->stop();
	song=NULL;
      }
      if (!you->isPause()) {
	if (*isDead==false) {
	  if (!you->isPauseM())
	    you->act();
	}
	level->act();
      }

      L_CODE next_level;
      ENT_CODE ent;
      if (level->isChangeRoom(next_level,ent)) {
	Level* temp = level;
	level = makeLevel(you,temp,next_level,ent);
	delete temp;
      
      }
    
      if (level->isBoss())
	window.clear();
      else if (you->isAntiGravity()) {
	window.clear(sf::Color(0,180,180));
      }
      else
	window.clear(sf::Color(100,100,100));
      level->render(window);
      you->render(window);
      renderAchievements(window);
      
      if (you->isPause()){
	if (song)
	  song->setVolume(50);
	if (isInFocus)
	  pause_menu.act();
	pause_menu.render(window);
	pause_menu.isChangeMenu(menu);
	if (menu!=-1&&song) {
	  song->stop();
	  song=NULL;
	}
      }
      else if (song)
	song->setVolume(100);
    }
    else if (menu==0) {
      if (isInFocus)
	start_menu.act();
      if (start_menu.isChangeMenu(menu)) {
	if (menu==1)
	  file_menu.restart(you1,you2,you3);
      }
      window.clear(sf::Color(100,100,100));
      start_menu.render(window);
    }
    else if (menu==1) {
      if (isInFocus)
	file_menu.act();
      if (file_menu.isChangeMenu(menu)) {
	if (menu!=0) {
	  if (menu==-2)
	    you=you1;
	  else if (menu==-3)
	    you=you2;
	  else if (menu==-4)
	    you=you3;
	  menu=2;
	  file_menu2.setYou(you);
	}
      }
 
      window.clear(sf::Color(100,100,100));
 
      file_menu.render(window);
 
    }
    else if (menu==2) {
      if (isInFocus)
	file_menu2.act();
      if (file_menu2.isChangeMenu(menu)) {
	if (menu==-1) {
	  level = loadLevel(you, you->getSave());
	}
	else if (menu==1)
	  file_menu.restart(you1,you2,you3);
      }
 
      window.clear(sf::Color(100,100,100));
 
      file_menu2.render(window);
      
    }
    window.display();
  }
#endif
  saveAchievements();
  if (song)
    song->stop();
  if (level) delete level;
  delete you1;
  delete you2;
  delete you3;
  delete isDead;
  destroySongs();
  return 0;
}

void loadInFiles() {
  addGraphic("Pumpkin","Graphics/GreatPumpkin1.png");
  addGraphic("Fairy1","Graphics/fairy1.png");
  addGraphic("Fairy5","Graphics/fairy5.png");
  addGraphic("GrayFairy","Graphics/grayfairy1.png");
  addGraphic("PumpkinHead","Graphics/pumpkin1.png");
  addGraphic("PumpkinHeadTurn","Graphics/pumpkin2.png");
  addGraphic("GhostPumpkin","Graphics/pumpkin_spirit.png");
  addGraphic("Vine","Graphics/vines.png");
  addGraphic("DeadVine","Graphics/wiltedvines.png");
  
  addFont("Arial","Fonts/arial.ttf");

  //Songs
  addSong("Colorless","Music/Colorless.wav",true);
  
  //Sfx
  addSong("Save","Music/save.wav",false);
}
