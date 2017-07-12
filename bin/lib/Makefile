##
## Makefile for BASE in /home/rouill_a
## 
## Made by Alexis Rouillard
## Login   <alexis.rouillard@epitech.eu>
## 
## Started on  Tue Jan  3 10:15:39 2017 Alexis Rouillard
## Last update Sat Jun  3 23:29:47 2017 Alexis Rouillard
##

NAME	=	a.out

CC	=	gcc

CFLAGS	=	-W -Wall -Wextra -Wshadow -Wpedantic

INCLUDE =	-I./include/

LFLAGS	=	-L./lib/my

LIBS	=	-lmy

SRC	=	$(shell find src/ -name "*.c" -type f)

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		$(MAKE) -C ./lib/my/
		$(CC) $(CFLAGS) $(INCLUDE) -o $(NAME) $(OBJ) $(LFLAGS) $(LIBS)

.c.o:
		$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
		$(RM) $(OBJ)
		$(MAKE) clean -C ./lib/my/

fclean:		clean
		$(RM) $(NAME)
		$(MAKE) fclean -C ./lib/my/

re:		fclean all

dbg: 		CFLAGS += -g
dbg: 		re

fast: 		CFLAGS += -Ofast
fast: 		re

.PHONY:		all clean fclean re dbg fast
