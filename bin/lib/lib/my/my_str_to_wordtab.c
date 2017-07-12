/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/rouill_a/Tek1/PSU/PSU_2016_minishell1
** 
** Made by Alexis Rouillard
** Login   <alexis.rouillard@epitech.eu>
** 
** Started on  Tue Jan 17 19:31:23 2017 Alexis Rouillard
** Last update Mon Mar 13 19:21:28 2017 Alexis Rouillard
*/

#include "my.h"

int	check_word(char c, char *sep)
{
  int	i;

  i = -1;
  while (sep[++i])
    if (c == sep[i])
      return (0);
  return (1);
}

int	count_word(char *str, char *sep)
{
  int	i;
  int	j;
  int	word;

  i = -1;
  word = 1;
  while (str[++i])
    {
      j = -1;
      while (sep[++j])
	if (sep[j] == str[i])
	  {
	    word++;
	    break;
	  }
    }
  return (word);
}

char            **my_str_to_wordtab(char *str, char *sep)
{
  char	**tab;
  int	nbr;
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  nbr = count_word(str, sep);
  if ((tab = malloc(sizeof(char *) * (nbr + 1))) == NULL)
    return (NULL);
  while (str[i] && str[i] != '\0')
    {
      if ((tab[j] = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
	return (NULL);
      while (check_word(str[i], sep) == 0 && str[i])
	i++;
      k = 0;
      while (check_word(str[i], sep) == 1 && str[i])
	tab[j][k++] = str[i++];
      tab[j][k] = '\0';
      j++;
    }
  tab[j] = NULL;
  return (tab);
}
