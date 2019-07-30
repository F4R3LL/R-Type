##
## Makefile for Makefile in /home/roby_t/perso/test/01_hello_SDL
## 
## Made by Tristan Roby
## Login   <roby_t@epitech.net>
## 
## Started on  Mon Jan 19 17:58:39 2015 Tristan Roby
## Last update Fri Dec 30 15:32:28 2016 Filipe Da Silva
##

SRC_CLIENT=	client/main.cpp \
		client/Displayer.cpp \
		client/Talker.cpp \
		client/Entity.cpp \
		client/keyhandler.cpp \

SRC_SERVER=	server/Socket.cpp \
		server/Serveur.cpp \
		server/Game.cpp \
		server/Entity.cpp \
		server/main.cpp \
		server/Player.cpp \
		server/Bullet.cpp \
		server/Pos.cpp \
		server/ThreadLib/Thread.cpp

OBJ=		$(SRC:.cpp=.o)

CXX=		g++

LDFLAGS=	-ldl -pthread -std=c++11

CXXFLAGS=  	-Wall -Wextra -Werror

NAME_CLIENT=	cli

NAME_SERVER= 	serv

all:		$(NAME_CLIENT) $(NAME_SERVER)
	g++ -Iserver/ -Iserver/Enemy/  server/Entity.cpp server/Enemy/Cruser.cpp -shared -fpic -o server/Enemy/Cruser.so -std=c++11
	g++ -Iserver/ -Iserver/Enemy/  server/Entity.cpp server/Enemy/Kamikaz.cpp -shared -fpic -o server/Enemy/Kamikaz.so -std=c++11
	g++ -Iserver/ -Iserver/Enemy/ server/Pos.cpp server/Entity.cpp server/Enemy/Boss.cpp -shared -fpic -o server/Enemy/Boss.so -std=c++11

$(NAME_CLIENT): 
	$(CXX) $(SRC_CLIENT) -o $(NAME_CLIENT) $(OBJ) -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -std=c++11

$(NAME_SERVER):	$(OBJ)	
	$(CXX) $(SRC_SERVER) $(LDFLAGS) -o $(NAME_SERVER) $(OBJ) $(CLAFGS)

clean:
	rm -f $(OBJ)
	rm -f server/*~
	rm -f client/*~	
	rm -f *~

fclean:	clean
	rm -f $(NAME_CLIENT)
	rm -f $(NAME_SERVER)

re:	fclean all

.PHONY:	all clean fclean re
