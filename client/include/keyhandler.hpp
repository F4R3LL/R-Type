//
// keyhandler.hpp for keyhand in /home/roby_t/rendu/rtype/client
// 
// Made by Tristan Roby
// Login   <roby_t@epitech.net>
// 
// Started on  Fri Dec 30 14:48:43 2016 Tristan Roby
// Last update Fri Dec 30 15:18:49 2016 Tristan Roby
//

#ifndef KEYHANDLER_HPP_
# define KEYHANDLER_HPP_

#include <SFML/Graphics.hpp>
#include "Talker.hpp"
class	Keyhandler
{
public:
  Keyhandler(Talker *);
  ~Keyhandler(){};
  void send();
  t_box recv();
  void catchKey(sf::RenderWindow *);
private:
  Talker		*talk;
  std::string		state = "NONE";
  int	     tab[7] = {
    sf::Keyboard::Key::Up, sf::Keyboard::Key::Down,
    sf::Keyboard::Key::Left, sf::Keyboard::Key::Right,
    sf::Keyboard::Key::Space, sf::Keyboard::Key::Escape, -42
  };
  std::string		inst[7] = {
    "UP", "DOWN", "LEFT", 
    "RIGHT", "FIRE", "ESCAPE", "NONE"
  };
  t_info		info;

  void			setInfo(bool);
  void			setInfo();
};

#endif
