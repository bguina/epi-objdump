/*
** file.c for someproject in /home/guina_b/
** 
** Made by benoit guina
** Login   <guina_b@epitech.net>
** 
** Started on  Fri Jan 01 00:00:00 2010 benoit guina
** Last update Fri Jan 01 00:00:00 2010 benoit guina
*/

#include "args.h"
#include "file.h"

int	project_main(t_flags *flags, t_file *file);

int		main(int ac, char **av)
{
  int		r;
  int		exit_code;
  t_flags	*flags;
  t_file	*files;
  t_file	**cur;
  t_file	*next;

  exit_code = -1;
  files = 0;
  cur = &files;
  if ((flags = args_parse(ac, av, (int (*)())&file_load, &cur)))
    {
      exit_code = 0;
      while (files)
        {
	  if ((r = project_main(flags, files)) && exit_code == 0)
            exit_code = r;
	  next = files->next;
	  file_free(files);
	  files = next;
        }
      args_flags_free(flags);
    }
  return (exit_code);
}
