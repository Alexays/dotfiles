/*
** my_str_isnum.c for my_str_isnum in /home/rouill_a/CPool_Day06
** 
** Made by Alexis Rouillard
** Login   <rouill_a@epitech.net>
** 
** Started on  Mon Oct 10 15:28:17 2016 Alexis Rouillard
** Last update Mon Oct 10 15:30:18 2016 Alexis Rouillard
*/

int	my_str_isnum(char *str)
{
  int	count;
  int	val;

  count = 0;
  while (str[count] != '\0')
    {
      if (str[count] >= '0' && str[count] <= '9')
	val = 1;
      else
	val = 0;
      count++;
    }
  if (val == 1 || !val)
    return (1);
  else
    return (0);
}
