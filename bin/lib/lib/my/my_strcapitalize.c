/*
** my_strcapitalize.c for my_strcapitalize in /home/rouill_a/CPool_Day06
** 
** Made by Alexis Rouillard
** Login   <rouill_a@epitech.net>
** 
** Started on  Mon Oct 10 14:23:38 2016 Alexis Rouillard
** Last update Mon Oct 10 14:59:10 2016 Alexis Rouillard
*/

char	*my_strcapitalize(char *str)
{
  int	count;

  count = 0;
  while (str[count] != '\0')
    {
      if (str[count] >= 'a' && str[count] <= 'z')
	{
	  if (count == 0)
	    str[count] -= 32;
	  else if (str[count - 1 ] == ' ')
	    str[count] -= 32;
	}
      count++;
    }
  return (str);
}
