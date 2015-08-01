#include "stdafx.h"
#include "achievements.h"
Achievement::Achievement(A_CODE ach) : Actor(NULL,200,100,300,100){

  if (ach==SAVE_1) {
    name="You Saved!";
    snippet="The circle of regen+1000";
    desc="Hit that circle thing that flashes";
  }
  else if (ach==DIE_1) {
    name="The first of many";
    snippet="Get used to it";
    desc="Fall to the mighty hands of mortality";
  }
  else if (ach==DIE_10) {
    name="A few corpses";
    snippet="Is it hard yet?";
    desc="Leave ten friends behind";
  }
	else if (ach==DIE_50) {
    name="Minor sacrifices";
    snippet="Giving up?";
    desc="Fifty sould departed";
  }
	else if (ach==DIE_100) {
    name="One hundred versus the world";
    snippet="The world won one million dollars!";
    desc="Throw 100 bodies at life.";
  }
	else if (ach==DIE_300) {
    name="This is SPARTA!";
    snippet="Your army is not as tough";
    desc="Lose an army of 300 on the battlefield";
  }
	else if (ach==DIE_500) {
    name="We are running out of yellow paint here";
    snippet="You really like dying don't you?";
    desc="Recolor yourself 500 times.";
  }
	else if (ach==DIE_999) {
    name="All out of paint";
    snippet="Seriously don't die again we don't have any more paint";
    desc="Use up all 999 liters of yellow paint on yourself";
  }
	else if (ach==DIE_1000) {
    name="Game over";
    snippet="Hah fooled you! We got plenty more for you.";
    desc="Die more times than we have paint to revive you with";
  }
	else if (ach==NO_SAVE) {
    name="Refuse the save";
    snippet="You know those dark circles were save points right?";
    desc="Don't save until the color is restored";
  }
	else if (ach==EVIL_SAVE) {
    name="Can the dark square save too?";
    snippet="Thanks for testing that for me";
    desc="Try to save with the dark square";
  }
	else if (ach==LOOP_EYE) {
    name="Infinite loops!";
    snippet="Back and forth and back and forth...";
    desc="Get your eye stuck in a loop";
  }
	else if (ach==EXTRA_1) {
    name="Got 1!";
    snippet="What could these do?";
    desc="Collect 1 of the mysterious pink items";
  }
	else if (ach==EXTRA_5) {
    name="Got 5!";
    snippet="Where are you putting all of these?";
    desc="Collect 5 of the mysterious pink items";
  }
	else if (ach==EXTRA_10) {
    name="Got 10!";
    snippet="At least they don't slow you down";
    desc="Collect 10 of the mysterious pink items";
  }
	else if (ach==EXTRA_20) {
    name="Got 20!";
    snippet="You are determined even though they seem to serve no purpose";
    desc="Collect 20 of the mysterious pink items";
  }
	else if (ach==EXTRA_ALL) {
    name="Got ALL!";
    snippet="Well done I am sure you will be rewarded for your efforts";
    desc="Collect all of the mysterious pink items";
  }
	else if (ach==BEAT_COLOR) {
    name="Color Restored!";
    snippet="Well now things are more distiguishable";
    desc="Defeat the keeper of colors.";
  }
	else if (ach==OCD) {
    name="OCD";
    snippet="Obsessive color disorder";
    desc="Prove that you must keep patterns";
  }
  shape.setFillColor(sf::Color(0,190,0));
  shape.setOutlineColor(sf::Color(50,50,50,150));
  shape.setOutlineThickness(20);
  alpha=255;
  tick=0;
  shape.setPosition(x,y);
  shape.setSize(sf::Vector2f(width,height));
  font.loadFromFile("Fonts/arial.ttf");
  name_text.setFont(font);
  name_text.setString(name);
  int size = 24;
  name_text.setCharacterSize(size);
  name_text.setOrigin(size*name.length()/4,0);
  name_text.setPosition(x+width/2,y+10);
  name_text.setColor(sf::Color(0,0,0));
  snip.setFont(font);
  snip.setString(snippet);
  int size2 = 15;
  snip.setCharacterSize(size2);
  snip.setPosition(x+15,y+50);
  snip.setColor(sf::Color(0,0,0));
}

void Achievement::render(sf::RenderWindow& window) {
  tick++;
  if (tick>60)
    alpha-=3;
  shape.setFillColor(sf::Color(0,190,0,alpha));
  shape.setOutlineColor(sf::Color(50,50,50,150*alpha/255));
  window.draw(shape);
  name_text.setColor(sf::Color(0,0,0,alpha));
  window.draw(name_text);
  snip.setColor(sf::Color(0,0,0,alpha));
  window.draw(snip);
}
