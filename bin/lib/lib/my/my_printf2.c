/*
** my_printf2.c for Project-Master in /home/rouill_a/Pool/PSU_2016_my_printf
** 
** Made by Alexis Rouillard
** Login   <alexis.rouillard@epitech.eu>
** 
** Started on  Fri Nov 18 00:08:55 2016 Alexis Rouillard
** Last update Wed May 10 19:45:10 2017 Alexis Rouillard
*/

#include "my.h"

int	sflags(char c)
{
  int	x;
  char	*flags;

  x = 0;
  flags = "ciduxXboSsp";
  while (*flags)
    {
      if (c == *flags)
	return (x);
      x++;
      flags++;
    }
  return (-1);
}

int	*flag_c2(int tmp[6], int i, char *av, char *flag)
{
  int	j;

  j = -1;
  tmp[4] = 1;
  tmp[0] = my_getnbr(&(*(flag + 1))) - my_nbrlen(my_getnbr(av));
  if (my_getnbr(av) < 0)
    {
      tmp[2] = 1;
      while (av[++j])
      	av[j] *= -1;
      tmp[5] += my_putchar('-');
    }
  tmp[0] = tmp[1] == 1 ? tmp[0] - 1 : tmp[0];
  if (*flag == '-')
    {
      tmp[3] = 1;
      tmp[5] += who(i, (void *)av, 0);
    }
  while (tmp[0]-- > 0)
    tmp[5] += my_putchar(*flag == '0' ? *flag : ' ');
  return (tmp);
}
