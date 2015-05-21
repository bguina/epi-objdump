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
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>

#include "xfuncs.h"
#include "file.h"

static int	file_map(t_file *file, int fd)
{
  struct stat	sb;

  if (fstat(fd, &sb) < 0)
    {
      fprintf(stderr, "could not map %s: stat failure: %s\n", file->name, strerror(errno));
      return (-1);
    }
  file->sz = sb.st_size;
  if (!S_ISREG(sb.st_mode))
    {
      fprintf(stderr, "could not map %s: not a regular file\n", file->name);
      return (-1);
    }
  file->sz = sb.st_size;
  errno = 0;
  if ((file->data = mmap(0, file->sz, PROT_READ, MAP_SHARED, fd, 0)) != MAP_FAILED)
    return (0);
  fprintf(stderr, "could not map %s: mmap failure: %s\n", file->name, strerror(errno));
  return (-1);
}

int	file_load(t_file ***file, char *filename)
{
  int	fd;

  if (!(**file = malloc(sizeof(t_file))))
    {
      fprintf(stderr, "could not load %s: malloc failure\n", filename);
      return (-1);
    }
  (**file)->next = 0;
  (**file)->name = filename;
  errno = 0;
  if ((fd = open(filename, O_RDONLY)) > 0)
    {
      if (file_map(**file, fd) == 0)
        {
	  xclose(fd, filename);
	  *file = &(**file)->next;
	  return (0);
        }
      xclose(fd, filename);
    }
  else
    fprintf(stderr, "could not load %s: open failure: %s\n", filename, strerror(errno));
  free(**file);
  **file = 0;
  return (1);
}

void	file_free(t_file *file)
{
  int	e;

  e = errno;
  if (munmap(file->data, file->sz) == -1)
    fprintf(stderr, "munmap error on %s: %s\n", file->name, strerror(errno));
  errno = e;
  free(file);
}
