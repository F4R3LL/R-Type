//
// sendInfo.hpp for  in /home/fernan_m/rendu/rtype/client/include
// 
// Made by valentin1 fernandes
// Login   <fernan_m@epitech.net>
// 
// Started on  Mon Dec 19 16:08:14 2016 valentin1 fernandes
// Last update Mon Dec 26 12:25:34 2016 Filipe Da Silva
//

#ifndef SENDINFO_HPP_
# define SENDINFO_HPP_

typedef struct s_box
{
  float		x;
  float		y;
  char		name[25];
  int		index;
  bool		alive;
}		t_box;

typedef struct s_info
{
  bool		up;
  bool		down;
  bool		left;
  bool		right;
  bool		fire;
}t_info;


#endif

