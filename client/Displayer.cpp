//
// Displayer.cpp for displayer in /home/roby_t/rendu/rtype/client
// 
// Made by Tristan Roby
// Login   <roby_t@epitech.net>
// 
// Started on  Fri Dec 16 16:58:00 2016 Tristan Roby
// Last update Fri Dec 30 15:18:08 2016 Tristan Roby
//

#include "include/Displayer.hpp"
#include "include/keyhandler.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <unistd.h>

Displayer::Displayer(Talker *t)
{
  this->window = new sf::RenderWindow(sf::VideoMode(1280, 720), "rtype");

  if (!this->texture.loadFromFile("client/assets/map.png"))
    std::cout << "pb load texture olala" << std::endl;

  this->sprite = new sf::Sprite(this->texture);
  if (!this->texture.loadFromFile("client/assets/map.png"))
    std::cout << "pb load texture olala" << std::endl;
  fond2 = new sf::Sprite(texture);
  sprite->setScale(5, 5);
  fond2->setScale(5, 5);
  this->sprite->setPosition(0, 0);
  talk = t;
}

void	Displayer::draw()
{
  for (auto i : _listEntity)
    if (i->getSprite())
      window->draw(*(i->getSprite()));
}

bool	Displayer::check(t_box box)
{
  for (auto i : _listEntity)
    if (i->check(box))
      {
	i->setPos(box);
	return true;
      }
  return false;
}

void	Displayer::clearList()
{
  std::list<Entity*> tmp;

  for (auto i : _listEntity)
    {
      if (i->isAlive())
	tmp.push_back(i);
      else
	delete i;
    }
  _listEntity = tmp;
}

void	Displayer::mainLoop()
{
  t_box box;
  sf::Clock clock;
  Keyhandler handler(talk);
  float a = 0;

  handler.send();
  box.index = -1;
  while (this->window->isOpen())
    {
      sf::Time elapsed = clock.restart();
      handler.catchKey(this->window);
      for (int i = 0; i != 100; ++i){
	box = handler.recv();
      if (box.index < 100 && box.index >= 0)
	{
	  if (_listEntity.size() == 0)
	    _listEntity.push_back(new Entity(box, box.name));
	  else if (check(box) == false)
	    _listEntity.push_back(new Entity(box, box.name));
	}
      }
      sprite->setPosition(a, 0);
      fond2->setPosition(a + 2998, 0);
      a -= 10.5;
      if (a <= -3000)
	a = 0;
      clearList();
      window->clear();
      window->draw((*sprite));
      window->draw((*fond2));
      draw();
      window->display();
    }
}
