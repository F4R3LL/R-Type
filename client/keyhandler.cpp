//
// keyhandler.cpp for keyhandl in /home/roby_t/rendu/rtype/client
// 
// Made by Tristan Roby
// Login   <roby_t@epitech.net>
// 
// Started on  Fri Dec 30 14:52:01 2016 Tristan Roby
// Last update Fri Dec 30 15:15:10 2016 Tristan Roby
//

#include "include/keyhandler.hpp"

Keyhandler::Keyhandler(Talker *t)
{
  talk = t;
  info.up = false;
  info.down = false;
  info.left = false;
  info.right = false;
  info.fire = false;
  state = "NONE";
}

t_box	Keyhandler::recv()
{
  return talk->recv();
}

void	Keyhandler::catchKey(sf::RenderWindow *window)
{
  sf::Event e;
  while (window->pollEvent(e))
    {
      switch (e.type)
	{
	case sf::Event::KeyReleased:
	  for (int i = 0; tab[i] != -42; ++i)
	    if (tab[i] == e.key.code)
	      {
		state = inst[i];
		setInfo(false);
		talk->send(info);
	      }
	  state = "NONE";
	  break;
	case sf::Event::Closed:
	  window->close();
	  break;
	case sf::Event::KeyPressed:
	  int	i = 0;
	  if (e.key.code == sf::Keyboard::Escape)
	    window->close();
	  while (tab[i] != -42)
	    {
	      if (tab[i] == e.key.code && state != inst[i])
		{
		  state = inst[i];
		  setInfo(true);
		  talk->send(info);
		}
	      ++i;
	    }
	  break;
	}
    }
}

void	Keyhandler::send()
{
  talk->send(info);
}

void	Keyhandler::setInfo(bool set)
{
  if (state == "UP")
    info.up = set;
  if (state == "DOWN")
    info.down = set;
  if (state == "LEFT")
    info.left = set;
  if (state == "RIGHT")
    info.right = set;
  if (state == "FIRE")
    info.fire = set;
}
