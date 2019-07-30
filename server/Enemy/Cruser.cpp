//
// Cruser.cpp for cpp in /home/roby_t/rendu/rtype/server/Enemy
// 
// Made by Tristan Roby
// Login   <roby_t@epitech.net>
// 
// Started on  Mon Dec 26 12:13:46 2016 Tristan Roby
// Last update Thu Dec 29 12:36:35 2016 Filipe Da Silva
//

#include "Cruser.hpp"

extern "C" {
  Entity *getClass(const Pos & coord)
  {
    return (new Cruser(coord));
  }
}

void	Cruser::checkCoor()
{
  if (coor.x < -100)
    alive = false;
}

void	Cruser::doAction()
{
  coor.x -= 2;
  firemode = false;
  if (static_cast<int>(coor.x) % 100 == 0)
    firemode = true;
}
