//
// Talker.hpp for  in /home/dasilv_f/rendu/rtype/client
// 
// Made by Filipe Da Silva
// Login   <dasilv_f@epitech.net>
// 
// Started on  Fri Dec 16 18:09:58 2016 Filipe Da Silva
// Last update Tue Dec 20 13:47:31 2016 Filipe Da Silva
//

#ifndef TALKER
# define TALKER

#include <iostream>
#include <netinet/in.h>
#include <netdb.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sendInfo.hpp"

class Talker
{
public:
  Talker(int, std::string);
  ~Talker();
  bool	init();
  void	launch();
  t_box	recv();
  void	send(t_info);
private:
  int			_port;
  int			_socket;
  bool			roomState = false;
  std::string		_ip;
  struct addrinfo	_serv, *_servinfo, *p;
};

#endif
