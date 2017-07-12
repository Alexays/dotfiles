/*
** my_str_join.c for my_str_join in /home/rouill_a/Tek1/PSU/PSU_2016_minishell1
** 
** Made by Alexis Rouillard
** Login   <alexis.rouillard@epitech.eu>
** 
** Started on  Tue Jan 17 20:40:15 2017 Alexis Rouillard
** Last update Tue Jan 17 20:54:31 2017 Alexis Rouillard
*/

#include "my.h"

char	*my_str_join(char *src, char *dest, char sep)
{
  char	*tmp;
  int	i;
  int	j;

  j = 0;
  tmp = malloc(sizeof(char *) * (my_strlen(src) + my_strlen(dest) + 1));
  i = 0;
  while (src[i] != '\0')
    tmp[j++] = src[i++];
  tmp[j++] = sep;
  i = 0;
  while (dest[i] != '\0')
    tmp[j++] = dest[i++];
  tmp[j] = '\0';
  return (tmp);
}
