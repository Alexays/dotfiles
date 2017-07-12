/*
** my_revstr.c for my_revstr in /home/rouill_a/CPool_Day06
** 
** Made by Alexis Rouillard
** Login   <rouill_a@epitech.net>
** 
** Started on  Mon Oct 10 09:41:53 2016 Alexis Rouillard
** Last update Tue May  9 21:05:49 2017 Alexis Rouillard
*/

#include "my.h"

char	*my_revstr(char *str)
{
  int	i;
  int	len;
  char	c;

  len = my_strlen(str);
  i = 0;
  while (i < len / 2)
    {
      c = *(str + i);
      *(str + i) = *(str + len - i - 1);
      *(str + len - i - 1) = c;
      ++i;
    }
  return (str);
}
