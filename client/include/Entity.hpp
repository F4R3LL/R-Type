//
// Entity.hpp for  in /home/dasilv_f/rendu/rtype/client
// 
// Made by Filipe Da Silva
// Login   <dasilv_f@epitech.net>
// 
// Started on  Tue Dec 20 11:01:10 2016 Filipe Da Silva
// Last update Mon Dec 26 12:48:33 2016 Filipe Da Silva
//

#ifndef ENTITY
# define ENTITY

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "sendInfo.hpp"

class Entity
{
public:
  Entity(t_box, std::string);
  ~Entity(){delete sp;};
  sf::Sprite *	getSprite();
  bool	check(t_box)const;
  void	setPos(t_box);
  bool	isAlive()const;
private:
  int		index;
  sf::Texture	tex;
  std::string	name;
  sf::Sprite	*sp;
  bool		alive;
};

#endif 
