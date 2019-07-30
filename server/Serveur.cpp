#include "Serveur.hpp"
#include <string>

Serveur::Serveur(int port)
{
  //Socket _s(this);
  _s = new Socket();

  if (_s->init("", port) == true)
    std::cout << "coucou" << std::endl;
 
}

int	Serveur::getFd()
{
  return _s->getFd();
}

std::list<Player*>	Serveur::launch()
{
  /*_s->launch();
    return _s->getListPlayer();*/
  return _s->launch();
}
