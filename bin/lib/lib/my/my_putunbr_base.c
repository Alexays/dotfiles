/*
** my_putnbr_base.c for my_putnbr_base in /home/rouill_a/CPool_Day06
** 
** Made by Alexis Rouillard
** Login   <rouill_a@epitech.net>
** 
** Started on  Mon Oct 10 15:47:03 2016 Alexis Rouillard
** Last update Mon Feb 20 20:33:39 2017 Alexis Rouillard
*/

#include "my.h"

int     my_putunbr_b(unsigned int nbr, int n_base, char *base, unsigned int id)
{
  int	i;

  i = 0;
  if (nbr < 0)
    {
      i += my_putchar('-');
      nbr *= -1;
    }
  else if (nbr == 0)
    {
      if (id > 1)
	i+= my_putchar(base[0]);
      return (0);
    }
  i += my_putunbr_b(nbr / n_base, n_base, base, id++);
  i += my_putchar(base[nbr % n_base]);
  return (i);
}

int		my_putunbr_base(unsigned int nbr, char *base)
{
  unsigned int	n_base;
  unsigned int	cnt;
  unsigned int	diff;

  n_base = 0;
  while (base[n_base] != '\0')
    n_base++;
  return (my_putunbr_b(nbr, n_base, base, 1));
}
