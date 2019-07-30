//
// main.cpp for  in /home/dasilv_f/rendu/rtype/server
// 
// Made by Filipe Da Silva
// Login   <dasilv_f@epitech.net>
// 
// Started on  Mon Dec 19 15:34:10 2016 Filipe Da Silva
// Last update Mon Dec 26 12:45:49 2016 Tristan Roby
//

#include "Serveur.hpp"
#include "Game.hpp"


int main(int ac, char **av)
{
  if (ac != 2)
    {
      std::cout << "./Serveur [port]" << std::endl;
      return -1;
    }
  std::list<Serveur*> serv;
  serv.push_back(new Serveur(std::stol(av[1])));
  std::list<Game*> list;
  srand(42);
  while(2)
    {
      list.push_back(new Game(serv.back()->launch(), serv.back()->getFd()));
    }
  /*  while ()
    {
      if (newgame.started == true)
      }*/
  //newgame.startGame();
}
