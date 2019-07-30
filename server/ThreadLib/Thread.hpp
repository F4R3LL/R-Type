//
// Thread.hpp for  in /home/dasilv_f/rendu/rtype
// 
// Made by Filipe Da Silva
// Login   <dasilv_f@epitech.net>
// 
// Started on  Wed Dec 21 18:46:12 2016 Filipe Da Silva
// Last update Wed Dec 21 18:46:12 2016 Filipe Da Silva
//

#ifndef __THREAD_HPP__
# define __THREAD_HPP__

#include "IThread.hpp"

class	Thread : public IThread {
public:
  Thread(void *(func)(void*), void*);
  ~Thread(void);

  virtual status_t	getStatus(void);
  virtual void		start(void);
  virtual void		join(void**);

protected:
  void*			(*_routine)(void*);
  void*			_param;
  status_t		_status;
  pthread_t		_th;
};

#endif // !__THREAD_HPP__ //
