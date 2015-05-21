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
#include <elf.h>

#include "xfuncs.h"
#include "args.h"
#include "file.h"
#include "elf_headers.h"
#include "objdump_header.h"
#include "objdump_content.h"

/*
**  objdump - display information from object files
**
**     -f
**     --file-headers
**         Display summary information from the overall header of each of the
**         objfile files.
**
**     -s
**     --full-contents
**         Display the full contents of any sections requested.  By default
**         all non-empty sections are displayed.
*/

int project_main(t_flags *flags, t_file *file)
{
    t_elf_ehdr *ehdr;
    char const *ffrmt;

    if (elf_magic_check((ehdr = file->data), file->name) == -1)
        return (1);
    ffrmt = (EHV(ehdr)) ? "32-i386" : "64-x86-64";
    xprintf("\n%s:%5sfile format elf%s\n", file->name, "", ffrmt);
    if (args_flag_is_set(flags, 'f'))
        objdump_header(ehdr);
    xprintf("\n");
    if (args_flag_is_set(flags, 's'))
        objdump_content(ehdr);
    return (0);
}
