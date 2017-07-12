/*
** my_strupcase.c for my_strupcase in /home/rouill_a/CPool_Day06
** 
** Made by Alexis Rouillard
** Login   <rouill_a@epitech.net>
** 
** Started on  Mon Oct 10 14:01:51 2016 Alexis Rouillard
** Last update Tue Oct 11 14:04:38 2016 Alexis Rouillard
*/

char	*my_strupcase(char *str)
{
  int	count;

  count = 0;
  while (str[count] != '\0')
    {
      if (str[count] >= 'a' && str[count] <= 'z')
	{
	  str[count] -= 32;
	}
      count++;
    }
  return (str);
}
