//
// Thread.cpp for  in /home/dasilv_f/rendu/rtype
// 
// Made by Filipe Da Silva
// Login   <dasilv_f@epitech.net>
// 
// Started on  Wed Dec 21 18:46:05 2016 Filipe Da Silva
// Last update Wed Dec 21 18:46:06 2016 Filipe Da Silva
//

#include <string>
#include <iostream>
#include <pthread.h>
#include <signal.h>
#include "Thread.hpp"
//#include "ThreadExceptions.hpp"

Thread::Thread(void* (*fct)(void*), void* param) {
  _routine = fct;
  _param = param;
  _status = WAIT;
}

Thread::~Thread() {
}

Thread::status_t	Thread::getStatus(void) {
  return _status;
}

void			Thread::start(void) {
  if (pthread_create(&_th, NULL, _routine, _param) != 0){
    std::cout << "Thread Start Error." << std::endl;
  }
  //throw ThreadCreate;
  _status = ALIVE;
}

void			Thread::join(void **ret) {
  if (getStatus() != Thread::ALIVE)
    return;
  if (pthread_join(_th, ret)){
    std::cout << "Thread join Error." << std::endl;
  }
  // throw ThreadJoin;
  _status = DEAD;
}
