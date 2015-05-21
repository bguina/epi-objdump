/*
** file.h for someproject in /home/guina_b/
** 
** Made by benoit guina
** Login   <guina_b@epitech.net>
** 
** Started on  Fri Jan 01 00:00:00 2010 benoit guina
** Last update Fri Jan 01 00:00:00 2010 benoit guina
*/

#ifndef H_ARGS
#define H_ARGS

typedef struct	s_flags
{
    char	bytes[32];
}		t_flags;

t_flags	*args_parse(int ac, char **av, int (*f)(void *, char*), void *arg);
void	args_flag_set(t_flags *flags, char c);
int	args_flag_is_set(t_flags *flags, char c);
void	args_flags_free(t_flags *flags);

#endif
