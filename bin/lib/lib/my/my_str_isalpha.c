/*
** my_str_isalpha.c for my_str_isalpha in /home/rouill_a/CPool_Day06
** 
** Made by Alexis Rouillard
** Login   <rouill_a@epitech.net>
** 
** Started on  Mon Oct 10 15:25:31 2016 Alexis Rouillard
** Last update Mon Oct 10 15:42:49 2016 Alexis Rouillard
*/

int	my_str_isalpha(char *str)
{
  int	count;
  int	val;

  count = 0;
  while (str[count] != '\0')
    {
      if (str[count] >= 'a' && str[count] <= 'z' && val != 0)
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
