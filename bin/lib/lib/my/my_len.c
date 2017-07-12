/*
** my_len.c for Project-Master in /home/rouill_a/Pool/PSU_2016_my_printf
** 
** Made by Alexis Rouillard
** Login   <alexis.rouillard@epitech.eu>
** 
** Started on  Thu Nov 17 22:33:35 2016 Alexis Rouillard
** Last update Wed Apr 26 12:37:43 2017 Alexis Rouillard
*/

int	my_nbrlen(long nbr)
{
  if (nbr < 10 && nbr >= 0)
    return (1);
  else if (nbr < 0 && nbr * -1 < 10)
    return (2);
  else
    return (1 + my_nbrlen(nbr / 10));
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (!str)
    return (0);
  while (str[i])
    i++;
  return (i);
}
