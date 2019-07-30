#ifndef BULLET
# define BULLET

#include "entity.hpp"

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
	Bullet(Bt da, const Pos & other) : damage(da), Entity(other) {}
	virtual void doAction(){
		/* 
		for (i = 0; i != 4; ++i)
		{
			if (checkifsamepos(game.player[i], *this) == true)
				{
					doDamageTo(game.player[i], damage);
					destroyBullet();
				}
			
		}
		x = x - 0.1;
		*/
		}
private:
	Bt	damage;
};

#endif