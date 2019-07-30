//
// Cruser.hpp for aze in /home/roby_t/rendu/rtype/server/Enemy
// 
// Made by Tristan Roby
// Login   <roby_t@epitech.net>
// 
// Started on  Mon Dec 26 12:10:06 2016 Tristan Roby
// Last update Thu Dec 29 21:03:34 2016 valentin1 fernandes
//

#ifndef CRUSER_H_
#define CRUSER_H_

#include "Entity.hpp"

class Cruser : public Entity
{
public:
  Cruser(const Pos &coord) : Entity(coord) { 
    hp = 10;
    name = "Cruser.png";
    _dir.x = -7;
    _dir.y = 0;
    weapon.push_back(Pos(-7, 0));
    friendly = false;
  }
  ~Cruser(){};
  virtual  void	doAction();
  virtual  void checkCoor();
};

#endif
