/*
** my_swap.c for my_swap in /home/rouill_a/CPool_Day04
** 
** Made by Alexis Rouillard
** Login   <rouill_a@epitech.net>
** 
** Started on  Thu Oct  6 09:08:01 2016 Alexis Rouillard
** Last update Thu Oct  6 09:26:39 2016 Alexis Rouillard
*/

int	my_swap(int *a, int *b)
{
  int	tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
  return (0);
}
