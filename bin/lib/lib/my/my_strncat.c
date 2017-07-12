/*
** my_strncat.c for my_strncat in /home/rouill_a/CPool_Day07
** 
** Made by Alexis Rouillard
** Login   <rouill_a@epitech.net>
** 
** Started on  Tue Oct 11 11:10:06 2016 Alexis Rouillard
** Last update Mon Feb 20 20:53:40 2017 Alexis Rouillard
*/

#include "my.h"

char	*my_strncat(char *dest, char *src, int nb)
{
  int	count_r;
  int	count_d;
  char	*tmp;

  tmp = malloc(sizeof(char *) * my_strlen(dest) + my_strlen(src));
  count_r = 0;
  count_d = 0;
  while (count_r < nb)
    {
      tmp[count_r] = src[count_r];
      count_r++;
    }
  while (count_d < nb)
    {
      tmp[count_r + count_d] = dest[count_d];
      count_d++;
    }
  tmp[count_r + count_d] = '\0';
  return (tmp);
}
