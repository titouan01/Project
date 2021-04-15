##
## EPITECH PROJECT, 2021
## cpp_rush3
## File description:
## Makefile
##

SRC_MAIN =	./main.cpp							\
			./modules/CpuInfo.cpp 				\
			./modules/CpuPourcent.cpp 			\
			./modules/Datetime.cpp 				\
			./modules/FileSystem.cpp 			\
			./modules/HostnameModule.cpp 		\
			./modules/Memory.cpp 				\
			./modules/Network.cpp 				\
			./modules/Sensors.cpp 				\
			./modules/Systeminfo.cpp 			\
			./modules/Task.cpp 					\
			./modules/Uptime.cpp 				\
			./display/ncurse/ncurse.cpp 		\
			./display/sfml/disp_mod_func.cpp 	\
			./display/sfml/disp_obj.cpp 		\
			./display/sfml/DisplaySfml.cpp 		\

CC =	g++

OBJ =	$(SRC_MAIN:.c=.o)

NAME =		MyGKrellm

CFLAGS = -Wall -Wextra -Werror -lncurses -lsfml-graphics -lsfml-window -lsfml-system

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

clean:
	rm -rf *.gc*
	rm -rf tests/*.gc*

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re