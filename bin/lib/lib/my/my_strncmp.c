/*
** my_strncmp.c for my_strncmp in /home/rouill_a/CPool_Day06
** 
** Made by Alexis Rouillard
** Login   <rouill_a@epitech.net>
** 
** Started on  Mon Oct 10 13:34:25 2016 Alexis Rouillard
** Last update Tue Oct 11 14:04:19 2016 Alexis Rouillard
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	x;

  x = 0;
  while (s1[x] == s2[x] && x < n)
    x++;
  if (x == n || s1[x] == '\0' && s2[x] == '\0')
    return (0);
  else if (s1[x] > s2[x])
    return (1);
  else
    return (-1);
}
