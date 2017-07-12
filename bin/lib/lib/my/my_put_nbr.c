/*
** my_put_nbr.c for my_put_nbr in /home/rouill_a/CPool_Day03
** 
** Made by Alexis Rouillard
** Login   <rouill_a@epitech.net>
** 
** Started on  Wed Oct  5 14:09:07 2016 Alexis Rouillard
** Last update Mon Feb 20 20:54:01 2017 Alexis Rouillard
*/

#include "my.h"

int	my_put_nbr(int nb)
{
  int	c;

  c = 1;
  if (nb == -2147483647 - 1)
    {
      my_putchar('-');
      my_putchar('2');
      nb = 147483648;
    }
  if (nb < 0)
    {
      nb = nb * -1;
      my_putchar('-');
    }
  while (c <= (nb / 10))
      c = c * 10;
  while (c >= 1)
    {
      my_putchar(nb / c + '0');
      nb = nb % c;
      c = c / 10;
    }
  return (0);
}
