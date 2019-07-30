//
// Game.hpp for  in /home/dasilv_f/rendu/rtype/server
// 
// Made by Filipe Da Silva
// Login   <dasilv_f@epitech.net>
// 
// Started on  Mon Dec 19 13:32:10 2016 Filipe Da Silva
// Last update Thu Dec 29 20:32:44 2016 valentin1 fernandes
//

#ifndef GAME
# define GAME

#include <list>
#include <fcntl.h>
#include <unistd.h>
#include <dlfcn.h>
#include <fstream>
#include <sstream>
#include "ThreadLib/Thread.hpp"
#include "Player.hpp"

class Game
{
public:
  Game(std::list<Player*>, int);
  ~Game(){}

static void*	ThreadStart(void*);
  void		startGame();
  void		level();

private:
  void			sendToAllPlayer(t_box);
  void			createEnemy();
  Pos			randomEnemyPos();

  IThread		*th;
  std::list<Player*>	_listPlayer;
  std::list<Entity*>	_listEntity;
  std::list<std::string> _listLevel;
  int			_fd;
  int			tick;
};

#endif
