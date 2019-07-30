//
// Kamikaz.cpp for  in /home/dasilv_f/rendu/rtype/server/Enemy
// 
// Made by Filipe Da Silva
// Login   <dasilv_f@epitech.net>
// 
// Started on  Thu Dec 29 12:34:42 2016 Filipe Da Silva
// Last update Fri Dec 30 15:31:21 2016 Filipe Da Silva
//

#include "Kamikaz.hpp"

extern "C" {
  Entity *getClass(const Pos & coord)
  {
    return (new Kamikaz(coord));
  }
}

void	Kamikaz::checkCoor()
{
  if (coor.y < 0 && _dir.y < 0 || coor.y > 700 && _dir.y > 0)
    _dir.y *= -1;
  if (coor.x < -100)
    alive = false;
}

void	Kamikaz::doAction()
{
  coor.x += _dir.x;
  coor.y += _dir.y;

  firemode = false;
  /*if (static_cast<int>(coor.x) % 100 == 0)
    firemode = true;*/
}
