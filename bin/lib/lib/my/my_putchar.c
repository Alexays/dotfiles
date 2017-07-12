/*
** my_putchar.c for my_putchar in /home/rouill_a/CPool_Day03
** 
** Made by Alexis Rouillard
** Login   <rouill_a@epitech.net>
** 
** Started on  Wed Oct  5 10:33:11 2016 Alexis Rouillard
** Last update Mon Feb 20 20:30:39 2017 Alexis Rouillard
*/

#include "my.h"

int    my_putchar(char c)
{
  write(1, &c, 1);
  return (1);
}
