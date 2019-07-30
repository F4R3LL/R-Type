#include "Bullet.hpp"

Bullet::Bullet(int da, const Entity & other, const Pos & dr) : damage(da), Entity(other)
{
  coor.y += 61.5;
  coor.x += 130;
  name = "bullet.png";
  _dir = dr;
}

void	Bullet::doAction()
{
  coor.x = coor.x + _dir.x;
  coor.y = coor.y + _dir.y;
}

void	Bullet::checkCoor()
{
  if (coor.x < 0)
    alive = false;
  if (coor.y < 0)
    alive = false;
  if (coor.x > 1300)
    alive = false;
  if (coor.y > 740)
    alive = false;
}
