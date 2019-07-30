//
// Player.cpp for  in /home/dasilv_f/rendu/rtype/server
// 
// Made by Filipe Da Silva
// Login   <dasilv_f@epitech.net>
// 
// Started on  Mon Dec 19 16:09:00 2016 Filipe Da Silva
// Last update Fri Dec 30 15:25:37 2016 Filipe Da Silva
//

#include "Player.hpp"

Player::Player(struct sockaddr_in a, int po, int fd) : Entity() , _addr(a)
{
  _fd = fd;
  _pos = po;
  name = "player.png";// + _pos;
  cd = 20;
  /*  _dir.x = 7;
      _dir.y = 0;*/
  
  weapon.push_back(Pos(7, 1));
  weapon.push_back(Pos(7, 0));
  weapon.push_back(Pos(7, -1));
  hp = 100;
  friendly = true;
}

struct sockaddr_in Player::lookAddr()
{
  return _addr;
}

void	Player::send(t_box info)
{
  struct sockaddr_in a;
  a = _addr;
  socklen_t fromlen = sizeof a;
  sendto(_fd, &info, sizeof(t_box), 0, (struct sockaddr*)&a, fromlen);
}

void	Player::doAction()
{  
  if (_info.up)
    coor.y = coor.y - 5;
  if (_info.down)
    coor.y = coor.y + 5;
  if (_info.left)
    coor.x = coor.x - 5;
  if (_info.right)
    coor.x = coor.x + 5;
  firemode = _info.fire;

}

void	Player::recv(t_info info)
{
  _info = info;
}

