/*
** file.h for someproject in /home/guina_b/
** 
** Made by benoit guina
** Login   <guina_b@epitech.net>
** 
** Started on  Fri Jan 01 00:00:00 2010 benoit guina
** Last update Fri Jan 01 00:00:00 2010 benoit guina
*/

#ifndef H_ELF_HEADERS
#define H_ELF_HEADERS

typedef struct s_elf_ehdr
{
    union
    {
        Elf32_Ehdr v32;
        Elf64_Ehdr v64;
    };
} t_elf_ehdr;

typedef struct s_elf_shdr
{
    union
    {
        Elf32_Shdr v32;
        Elf64_Shdr v64;
    };
} t_elf_shdr;

typedef struct s_elf_sym
{
    union
    {
        Elf32_Sym v32;
        Elf64_Sym v64;
    };
} t_elf_sym;

#define EHV(e)      (((e)->v32.e_ident[EI_CLASS] == ELFCLASS32) ? 1 : 0)
#define EHI(e, c, h, i)   ((EHV(e)) ? (c)&(&(h)->v32)[i] : (c)&(&(h)->v64)[i])
#define EHIM(e, h, i, m) ((EHV(e)) ? (&(h)->v32)[i].m : (&(h)->v64)[i].m)
#define EHM(e, h, m) (EHIM(e, h, 0, m))

int elf_magic_check(t_elf_ehdr *ehdr, char const *filename);

#endif
