#ifndef SOCKET
# define SOCKET

//#include "Serveur.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include <list>

class Socket
{
public:
  Socket();
  ~Socket(){}
  bool			init(const std::string & listen, int port);
  std::list<Player*>			launch();
  std::list<Player*>		getListPlayer();
  int			getFd();
private:

  bool			check(struct sockaddr_in);
  void			sendToAllPlayer(std::string &);
  void			deletePlayer(struct sockaddr_in);
  
  int				_listenSocketTcp;
  int				_listenSocketUdp;
  std::list<int>		_clientsList;
  
  std::list<Player*>		_listPlayer;
  //std::map<int, ISocket *>	_clientsSocksMap;
  //std::map<std::string, ISocket *>	_clientsSocksUdpMap;
  fd_set			_readFd;
  //InterpretPackage*		_interPckg;
  struct sockaddr_in		_servAddr;
  int							_portUdpPeer;
};

#endif
