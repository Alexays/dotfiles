/*
** my_strcpy.c for my_strcpy in /home/rouill_a/CPool_Day06
** 
** Made by Alexis Rouillard
** Login   <rouill_a@epitech.net>
** 
** Started on  Mon Oct 10 09:05:49 2016 Alexis Rouillard
** Last update Fri Mar 10 13:04:31 2017 Alexis Rouillard
*/

char	*my_strcpy(char *dest, char *src)
{
  int count;

  count = 0;
  while (src[count])
    {
      dest[count] = src[count];
      count++;
    }
  dest[count] = '\0';
  return (dest);
}

int	*my_intcpy(int *dest, int *src)
{
  int count;

  count = 0;
  while (src[count])
    {
      dest[count] = src[count];
      count++;
    }
  dest[count] = '\0';
  return (dest);
}
