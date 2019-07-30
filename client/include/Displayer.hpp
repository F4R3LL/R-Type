//
// Displayer.hpp for displ in /home/roby_t/rendu/rtype/client/include
// 
// Made by Tristan Roby
// Login   <roby_t@epitech.net>
// 
// Started on  Fri Dec 16 16:55:37 2016 Tristan Roby
// Last update Fri Dec 30 15:18:35 2016 Tristan Roby
//

#ifndef DISPLAYER_HPP_
# define DISPLAYER_HPP_

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Talker.hpp"
#include "Entity.hpp"
#include <list>
#include <vector>

class Displayer
{
public:
  Displayer(Talker *);
  ~Displayer(){};

private:
  sf::RenderWindow	*window;
  sf::Texture		texture;
  sf::Sprite		*sprite;
  sf::Sprite		*fond2;

  std::list<Entity*>	_listEntity;
  Talker		*talk;
//  std::vector<sf::Sprite*> all;
  void	draw();
  bool	check(t_box);
  void	clearList();
public:
  void mainLoop();
};

#endif
