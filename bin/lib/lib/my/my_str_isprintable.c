/*
** my_str_isprintable.c for my_str_isprintable in /home/rouill_a/CPool_Day06
** 
** Made by Alexis Rouillard
** Login   <rouill_a@epitech.net>
** 
** Started on  Mon Oct 10 15:36:42 2016 Alexis Rouillard
** Last update Mon Oct 10 15:42:09 2016 Alexis Rouillard
*/

int	my_str_isprintable(char *str)
{
  int	count;
  int	val;

  count = 0;
  while (str[count] != '\0')
    {
      if (str[count] >= 32 && str[count] <= 126 && val != 0)
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
