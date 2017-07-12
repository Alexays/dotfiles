/*
** my.h for my in /home/rouill_a/CPool_Day09/include
** 
** Made by Alexis Rouillard
** Login   <rouill_a@epitech.net>
** 
** Started on  Thu Oct 13 09:11:51 2016 Alexis Rouillard
** Last update Thu Apr 13 11:23:10 2017 Alexis Rouillard
*/

#ifndef MY_H_
# define MY_H_

# ifndef READ_SIZE
#	define READ_SIZE (1000)
# endif /* !READ_SIZE */

# include <stdlib.h>

#define UNUSED __attribute__ ((unused))

/********************
**  LIB-C Function **
********************/

void    *malloc_or_die(size_t size);
int	my_putchar(char c);
int	my_isneg(int nb);
int	my_put_nbr(int nb);
int     my_put_unbr(unsigned int nb, int i);
int	my_swap(int *a, int *b);
int	my_putstr(char *str);
int	my_puterr(char *str);
int	my_strlen(char *str);
int	my_nbrlen(long nbr);
int	my_getnbr(char *str);
int	my_isnum(char *str);
void	my_sort_int_tab(int *tab, int size);
int	my_power_rec(int nb, int power);
int	my_square_root(int nb);
int	my_is_prime(int nombre);
int	my_find_prime_sup(int nb);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int n);
char	*my_revstr(char *str);
char	*my_strstr(char *str, char *to_find);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int n);
char	*my_strupcase(char *str);
char	*my_strlowcase(char *str);
char	*my_strcapitalize(char *str);
int	my_str_isalpha(char *str);
int	my_str_isnum(char *str);
int	my_str_islower(char *str);
int	my_str_isupper(char *str);
int	my_str_isprintable(char *str);
int	my_showstr(char *str);
int	my_showmem(char *str, int size);
char	*my_strcat(char *dest, char *src);
char	*my_strncat(char *dest, char *src, int nb);
int     my_expr(char **str, int s1);
int     my_putnbr_base(int nbr, char *base);
int     my_putunbr_base(unsigned int nbr, char *base);
int     sflags(char c);
int     *flag_c2(int *tmp, int i, void *av, char *flag);
int     my_printf(char *str, ...);
char    *my_str_join(char *src, char *dest, char sep);
char    **my_str_to_wordtab(char *str, char *sep);
char    *get_next_line(const int fd);

#endif /* !MY_H_ */
