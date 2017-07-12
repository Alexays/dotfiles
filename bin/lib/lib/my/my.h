/*
** my.h for my in /home/rouill_a/CPool_Day09/include
** 
** Made by Alexis Rouillard
** Login   <rouill_a@epitech.net>
** 
** Started on  Thu Oct 13 09:11:51 2016 Alexis Rouillard
** Last update Wed May 10 19:45:29 2017 Alexis Rouillard
*/

#ifndef MY_H_
# define MY_H_

# ifndef READ_SIZE
#	define READ_SIZE (1000)
# endif /* !READ_SIZE */

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

void    *malloc_or_die(size_t size);
int	my_putchar(char c);
int	my_isneg(int nb);
int	my_put_nbr(int nb);
int	my_swap(int *a, int *b);
int	my_putstr(char *str);
int	my_error(char *str);
int	my_puterr(char *str);
int	my_strlen(char *str);
char	*get_next_line(const int fd);
int	my_nbrlen(long nbr);
int     my_isnum(char *str);
int     my_sort_int_tab(int *tab, int size);
char	**my_str_to_wordtab(char *str, char *sep);
int	my_getnbr(char *str);
int	my_power_rec(int nb, int power);
int	my_square_root(int nb);
int	my_is_prime(int nb);
int     *my_intcpy(int *dest, int *src);
int	my_find_prime_sup(int nb);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int n);
char	*my_revstr(char *str);
char	*my_strstr(char *str, char *to_find);
int	my_strcmp(char *s1, char *s2);
int	my_strscmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int n);
char	*my_strupcase(char *str);
char	*my_strlowcase(char *str);
char	*my_strcapitalize(char *str);
int	my_str_isalpha(char *str);
void    my_free(void *data);
char    *my_str_replace(char *org, char *src, char *dest);
void    my_tab_free(void **data);
int     is_in(char *str, int i);
int	my_str_isnum(char *str);
char    *my_tab_join(char **data, char sep);
int	my_str_islower(char *str);
int	my_str_isupper(char *str);
int	my_str_isprintable(char *str);
int	my_showstr(char *str);
int	my_showmem(char *str, int size);
char	*my_strcat(char *dest, char *src);
char	*my_strncat(char *dest, char *src, int nb);
int	my_putunbr_base(unsigned int nbr, char *base);
int     my_putnbr_base(int nbr, char *base);
int     who(int i, void *av, int tmp);
int     *flag_c2(int tmp[6], int i, char *av, char *flag);
int     sflags(char c);
char    *my_str_join(char *src, char *dest, char sep);
char	*get_next_line(const int fd);

#endif
