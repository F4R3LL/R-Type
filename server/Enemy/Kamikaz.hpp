//
// Kamikaz.hpp for  in /home/dasilv_f/rendu/rtype/server/Enemy
// 
// Made by Filipe Da Silva
// Login   <dasilv_f@epitech.net>
// 
// Started on  Thu Dec 29 12:34:45 2016 Filipe Da Silva
// Last update Thu Dec 29 21:21:32 2016 valentin1 fernandes
//

#ifndef KAMIKAZ
# define KAMIKAZ

#include "Entity.hpp"

class Kamikaz : public Entity
{
public:
  Kamikaz(const Pos &coord) : Entity(coord) { 
    hp = 100;
    name = "kamikaz.png";
    _dir.x = -7;
    _dir.y = 4;
    friendly = false;
  }
  ~Kamikaz(){};
  virtual  void	doAction();
  virtual  void checkCoor();
};

#endif
