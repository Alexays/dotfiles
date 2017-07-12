/*
** my_isnum.c for Project-Master in /home/rouill_a/Pool/PSU_2016_my_printf
** 
** Made by Alexis Rouillard
** Login   <alexis.rouillard@epitech.eu>
** 
** Started on  Sat Nov 19 09:31:56 2016 Alexis Rouillard
** Last update Fri Mar 10 12:53:46 2017 Alexis Rouillard
*/

#include "my.h"

int     my_isnum(char *str)
{
  int   i;

  i = 0;
  while (*str)
    {
      if (!(*str >= '0' && *str <= '9'))
        i = 1;
      str++;
    }
  if (i == 1)
    return (0);
  else
    return (1);
}
