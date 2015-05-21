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
#include <stdio.h>

#include "flags.h"
#include "elf_headers.h"
#include "elf_sloop.h"
#define OBJDUMP_HEADER_IMPORT_INTERNAL
#include "objdump_header.h"

static char const *get_arch(t_elf_ehdr *ehdr)
{
    static t_arch archs[] = {
        {EM_386, "i386"},
        {EM_X86_64, "i386:x86-64"},
    };
    unsigned int i;

    i = -1;
    while (++i < sizeof(archs) / sizeof(t_arch))
        if (EHM(ehdr, ehdr, e_machine) == archs[i].v)
            return (archs[i].s);
    return ("unknown");
}

static int get_sflags(t_elf_shdr *shdr, char *sname, void *ehdr, void *flags)
{
    (void)sname;
    if (EHM((t_elf_ehdr *)ehdr, shdr, sh_type) == SHT_SYMTAB)
        *(int *)flags |= HAS_SYMS;
    return (0);
}

static int get_flags(t_elf_ehdr *ehdr)
{
    int type;
    int flags;

    type = EHM(ehdr, ehdr, e_type);
  flags = 0;
  if (type == ET_EXEC)
    flags |= EXEC_P;
  else if (type == ET_DYN)
    flags |= DYNAMIC;
  else
    flags |= HAS_RELOC;
  if (EHM(ehdr, ehdr, e_phnum) > 0)
    flags |= D_PAGED;
    elf_sloop(ehdr, &get_sflags, ehdr, &flags);
    return (flags);
} 

void objdump_header(t_elf_ehdr *ehdr)
{
    static const t_bfd_flag bfd_flags[] = {
        VALUE_STRING_PAIR(HAS_RELOC),
        VALUE_STRING_PAIR(EXEC_P),
        VALUE_STRING_PAIR(HAS_SYMS),
        VALUE_STRING_PAIR(DYNAMIC),
        VALUE_STRING_PAIR(WP_TEXT),
        VALUE_STRING_PAIR(D_PAGED)
    };
    int flags;
  char const *comma;
  unsigned int i;

  printf("architecture: %s, ", get_arch(ehdr));
  printf("flags 0x%08x:\n", (flags = get_flags(ehdr)));
  comma = "";
  i = -1;
  while (++i < sizeof(bfd_flags) / sizeof(t_bfd_flag))
      if ((flags & bfd_flags[i].v))
      {
          printf("%s%s", comma, bfd_flags[i].s);
          comma = ", ";
      }
  printf("\nstart address 0x%0*x\n", EHV(ehdr) ? 8 : 16, (int)EHM(ehdr, ehdr, e_entry));
}

