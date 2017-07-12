##
## Makefile for d10 in /home/rouill_a/CPool_Day10
##
## Made by Alexis Rouillard
## Login   <rouill_a@epitech.net>
##
## Started on  Fri Oct 14 09:05:16 2016 Alexis Rouillard
## Last update Wed Apr 19 11:23:15 2017 Alexis Rouillard
##

SRC	=	my_getnbr_base.c	\
		my_find_prime_sup.c     \
		my_getnbr.c		\
		my_isneg.c		\
		my_is_prime.c		\
		my_power_rec.c		\
		get_next_line.c		\
		my_putchar.c		\
		my_putnbr_base.c	\
		my_putunbr_base.c	\
		my_put_nbr.c		\
		my_put_unbr.c		\
		my_putstr.c		\
		my_revstr.c		\
		my_showmem.c		\
		my_showstr.c		\
		my_isnum.c		\
		my_sort_int_tab.c	\
		my_square_root.c	\
		my_strcapitalize.c	\
		my_strcmp.c		\
		my_strcpy.c		\
		my_str_isalpha.c	\
		my_str_isnum.c		\
		my_str_islower.c	\
		my_str_isupper.c	\
		my_str_isprintable.c	\
		my_str_isupper.c	\
		my_len.c		\
		my_strlowcase.c		\
		my_strncat.c		\
		my_strncmp.c		\
		my_strncpy.c		\
		my_strstr.c		\
		my_strupcase.c		\
		my_swap.c		\
		my_printf.c		\
		my_printf2.c		\
		my_str_to_wordtab.c	\
		my_strcat.c		\
		my_str_join.c		\
		get_next_line.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

NAME1	=	my.h

CFLAGS	=	-Iinclude/

all:	$(NAME)

clean:
	@rm -f $(OBJ)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib libmy.a

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.c.o:
	@$(CC) -c $< -o $@
	@echo -e "[ \e[32mOK\e[39m ] Compiling" $<

auteur:
	echo $(USER) > auteur
