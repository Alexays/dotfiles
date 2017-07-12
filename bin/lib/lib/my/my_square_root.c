/*
** my_square_root.c for my_square_root in /home/rouill_a/CPool_Day05
** 
** Made by Alexis Rouillard
** Login   <rouill_a@epitech.net>
** 
** Started on  Sun Oct  9 20:09:59 2016 Alexis Rouillard
** Last update Sun Oct  9 21:13:09 2016 Alexis Rouillard
*/

int	my_square_root(int nb)
{
  int	res;

  res = 1;
  if (nb == 2147483647 || nb <= 0)
    return (0);
  while (res * res < nb)
    res += 1;
  if (res * res == nb)
    return (res);
  else
    return (0);
}
