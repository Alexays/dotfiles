/*
** my_getnbr.c for my_getnbr in /home/rouill_a/CPool_Day04
** 
** Made by Alexis Rouillard
** Login   <rouill_a@epitech.net>
** 
** Started on  Thu Oct  6 15:39:56 2016 Alexis Rouillard
** Last update Fri Mar 10 12:50:20 2017 Alexis Rouillard
*/

#include "my.h"

int	my_getnbr(char *str)
{
  int	i;
  int	sign;
  int	offset;

  i = 0;
  sign = 0;
  offset = 0;
  while (str[i] == '+' || str[i] <= '-')
    sign = str[i++];
  offset = i;
  str = &str[offset];
  i = 0;
  while (*str && *str >= '0' && *str <= '9')
    i = i * 10 + *str++ - '0';
  if (sign == '-')
    i = i * -1;
  return (i);
}
