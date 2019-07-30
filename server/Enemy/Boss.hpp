//
// Cruser.hpp for aze in /home/roby_t/rendu/rtype/server/Enemy
// 
// Made by Tristan Roby
// Login   <roby_t@epitech.net>
// 
// Started on  Mon Dec 26 12:10:06 2016 Tristan Roby
// Last update Fri Dec 30 15:24:16 2016 Filipe Da Silva
//

#ifndef BOSS
# define BOSS

#include "Entity.hpp"
#include <cstdlib>

class Boss : public Entity
{
public:
  Boss(const Pos &coord) : Entity(coord) { 
    hp = 1000;
    name = "Boss.png";
    _dir.x = -7;
    _dir.y = 0;
    friendly = false;
  }
  ~Boss(){};
  virtual  void	doAction();
  virtual  void checkCoor();
};

#endif
