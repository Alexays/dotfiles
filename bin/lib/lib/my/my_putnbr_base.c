/*
** my_putnbr_base.c for my_putnbr_base in /home/rouill_a/CPool_Day06
** 
** Made by Alexis Rouillard
** Login   <rouill_a@epitech.net>
** 
** Started on  Mon Oct 10 15:47:03 2016 Alexis Rouillard
** Last update Mon Feb 20 20:52:15 2017 Alexis Rouillard
*/

#include "my.h"

int	my_putnbr_b(int nbr, int n_base, char *base, int id)
{
  if (nbr < 0)
    {
      my_putchar('-');
      nbr *= -1;
    }
  else if (nbr == 0)
    {
      if (id > 1)
	my_putchar(base[0]);
      return (0);
    }
  my_putnbr_b(nbr / n_base, n_base, base, id++);
  my_putchar(base[nbr % n_base]);
}

int	my_putnbr_base(int nbr, char *base)
{
  int	n_base;
  int	cnt;
  int	diff;

  n_base = 0;
  while (base[n_base] != '\0')
    n_base++;
  my_putnbr_b(nbr, n_base, base, 1);
  return (0);
}
