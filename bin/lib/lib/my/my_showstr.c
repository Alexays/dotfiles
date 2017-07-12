/*
** my_showstr.c for my_showstr in /home/rouill_a/CPool_Day06
** 
** Made by Alexis Rouillard
** Login   <rouill_a@epitech.net>
** 
** Started on  Mon Oct 10 17:57:10 2016 Alexis Rouillard
** Last update Mon Feb 20 21:01:13 2017 Alexis Rouillard
*/

#include "my.h"

int     my_putnbr_b2(int nbr, int n_base, char *base, int id)
{
  if (nbr < 0)
    {
      my_putchar('-');
      nbr *= -1;
    }
  else if (nbr == 0)
    {
      my_putchar(base[0]);
      return (0);
    }
  my_putnbr_b2(nbr / n_base, n_base, base, id++);
  if (base[nbr % n_base] >= 'A' && base[nbr % n_base] <= 'Z')
    my_putchar(base[nbr % n_base] - 32);
  else
    my_putchar(base[nbr % n_base] - 32);
}

int     my_putnbr_base2(int nbr, char *base)
{
  int   n_base;
  int   cnt;
  int   diff;

  n_base = 0;
  while (base[n_base] != '\0')
    n_base++;
  my_putnbr_b2(nbr, n_base, base, 1);
  return (0);
}

int	my_printstrl(char *str)
{
  int	count;

  count = 0;
  while (str[count] != '\0')
    {
      my_putchar(str[count]);
      count++;
    }
}

int	my_showstr(char *str)
{
  int	count;

  count = 0;
  while (str[count] != '\0')
    {
      if (str[count] >= 32 && str[count] <= 126)
	{
	  my_putchar(str[count]);
	}
      else
	{
	  my_putnbr_base(str[count], "0123456789ABCDEF");
	}
      count++;
    }
  return (0);
}
