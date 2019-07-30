#include "Entity.hpp"
#include "Bullet.hpp"

static int i = 0;

Entity::Entity()
{
  _index = i++;
  alive = true;
  firemode = false;
}

Entity::Entity(const Pos & cor) : coor(cor)
{
  _index = i++;
  alive = true;
  firemode = false;
}

Entity::Entity(const Entity & other) : coor(other.getCoor())
{
  _index = i++;
  alive = true;
  firemode = false;
  friendly = other.isFriend();
  
}

Entity::~Entity()
{
  if (_index == 50)
    i = 0;
}

bool Entity::isFriend()const
{
  return friendly;
}

Pos  Entity::getCoor()const
{
  Pos a = coor;
  return (a);
}

bool	Entity::isAlive()
{
  checkCoor();  
  return alive;
}

void	Entity::checkCoor()
{
  if (coor.x < 0)
    coor.x = 0;
  if (coor.y < 0)
    coor.y = 0;
  if (coor.x > 1200)
    coor.x = 1200;
  if (coor.y > 700)
    coor.y = 700;
}

t_box	Entity::creatBox()
{
  t_box box;


  box.x = coor.x;
  box.y = coor.y;
  box.index = _index;
  box.alive = alive;
  memset(box.name, 0, 25);
  memcpy(box.name, name.c_str(), name.size());
  return box;
}

void	Entity::takeDamage(int da)
{
  hp -= da;
  if (hp <= 0)
    alive = false;
}

void	 Entity::collision(Entity * other)
{
  if (other->getName() == "bullet.png" || friendly == other->isFriend())
    return;
  Pos test = other->getCoor();
  int hb = 100;
  int a = coor.x - test.x;
  if (a >= 0 && a <= hb)
    {
      a = coor.y - test.y;
      if (a >= 0 && a <= hb)
	{
	  other->takeDamage(10);
	  alive = false;
	}
    }
  
}

std::list<Entity *> Entity::fire()
{
  std::list<Entity *>bullet;

  if (firemode == true && cd == 10)
    {
      cd = 0;
      for (auto i : weapon)
	bullet.push_back(new Bullet(1, *this, i));
    }
  if (cd >= 10)
    cd = 9;
  ++cd;
  return bullet;
}
/*
void Entity::affCoor()const
{
	std::cout << coor.x << "  " << coor.y << std::endl;
}
*/
