#include "Socket.hpp"

Socket::Socket()
{
}

#include <string.h>	
#include <unistd.h>
#include <fcntl.h>
class test
{
public:
  test() {}

  struct sockaddr_in s;
  char	ip[25];
  int port;
  char msg[200];
};

/*void *get_in_addr(struct sockaddr *sa)
{
  if (sa->sa_family == AF_INET)
    return &(((struct sockaddr_in*)sa)->sin_addr);
  return &(((struct sockaddr_in6*)sa)->sin6_addr);

  }*/

bool	Socket::check(struct sockaddr_in test)
{
  // for (std::list<Player*>::iterator it = _listPlayer.begin(); it != _listPlayer.end() ; it++)
  //   {
  //     if (test == (it).front()->lookAddr)
  // 	return true;
  //   }
  for (auto i : _listPlayer)
    {
      if (test.sin_port == i->lookAddr().sin_port)
	{
	  std::cout << i->pos();
	  return true;
	}
    }
  return false;
 
}

void	Socket::sendToAllPlayer(std::string & msg)
{
  socklen_t fromlen = sizeof (struct sockaddr_in);
  int		in = 0;
  struct sockaddr_in tmp;
  std::string finalmsg;

  for (auto i : _listPlayer)
    {
      tmp = i->lookAddr();
      finalmsg = msg + " " + std::to_string(++in);
      if (sendto(_listenSocketUdp, finalmsg.c_str(), finalmsg.length(), 0, (struct sockaddr*)&tmp, fromlen) == -1)
	std::cout << "soucis" << std::endl;
      std::cout << finalmsg << std::endl;
    }
}

void	Socket::deletePlayer(struct sockaddr_in test)
{
  std::list<Player*> tmp;

  if (_listPlayer.size() == 0)
    return ;
  for (int i = 0; i <= _listPlayer.size(); ++i)
  {
    if (test.sin_port == _listPlayer.front()->lookAddr().sin_port)
      {
	_listPlayer.pop_front();
      }
    else
      {
	tmp.push_back(_listPlayer.front());
	_listPlayer.pop_front();    
      }
  }
  std::cout << "test "<< tmp.size() << " " << _listPlayer.size() << std::endl;
  _listPlayer = tmp;
}

std::list<Player*>	Socket::launch()
{
  int	i, res, serv;
  char buff[4096];
  socklen_t fromlen, p;
  test t;
  struct sockaddr_in  a, b;
  int count;
  char s[INET6_ADDRSTRLEN];
  std::string msg("coucou");
  count = 0;
  std::list<Player*> forroom;
  t_info info;
  for (;;)
    {
      sockaddr from = { 0 };
      socklen_t addrlen = sizeof(sockaddr);
      fromlen = sizeof a;
      i = -1;
      /*if (recvfrom(_listenSocketUdp, buff, 40, 0, (struct sockaddr*)&a, &fromlen) > 0)
	{*/
      if (recvfrom(_listenSocketUdp, &info, sizeof(t_info), 0, (struct sockaddr*)&a, &fromlen) > 0)
	{
	  for (auto i : _listPlayer)
	    if (i->lookAddr().sin_port == a.sin_port)
	      i->recv(info);
	  if (std::string(buff) == "ESCAPE")
	    deletePlayer(a);
	  else if (!check(a))
	    {
	      Player *nplayer = new Player(a, _listPlayer.size() + 1, _listenSocketUdp);
	      forroom.push_back(nplayer);
	      //sendToAllPlayer(msg);
	      _listPlayer.push_back(forroom.back());
	    }
	  if (forroom.size() == 2)
	    break;
	  //	  std::cout << buff << std::endl;
	}
      //      std::cout << "coucou" << std::endl;
      //sleep(1);
    }
  msg = "Start";
  return forroom;
  //  sendToAllPlayer(msg);
}

int Socket::getFd()
{
  return _listenSocketUdp;
}

std::list<Player*> Socket::getListPlayer()
{
  return _listPlayer;
}

bool Socket::init(const std::string & listenHost, int port)
{
  int i;
  bzero((char *) &(this->_servAddr), sizeof(this->_servAddr));
  this->_servAddr.sin_family = AF_INET;
  this->_servAddr.sin_addr.s_addr = INADDR_ANY;
  this->_servAddr.sin_port = htons(port);

  this->_listenSocketUdp = socket(AF_INET, SOCK_DGRAM, 0);
  if (this->_listenSocketUdp <= 0)
    {
      std::cerr << "socket failed with error (UDP)" << std::endl;
      return false;
    }
  i = bind( this->_listenSocketUdp, (struct sockaddr *) &this->_servAddr, sizeof(this->_servAddr));
  if (i < 0)
    {
      std::cerr << "bind failed with error (UDP): " << std::endl;
      close(this->_listenSocketUdp);
      return false;
    }
  return true;
}
