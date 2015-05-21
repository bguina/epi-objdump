/*
** file.c for someproject in /home/guina_b/
** 
** Made by benoit guina
** Login   <guina_b@epitech.net>
** 
** Started on  Fri Jan 01 00:00:00 2010 benoit guina
** Last update Fri Jan 01 00:00:00 2010 benoit guina
*/

#include <elf.h>

#include "elf_headers.h"
#include "elf_sloop.h"

int elf_sloop(t_elf_ehdr *ehdr, int (*f)(t_elf_shdr *, char *, void *, void *), void *a, void *b)
{
    t_elf_shdr *shdr;
    char *snames;
    int i;

    shdr = (void *)ehdr + EHM(ehdr, ehdr, e_shoff);
    snames = (void *)ehdr + EHIM(ehdr, shdr, EHM(ehdr, ehdr, e_shstrndx), sh_offset);
    i = -1;
    while (++i < EHM(ehdr, ehdr, e_shnum))
    {
        if (f(EHI(ehdr, t_elf_shdr *, shdr, i), snames + EHIM(ehdr, shdr, i, sh_name), a, b) == -1)
            return (-1);
    }
    return (0);
}
