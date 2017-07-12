/*
** my_isneg.c for my_isneg in /home/rouill_a/CPool_Day03
** 
** Made by Alexis Rouillard
** Login   <rouill_a@epitech.net>
** 
** Started on  Wed Oct  5 10:16:24 2016 Alexis Rouillard
** Last update Mon Feb 20 20:30:19 2017 Alexis Rouillard
*/

#include "my.h"

int	my_isneg(int n)
{
  if (n >= 0)
    my_putchar('P');
  else
    if (!n)
    my_putchar('P');
  else
    my_putchar('N');
  return (0);
}
