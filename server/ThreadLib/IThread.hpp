//
// IThread.hpp for  in /home/dasilv_f/rendu/rtype
// 
// Made by Filipe Da Silva
// Login   <dasilv_f@epitech.net>
// 
// Started on  Wed Dec 21 18:45:51 2016 Filipe Da Silva
// Last update Wed Dec 21 18:45:59 2016 Filipe Da Silva
//

#ifndef __ITHREAD_HPP__
# define __ITHREAD_HPP__

class	IThread {
public:
  typedef enum	status_e {
    WAIT,
    ALIVE,
    DEAD
  } status_t;
  virtual		~IThread(void) {};
  virtual status_t	getStatus(void) = 0;
  virtual void		start(void) = 0;
  virtual void		join(void **) = 0;
};

#endif // !__ITHREAD_HPP__ //
