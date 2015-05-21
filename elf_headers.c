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
#include <string.h>
#include <elf.h>

#include "elf_headers.h"

int elf_magic_check(t_elf_ehdr *ehdr, char const *filename)
{
    if (strncmp((char *)ehdr->v32.e_ident, ELFMAG, SELFMAG))
    {
        fprintf(stderr, "%s: ELF magic number mismatch\n", filename);
        return (-1);
    }
    return (0);
}
