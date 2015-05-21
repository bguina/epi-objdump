/*
** file.h for someproject in /home/guina_b/
** 
** Made by benoit guina
** Login   <guina_b@epitech.net>
** 
** Started on  Fri Jan 01 00:00:00 2010 benoit guina
** Last update Fri Jan 01 00:00:00 2010 benoit guina
*/

#ifndef H_OBJDUMP_HEADER
#define H_OBJDUMP_HEADER

#ifdef OBJDUMP_HEADER_IMPORT_INTERNAL

struct s_value_string_pair
{
    int const v;
    char const *const s;
};

typedef struct s_value_string_pair t_arch;
typedef struct s_value_string_pair t_bfd_flag;

#define VALUE_STRING_PAIR(x) {x, #x}

#endif

void objdump_header(t_elf_ehdr *ehdr);

#endif
