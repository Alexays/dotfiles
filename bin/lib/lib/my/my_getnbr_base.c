/*
** my_getnbr_base.c for my_getnbr_base in /home/rouill_a/CPool_Day06
** 
** Made by Alexis Rouillard
** Login   <rouill_a@epitech.net>
** 
** Started on  Mon Oct 10 16:56:04 2016 Alexis Rouillard
** Last update Thu Dec  8 22:17:38 2016 Alexis Rouillard
*/

int	calc_len_str(char *str)
{
  int	c_str;

  c_str = 0;
  while (str[c_str] != '\0')
    c_str++;
  return (c_str - 1);
}

int	calc_len(char *base)
{
  int c_base;

  c_base = 0;
  while (base[c_base] != '\0')
    c_base++;
  return (c_base);
}

int	my_getnbr_base(char *str, char *base)
{
  int	n_base;
  int	nbr;
  int	x;
  int	s;
  int	mul;

  nbr = 0;
  mul = 1;
  if (str[0] == '-')
    {
      s *= -1;
      str = &str[1];
    }
  x = calc_len_str(str);
  while (x >= 0)
    {
      n_base = 0;
      while (str[x] != base[n_base])
	n_base += 1;
      nbr += n_base * mul;
      mul *= calc_len(base);
      x--;
    }
  return (s == -1 ? nbr * s : nbr);
}
