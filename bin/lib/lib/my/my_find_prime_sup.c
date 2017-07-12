/*
** my_find_prime_sup.c for my_find_prime_sup in /home/rouill_a/CPool_Day05
** 
** Made by Alexis Rouillard
** Login   <rouill_a@epitech.net>
** 
** Started on  Sun Oct  9 20:22:10 2016 Alexis Rouillard
** Last update Mon Feb 20 20:29:49 2017 Alexis Rouillard
*/

#include "my.h"

int	my_find_prime_sup(int nb)
{
  int	x;

  x = nb;
  if (nb <= 1)
    return (0);
  else
    {
      while (x < 2147483647)
	{
	  if (my_is_prime(x))
	    return (x);
	  x++;
	}
      return (0);
    }
}
