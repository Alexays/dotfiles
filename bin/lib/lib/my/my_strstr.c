/*
** my_strstr.c for my_strstr in /home/rouill_a/CPool_Day06
** 
** Made by Alexis Rouillard
** Login   <rouill_a@epitech.net>
** 
** Started on  Mon Oct 10 11:11:58 2016 Alexis Rouillard
** Last update Tue Oct 11 13:51:29 2016 Alexis Rouillard
*/

char	*my_strstr(char *str, char *to_find)
{
  int	count;
  int	cnt_find;
  int	cnt2;
  int	verify;

  count = 0;
  cnt_find = 0;
  cnt2 = 0;
  while (to_find[cnt_find] != '\0')
    cnt_find++;
  while (str[count] != '\0')
    {
      if (str[count] == to_find[cnt2])
	{
	  if (cnt2 == 0)
	    verify = count;
	  cnt2++;
	}
      count++;
    }
  if (cnt2 == cnt_find)
    return (str = &str[verify]);
  else
    return (0);
}
