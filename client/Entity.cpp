//
// Entity.cpp for  in /home/dasilv_f/rendu/rtype/client
// 
// Made by Filipe Da Silva
// Login   <dasilv_f@epitech.net>
// 
// Started on  Tue Dec 20 11:01:25 2016 Filipe Da Silva
// Last update Tue Dec 27 14:06:56 2016 valentin1 fernandes
//

#include "include/Entity.hpp"
#include <iostream>

Entity::Entity(t_box box, std::string text)
{
  tex.loadFromFile("client/assets/"+text);
  sp = new sf::Sprite(tex);
  sp->setPosition(box.x, box.y);
  index = box.index;
  name = std::string(box.name);
  alive = true;
}

sf::Sprite *	Entity::getSprite()
{
  return sp;
}

bool		Entity::isAlive()const
{
  return alive;
}

void	Entity::setPos(t_box box)
{
  alive = box.alive;
  sp->setPosition(box.x, box.y);
}

bool	Entity::check(t_box box)const
{
  if (box.index == index && std::string(box.name) == name)
    return true;
  return false;
}
