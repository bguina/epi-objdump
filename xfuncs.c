/*
** file.c for someproject in /home/guina_b/
** 
** Made by benoit guina
** Login   <guina_b@epitech.net>
** 
** Started on  Fri Jan 01 00:00:00 2010 benoit guina
** Last update Fri Jan 01 00:00:00 2010 benoit guina
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#include "xfuncs.h"

void xprintf(const char *s, ...)
{
    va_list ap;

    va_start(ap, s);
    if (vprintf(s, ap) < 0)
    {
        if (fprintf(stderr, "printf: stdout output error\n") < 0)
        {
        }
        exit(1);
    }
    va_end(ap);
}

void	xclose(int fd, char *name)
{
  int	e;

  e = errno;
  if (close(fd))
  {
    if (fprintf(stderr, "close error on %s: %s\n", name, strerror(errno)) < 0)
    {
    }
  }
  errno = e;
}
