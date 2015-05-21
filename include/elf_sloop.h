/*
** file.h for someproject in /home/guina_b/
** 
** Made by benoit guina
** Login   <guina_b@epitech.net>
** 
** Started on  Fri Jan 01 00:00:00 2010 benoit guina
** Last update Fri Jan 01 00:00:00 2010 benoit guina
*/

#ifndef H_ELF_SLOOP
#define H_ELF_SLOOP

int elf_sloop(t_elf_ehdr *ehdr, int (*f)(t_elf_shdr *, char *, void *, void *), void *a, void *b);

#endif
