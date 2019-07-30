//
// Cruser.cpp for cpp in /home/roby_t/rendu/rtype/server/Enemy
// 
// Made by Tristan Roby
// Login   <roby_t@epitech.net>
// 
// Started on  Mon Dec 26 12:13:46 2016 Tristan Roby
// Last update Fri Dec 30 15:31:51 2016 Filipe Da Silva
//

#include "Boss.hpp"

extern "C" {
  Entity *getClass(const Pos & coord)
  {
    return (new Boss(coord));
  }
}

void	Boss::checkCoor()
{
  if (coor.x <= 900 && _dir.y == 0)
    {
      _dir.x = 0;
      _dir.y = 2;
    }
  if (coor.y < 0 && _dir.y < 0 || coor.y > 700 && _dir.y > 0)
    _dir.y *= -1;
}

void	Boss::doAction()
{
  std::list<Pos> wea;

  coor.x += _dir.x;
  coor.y += _dir.y;
  firemode = false;
  if (rand() % 50 == 0)
    {
      wea.push_back(Pos(-7, 5));
      wea.push_back(Pos(-7, 4));
      wea.push_back(Pos(-7, 3));
      wea.push_back(Pos(-7, 2));
      wea.push_back(Pos(-7, 1));
      wea.push_back(Pos(-7, 0));
      wea.push_back(Pos(-7, -1));
      wea.push_back(Pos(-7, -2));
      wea.push_back(Pos(-7, -3));
      wea.push_back(Pos(-7, -4));
      wea.push_back(Pos(-7, -5));
      for (auto i : wea)
	if (rand() % 3 != 0)
	  weapon.push_back(i);
      wea = weapon;
      firemode = true;
    }
  weapon = wea;
}
