/*
** my_strcmp.c for my_strcmp in /home/rouill_a/CPool_Day06
** 
** Made by Alexis Rouillard
** Login   <rouill_a@epitech.net>
** 
** Started on  Mon Oct 10 13:29:21 2016 Alexis Rouillard
** Last update Sat Apr 29 19:43:57 2017 Alexis Rouillard
*/

int     my_strcmp(char *s1, char *s2)
{
  int   i;

  i = 0;
  if (!s1 || !s2)
    return (1);
  while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
    i++;
  return (s1[i] - s2[i]);
}

int	my_strscmp(char *s1, char *s2)
{
  int	x;

  x = 0;
  while (s1[x] != 0)
    {
      if (s1[x] < s2[x])
	return (-1);
      if (s1[x] > s2[x])
	return (1);
      if (s1[x] > s2[x])
	return (1);
      x++;
    }
  return (0);
}
