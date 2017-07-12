/*
** my_printf.c for Project-Master in /home/rouill_a/Pool/PSU_2016_my_printf
** 
** Made by Alexis Rouillard
** Login   <alexis.rouillard@epitech.eu>
** 
** Started on  Thu Nov 10 10:46:43 2016 Alexis Rouillard
** Last update Wed May 10 19:46:25 2017 Alexis Rouillard
*/

#include "my.h"

int	dp_str(char *str)
{
  int	tmp;

  tmp = 0;
  while (*str)
    {
      if (*str >= 32 && *str < 127)
	tmp += my_putchar(*str);
      else
	{
	  tmp += 1;
	  my_putstr("\\");
	  if (*str < 8)
	    tmp += my_putstr("00");
	  else if (*str < 32)
	    tmp += my_putchar('0');
	  tmp += my_putunbr_base(*str, "01234567");
	}
      str++;
    }
  return (tmp);
}

int	put_base(unsigned long str, int i)
{
  int	len;

  len = 0;
  if (i == 5)
    len += my_putunbr_base(str, "0123456789ABCDEF");
  else if (i == 4)
    len += my_putunbr_base(str, "0123456789abcdef");
  else if (i == 3)
    len += my_putunbr_base(str, "0123456789");
  else if (i == 6)
    len += my_putunbr_base(str, "01");
  else if (i == 7)
    len += my_putunbr_base(str, "01234567");
  else if (i == 10)
    {
      len += my_putstr("0x");
      len += my_putunbr_base(str, "0123456789abcdef");
    }
  return (len);
}

int	flag_c(int i, void *av, char *flag, int j[3])
{
  int	tmp[6] = {0};

  while (j[1] > 0 && flag != NULL && *flag)
    {
      if (*flag == '+' && av >= 0)
	{
	  tmp[1] = 1;
	  tmp[5] += my_putchar(*flag);
	}
      else if (*flag == '0' || *flag == '-')
	my_intcpy(tmp, flag_c2(tmp, i, av, flag));
      else if (my_isnum(&*flag) && tmp[1] != 1 && tmp[4] != 1)
	{
	  tmp[0] = my_getnbr(&*flag);
	  while (tmp[0]-- > 0)
            tmp[5] += my_putchar(' ');
	}
      flag++;
    }
  if (tmp[3] != 1)
    tmp[5] += who(i, av, 0);
  return (tmp[5]);
}

int	who(int i, void *av, int tmp)
{
  int	(*ptr[14])();

  ptr[1] = &my_put_nbr;
  ptr[2] = &my_put_nbr;
  ptr[3] = &put_base;
  ptr[4] = &put_base;
  ptr[5] = &put_base;
  ptr[6] = &put_base;
  ptr[7] = &put_base;
  ptr[8] = &dp_str;
  ptr[9] = &my_putstr;
  ptr[10] = &put_base;
  if (i == 0)
    tmp += my_putstr((char *)&av);
  else if ((i >= 3 && i <= 7) || i == 10)
    tmp += ptr[i]((unsigned long)av, i);
  else
    tmp += ptr[i](av);
  if (i == 9 || i == 8)
    tmp -= 1;
  return (tmp);
}

int		my_printf(char *str, ...)
{
  va_list	av;
  int		i[3] = {0};
  char		*flags;

  va_start(av, str);
  flags = malloc(sizeof(char *) * my_strlen(str));
  while (*str)
    {
      if (*str == '%' && i[0] != 1)
	i[0] = 1;
      else if (!(*str == '%' && i[0] != 1) && !(i[0] == 1 && *str != '%'))
	{
	  i[2] += my_putchar(*str);
	  i[0] = 0;
	}
      else if (i[0] == 1 && *str != '%' && sflags(*str) != -1)
	{
	  i[2] += flag_c(sflags(*str), va_arg(av, void *), flags, i);
	  i[0] = -1;
	}
      else
	flags[i[1]++] = *str;
      str++;
    }
  return (free(flags), i[2]);
}
