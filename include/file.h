/*
** file.h for someproject in /home/guina_b/
** 
** Made by benoit guina
** Login   <guina_b@epitech.net>
** 
** Started on  Fri Jan 01 00:00:00 2010 benoit guina
** Last update Fri Jan 01 00:00:00 2010 benoit guina
*/

#ifndef H_FILE
#define H_FILE

typedef struct		s_file
{
    struct s_file	*next;
    char		*name;
    unsigned int	sz;
    void		*data;
} t_file;

int	file_load(t_file ***file, char *filename);
void	file_free(t_file *file);

#endif
