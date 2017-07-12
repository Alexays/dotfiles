/*
** my_showmem.c for my_showmem in /home/rouill_a/CPool_Day06
** 
** Made by Alexis Rouillard
** Login   <rouill_a@epitech.net>
** 
** Started on  Tue Oct 11 15:16:27 2016 Alexis Rouillard
** Last update Mon Feb 20 20:58:58 2017 Alexis Rouillard
*/

#include "my.h"

int	my_showmem(char *str, int size)
{
  int	count;
  char	tmp[15];
  int	r_count;

  count = 0;
  r_count = 0;
  while (count < size)
    {
      if (count % 16 == 0 && r_count == 0)
	{
	  my_putstr(tmp);
	  if (count != 0)
	    my_putchar('\n');
	  my_putnbr_base(str[count], "0123456789ABCDEF");
	  write(1, ": ", 2);
	}
      tmp[r_count] = (str[count] != '0') ? str[count]  : '\0';
      if (count % 2 == 0 && r_count++)
	my_putchar(' ');
      my_putnbr_base(str[count], "0123456789ABCDEF");
      count++;
    }
  my_putstr(tmp);
  my_putchar('\n');
  return (0);
}
