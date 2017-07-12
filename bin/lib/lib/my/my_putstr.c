/*
** my_putstr.c for my_putstr in /home/rouill_a/CPool_Day04
** 
** Made by Alexis Rouillard
** Login   <rouill_a@epitech.net>
** 
** Started on  Thu Oct  6 09:27:29 2016 Alexis Rouillard
** Last update Wed Apr 12 10:18:40 2017 Alexis Rouillard
*/

#include "my.h"

int	my_putstr(char *str)
{
  int	i;

  i = -1;
  if (!str)
    return (0);
  while (str[++i])
    write(1, &str[i], 1);
  return (i);
}

int	my_puterr(char *str)
{
  int	i;

  i = -1;
  if (!str)
    return (0);
  while (str[++i])
    write(2, &str[i], 1);
  return (i);
}
