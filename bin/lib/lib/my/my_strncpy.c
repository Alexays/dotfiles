/*
** my_strncpy.c for my_strncpy in /home/rouill_a/CPool_Day06
** 
** Made by Alexis Rouillard
** Login   <rouill_a@epitech.net>
** 
** Started on  Mon Oct 10 09:32:14 2016 Alexis Rouillard
** Last update Tue Oct 11 13:11:15 2016 Alexis Rouillard
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	count;

  count = 0;
  while (count < n)
    {
      dest[count] = src[count];
      count++;
    }
  dest[count] = '\0';
  return (dest);
}
