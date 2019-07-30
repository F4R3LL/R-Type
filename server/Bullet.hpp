#ifndef BULLET
# define BULLET

#include "Entity.hpp"

enum Bt{
	small=1,
	big,
	laser,
	mlaser,
	HyperBeam
};

class Bullet : public Entity
{
public:
  Bullet(int da, const Entity & other, const Pos &dir);
  virtual void doAction();
  virtual void	checkCoor();
private:
	int	damage;
};

#endif
