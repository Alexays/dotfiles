/*
** my_is_prime.c for my_is_prime in /home/rouill_a/CPool_Day05
** 
** Made by Alexis Rouillard
** Login   <rouill_a@epitech.net>
** 
** Started on  Sun Oct  9 20:17:24 2016 Alexis Rouillard
** Last update Sun Oct  9 21:19:58 2016 Alexis Rouillard
*/

int	my_is_prime(int nb)
{
  int x;

  x = 2;
  if (nb <= 1)
    return (0);
  while (x < nb)
    {
      if (nb % x == 0)
	return (0);
      x++;
    }
  return (1);
}
