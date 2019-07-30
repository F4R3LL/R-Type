#ifndef SERVEUR
# define SERVEUR

#include <iostream>
#include <list>
#include "Socket.hpp"
#include "Player.hpp"
#include <stdlib.h>

class Serveur
{
public:
  Serveur(int port);
  ~Serveur(){};
  std::list<Player*> launch();
  int		getFd();
private:
  Socket *_s;
};

#endif
