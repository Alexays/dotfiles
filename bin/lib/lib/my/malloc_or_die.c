/*
** malloc_or_die.c for malloc_or_die in /home/rouill_a/bin/lib
** 
** Made by Alexis Rouillard
** Login   <alexis.rouillard@epitech.eu>
** 
** Started on  Sat Mar 11 11:08:43 2017 Alexis Rouillard
** Last update Sat Mar 11 11:09:28 2017 Alexis Rouillard
*/

#include "my.h"

void	*malloc_or_die(size_t size)
{
  void	*ptr;

  ptr = malloc(size);
  if (ptr == NULL)
    {
      my_puterr("Malloc() has failed\n");
      exit(84);
    }
  return (ptr);
}
