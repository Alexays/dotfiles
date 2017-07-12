/*
** my_power_rec.c for my_power_rec in /home/rouill_a/delivery
** 
** Made by Alexis Rouillard
** Login   <rouill_a@epitech.net>
** 
** Started on  Fri Oct  7 09:51:36 2016 Alexis Rouillard
** Last update Tue Oct 11 13:01:46 2016 Alexis Rouillard
*/

int	my_power_rec(int nb, int p)
{
  unsigned long long	res;

  if (p >= 2147483647 || nb >= 2147483647)
    return (0);
  else if (p == 0)
    return (1);
  else
    {
      if (p > 1)
	{
	  res = my_power_rec(nb, (p - 1)) * nb;
	  if (res < 0)
	    return (0);
	  else
	    {
	      if (res >= 2147483647)
		return (0);
	      else
		return (res);
	    }
	}
      else
	return (nb);
    }
}
