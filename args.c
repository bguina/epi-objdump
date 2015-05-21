/*
** file.c for someproject in /home/guina_b/
** 
** Made by benoit guina
** Login   <guina_b@epitech.net>
** 
** Started on  Fri Jan 01 00:00:00 2010 benoit guina
** Last update Fri Jan 01 00:00:00 2010 benoit guina
*/

#include <stdlib.h>
#include <string.h>

#include "args.h"

t_flags		*args_parse(int ac, char **av, int (*f)(void *, char*), void *arg)
{
  t_flags	*r;
  int		i;

  if (!(r = malloc(sizeof(t_flags))))
    return (0);
  bzero(r, sizeof(t_flags));
  i = 0;
  while (++i < ac)
    if (!args_flag_is_set(r, '-') && *av[i] == '-')
      while (!args_flag_is_set(r, '-') && *++av[i])
	args_flag_set(r, *av[i]);
    else if (f(arg, av[i]) == -1)
      {
	args_flags_free(r);
	return (0);
      }
  return (r);
}

void	args_flag_set(t_flags *flags, char c)
{
    flags->bytes[c / 8] |= (1 << (c % 8));
}

int	args_flag_is_set(t_flags *flags, char c)
{
    return (flags->bytes[c / 8] & (1 << (c % 8)));
}

void	args_flags_free(t_flags *flags)
{
    free(flags);
}
