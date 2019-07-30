//
// Game.cpp for  in /home/dasilv_f/rendu/rtype/server
// 
// Made by Filipe Da Silva
// Login   <dasilv_f@epitech.net>
// 
// Started on  Mon Dec 19 13:32:05 2016 Filipe Da Silva
// Last update Fri Dec 30 15:25:01 2016 Filipe Da Silva
//

#include "Game.hpp"

Game::Game(std::list<Player*> players, int fd) : _listPlayer(players), _fd(fd) 
{
  level();
  tick = 0;
  th = new Thread(Game::ThreadStart, reinterpret_cast<void*>(&(*this)));
  th->start();
}

Pos Game::randomEnemyPos()
{
  int	x;
  int	y;

  x = 1350;
  y = rand() % 720;
  return (Pos(x, y));
}

void	Game::createEnemy()
{
  void	*lib;
  Entity *(*ptr)(const Pos &);

  _listLevel.pop_front();
  std::string path("server/Enemy/" + _listLevel.front());
  _listLevel.pop_front();
  lib = dlopen(path.c_str(), RTLD_LAZY);
  if (lib == NULL)
    {
      std::cout << "lib = " << path << std::endl;
      return;
    }
  ptr = reinterpret_cast<Entity *(*)(const Pos &)>(dlsym(lib, "getClass"));
  if (ptr == NULL)
    {
      std::cout << "ptr = NULL" << std::endl;
      return;
    }
  _listEntity.push_back(ptr(Pos(1350, std::stol(_listLevel.front()))));
  _listLevel.pop_front();
  /*  for (auto i : _listLevel)
      std::cout << i << std::endl;*/
}

void	*Game::ThreadStart(void *arg)
{
  Game *game = reinterpret_cast<Game*>(arg);

  game->startGame();
  return NULL;
}

void	Game::sendToAllPlayer(t_box box)
{
  for ( auto i : _listPlayer)
    i->send(box);
}

void	Game::startGame()
{
  char	buff[4096];
  struct sockaddr_in a;
  socklen_t fromlen = sizeof (struct sockaddr_in);
  t_info	info;
  int		i = 0;

  fcntl(_fd, F_SETFL, O_NONBLOCK);
  for (auto i : _listPlayer)
    {
      sendToAllPlayer(i->creatBox());
      _listEntity.push_back(reinterpret_cast<Entity*>(i));
    }
  while (1)
    {
      usleep(15625);
      //memset(buff, 0, 4096);
      /*if (recvfrom(_fd, &info, sizeof(t_info), 0, (struct sockaddr*)&a, &fromlen) > 0)
	{
	  for (auto i : _listPlayer)
	    if (i->lookAddr().sin_port == a.sin_port)
	      i->recv(info);
	}*/
      if (_listLevel.size() != 0 && tick == std::stol(_listLevel.front()))
	createEnemy();
      std::list<Entity*> e;
      /*for (auto i : _listPlayer)
	{
	  i->doAction();
	  e = i->fire();
	  if (e.size() != 0)
	    _listEntity.splice(_listEntity.begin(), e);
	    }*/
      for (auto i : _listEntity)
	{
	  i->doAction();
	  e = i->fire();
	  if (e.size() != 0)
	    _listEntity.splice(_listEntity.begin(), e);
	}
      for (auto i : _listEntity)
	for (auto j : _listEntity)
	  i->collision(j);

      for (auto i : _listEntity)
	i->isAlive();
      /*      for (auto i : _listPlayer)
	i->isAlive();

      for (auto i : _listPlayer)
      sendToAllPlayer(i->creatBox());*/
      for (auto i : _listEntity)
	sendToAllPlayer(i->creatBox());
      std::list<Entity*> tmp;
      if (_listEntity.size() != 0)
	{
	  for (auto i : _listEntity)
	    {
	      if (i->isAlive() == true)
		tmp.push_front(i);
	      else
		delete i;
	    }
	  _listEntity = tmp;
	}
      ++tick;
    }
}

void	Game::level()
{
  std::fstream is;
  std::string line;
  
  is.open("server/Level/level1");
  if (is.is_open())
    {
      while (getline(is, line))
	_listLevel.push_back(line);
      is.close();
    }
}
