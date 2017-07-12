/*
** my_put_nbr.c for my_put_nbr in /home/rouill_a/CPool_Day03
** 
** Made by Alexis Rouillard
** Login   <rouill_a@epitech.net>
** 
** Started on  Wed Oct  5 14:09:07 2016 Alexis Rouillard
** Last update Mon Feb 20 20:33:29 2017 Alexis Rouillard
*/

#include "my.h"

int		my_put_unbr(unsigned long nb, int i)
{
  unsigned long	c;
  int		x;

  c = 1;
  x = 0;
  while (c <= (nb / 10))
    c = c * 10;
  while (c >= 1)
    {
      if (i == 0)
	my_putchar(nb / c + '0');
      nb = nb % c;
      c = c / 10;
      x++;
    }
  return (x);
}
