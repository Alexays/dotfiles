/*
** my_sort_int_tab.c for my_sort_int_tab in /home/rouill_a/CPool_Day07/lib/my
** 
** Made by Alexis Rouillard
** Login   <rouill_a@epitech.net>
** 
** Started on  Tue Oct 11 18:24:29 2016 Alexis Rouillard
** Last update Mon Feb 20 20:55:54 2017 Alexis Rouillard
*/

#include "my.h"

int	my_sort_int_tab(int *tab, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      if (tab[i] > tab[i + 1])
	{
	  my_swap(&tab[i], &tab[i + 1]);
	}
      i = i + 1;
    }
  return (i);
}
