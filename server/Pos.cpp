#include "Pos.hpp"

Pos Pos::getPos()const
{
	return *this;
}

const Pos &   Pos::operator=(const Pos & other)
{
    this->x = other.x;
    this->y = other.y;
    return (*this);
}


const Pos   &Pos::operator+(const Pos & other)
{
  this->x += other.x;
  this->y += other.y;
  return (*this);
}


const Pos  &Pos::operator-(const Pos & other)
{
  this->x -= other.x;
  this->y -= other.y;
  return (*this);
}
