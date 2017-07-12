/*
** get_next_line.c for get_next_line in /home/rouill_a/Tek1/CPE/CPE_2016_getnextline
** 
** Made by Alexis Rouillard
** Login   <alexis.rouillard@epitech.eu>
** 
** Started on  Tue Jan  3 10:35:48 2017 Alexis Rouillard
** Last update Mon Feb 13 14:08:51 2017 Alexis Rouillard
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int		get_buff(const int fd, char *str)
{
  static int	i = 0;
  static int	lo = READ_SIZE;
  static char	buff[READ_SIZE];

  if (i == 0 || i >= lo)
    i = 0;
  if (i == 0 && (lo = read(fd, buff, READ_SIZE)) == -1)
    return (0);
  if (lo != 0 && buff[i] == '\n')
    *str = '\0';
  else if (lo != 0)
    *str = buff[i];
  else
    {
      *str = '\0';
      return (0);
    }
  i++;
  return (lo);
}

char		*do_realloc(char *str, int rs)
{
  char		*dest;
  char		*src;
  char		*tmp;
  int		i;

  i = 0;
  if (str == NULL)
    {
      if (!(str = malloc(rs)))
	return (NULL);
      return (str);
    }
  if (!(tmp = malloc(rs + 1)))
    return (NULL);
  dest = tmp;
  src = str;
  while (i++ < rs)
    *(dest++) = *(src++);
  free(str);
  return (tmp);
}

char		*get_next_line(const int fd)
{
  char		*str;
  int		i;
  int		rd;

  i = 0;
  if (fd < 0 || READ_SIZE < 1)
    return (NULL);
  if (!(str = malloc(sizeof(char *) * READ_SIZE + 1)))
      return (NULL);
  if ((rd = get_buff(fd, &str[0])) == 0)
    return (NULL);
  while (str[i++])
    {
      if (i % READ_SIZE == 0 && (str = do_realloc(str, READ_SIZE + i)) == NULL)
	return (NULL);
      get_buff(fd, &str[i]);
    }
  return (str);
}
