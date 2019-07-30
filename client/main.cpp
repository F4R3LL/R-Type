//
// main.cpp for main in /home/roby_t/rendu/rtype/client
// 
// Made by Tristan Roby
// Login   <roby_t@epitech.net>
// 
// Started on  Fri Dec 16 18:12:38 2016 Tristan Roby
// Last update Fri Dec 30 15:27:12 2016 Tristan Roby
//

#include "include/Displayer.hpp"

int main(int ac, char **av)
{
  Talker *talk;
  if (ac < 2)
    {
      std::cout << av[0] << " [port] [adress:default=localhost]" << std::endl;
      return -1;
    }
  if (ac == 2)
    talk = new Talker(std::stol(av[1]) , "127.0.0.1");
  else
    talk = new Talker(std::stol(av[1]) , av[2]);
  if (talk->init() == true)
    {
      Displayer display(talk);
      display.mainLoop();
    }
}

