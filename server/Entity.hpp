
#ifndef ENTITY
# define ENTITY

#include "Pos.hpp"
#include <list>
#include <iostream>
#include <string.h>

typedef struct s_box
{
  float	x;
  float y;
  char	name[25];
  int	index;
  bool	alive;
}t_box;

class Entity //: public IEntity
{
public:
  Entity();
  Entity(const Pos &);
  Entity(const Entity &);
  ~Entity();
  

  std::string &			getName(){ return name;};
  Pos  			getCoor()const;
  t_box			creatBox();
  virtual void		doAction() = 0;
  bool			isAlive();
  std::list<Entity*>	fire();
  void			collision(Entity *);
  bool			isFriend()const;
  void			takeDamage(int);
protected:

  virtual void			checkCoor();
  Pos			coor;
  Pos			_dir;
  std::list<Pos>	weapon;
  int			cd;
  int 			hp;
  float			hitbox;
  bool 			brk;
  int			_index;
  bool			alive;
  bool			friendly;
  bool			firemode;
  std::string		name;
};

#endif
