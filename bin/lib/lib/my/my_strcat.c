/*
** my_strcat.c for Minishell1 in /home/bourm_m/Tek1/PSU_2016/PSU_2016_minishell1/src
**
** Made by BOURMAUD Maxime
** Login   <bourm_m@epitech.net>
**
** Started on  Sun Jan 22 18:26:09 2017 BOURMAUD Maxime
** Last update Wed Feb 22 19:51:41 2017 BOURM
*/

#include "my.h"

char    *my_strcat(char *dest, char *src)
{
  int   i;
  int   j;
  char	*tmp;

  tmp = malloc(sizeof(char *) * (my_strlen(dest) + my_strlen(src) + 1));
  j = -1;
  while (dest[++j] != '\0')
    tmp[j] = dest[j];
  i = -1;
  while (src[++i] != '\0')
    tmp[j + i] = src[i];
  tmp[j + i] = '\0';
  return (tmp);
}
