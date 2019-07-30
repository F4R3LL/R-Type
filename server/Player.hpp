#ifndef PLAYER
# define PLAYER

#include "Entity.hpp"

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "Bullet.hpp"

typedef struct s_info
{
  bool		up;
  bool		down;
  bool		left;
  bool		right;
  bool		fire;
}t_info;

class Player : public Entity
{
public:
  Player(struct sockaddr_in a, int po, int fd);
  ~Player(){};
  

  struct sockaddr_in lookAddr();
  virtual void doAction();
  int		pos()
  {return _pos;}
  void send(t_box);
  void recv(t_info);
private:
  int			_fd;
  int			_pos;
  struct sockaddr_in	_addr;
  t_info		_info;

//  std::string		state;
  //  std::string		name;
};

#endif
