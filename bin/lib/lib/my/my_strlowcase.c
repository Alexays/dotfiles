/*
** my_strlowcase.c for my_strlowcase in /home/rouill_a/CPool_Day06
** 
** Made by Alexis Rouillard
** Login   <rouill_a@epitech.net>
** 
** Started on  Mon Oct 10 14:19:04 2016 Alexis Rouillard
** Last update Tue Oct 11 14:07:48 2016 Alexis Rouillard
*/

char	*my_strlowcase(char *str)
{
  int   count;

  count = 0;
  while (str[count] != '\0')
    {
      if (str[count] >= 'A' && str[count] <= 'Z')
	{
	  str[count] += 32;
	}
      count++;
    }
  return (str);
}
