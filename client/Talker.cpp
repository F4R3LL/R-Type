//
// Talker.cpp for  in /home/dasilv_f/rendu/rtype/client
// 
// Made by Filipe Da Silva
// Login   <dasilv_f@epitech.net>
// 
// Started on  Fri Dec 16 16:54:28 2016 Filipe Da Silva
// Last update Tue Dec 27 14:12:02 2016 valentin1 fernandes
//

#include "include/Talker.hpp"
#include "include/sendInfo.hpp"

class test
{
public:
  test(){}
  
  struct sockaddr_in ss;
  char	ip[25];
  int	port;
  char	msg[200];
};

Talker::Talker(int port, std::string ip) : _port(port), _ip(ip)
{
}

Talker::~Talker()
{
  std::cout << "Sa passe ici " << std::endl;
  sendto(_socket, "ESCAPE", 9, 0, p->ai_addr, p->ai_addrlen);
}

t_box	Talker::recv()
{
  t_box box;
  socklen_t m = sizeof(_serv);
  
  box.index = -1;
  recvfrom(_socket, &box, sizeof(t_box), 0,(struct sockaddr *)&_serv , &m);
  return box;
}

void	Talker::send(t_info info)
{
  
  fcntl(_socket, F_SETFL, O_NONBLOCK);
  sendto(_socket, &info, sizeof(t_info), 0, p->ai_addr, p->ai_addrlen);
}


#include <fcntl.h>

bool	Talker::init()
{
  memset(&_serv, 0, sizeof _serv);
  _serv.ai_family = AF_INET;
  _serv.ai_socktype = SOCK_DGRAM;


  if ((getaddrinfo(_ip.c_str(), std::to_string(_port).c_str(), &_serv, &_servinfo)) != 0)
    return false;
  
  
  for (p = _servinfo; p != NULL; p = p->ai_next)
    {
      if ((_socket = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1)
	{
	  std::cout << "talker : socket\n";
	  continue;
	}
      break;
    }
  if (p == NULL)
    return false;
  return true;
}

void	Talker::launch()
{
  test t;

  char buffer[256];
  socklen_t m = sizeof(_serv);
  t_box		*box;
  memcpy(t.ip, "127.0.0.1", 10);
  std::cout<<"\ngoing to send\n";
  std::cout<<"\npls enter the mssg to be sent\n";

  while (1)
    {
      fgets(t.msg,256,stdin);
      sendto(_socket, &t, sizeof(t),0, p->ai_addr, p->ai_addrlen);
      memset(buffer, 0 , 256);
      while (1)
	{
	  memset(buffer, 0, 256);
	  recvfrom(_socket, &box, sizeof(t_box), 0,(struct sockaddr *)&t.ss,&m);
	  std::cout << buffer << std::endl;
	}
    }
}
