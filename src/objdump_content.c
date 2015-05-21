/*
** file.c for someproject in /home/guina_b/
** 
** Made by benoit guina
** Login   <guina_b@epitech.net>
** 
** Started on  Fri Jan 01 00:00:00 2010 benoit guina
** Last update Fri Jan 01 00:00:00 2010 benoit guina
*/

#include <string.h>
#include <ctype.h>
#include <elf.h>

#include "xfuncs.h"
#include "elf_headers.h"
#include "elf_sloop.h"
#include "objdump_content.h"

static void sdump_word(const char *cur, const char *end, int hex)
{
    int i;
    int j;
    char c;

    i = -1;
    while (++i < 4 && cur < end)
    {
        j = -1;
        while (++j < 4 && cur + j < end)
        {
            c = cur[j];
            xprintf((hex) ? "%02hhx" : "%c", (hex || isprint(c)) ? c : '.');
        }
        while (j++ < 4)
            xprintf("%*s", (hex) ? 2 : 0, "");
        xprintf("%s", (hex) ? " " : "");
        cur += 4;
    }
    while (i++ < 4)
        xprintf("%*s", (hex) ? 9 : 0, "");
}

static int sdump(t_elf_shdr *shdr, char *sname, void *ehdr, void *n)
{
    char *beg;
    char *cur;
    char *end;

    if (((int *)n)[0]++ >= ((int *)n)[1])
        return (1);
    if (!strncmp(".rel.", sname, 5))
        return (0);
    beg = ehdr + EHM((t_elf_ehdr *)ehdr, shdr, sh_offset);
    cur = beg;
    end = beg + EHM((t_elf_ehdr *)ehdr, shdr, sh_size);
    if (cur < end)
        xprintf("Contents of section %s:\n", sname);
    while (cur < end)
    {
        xprintf(" %04x ", cur - beg);
        sdump_word(cur, end, 1);
        xprintf(" ");
        sdump_word(cur, end, 0);
        xprintf("\n");
        cur += 0x10;
    }
    return (0);
}

void objdump_content(t_elf_ehdr *ehdr)
{
    int n[2];

    n[0] = 0;
    n[1] = EHM(ehdr, ehdr, e_shnum) - 3;
    elf_sloop(ehdr, &sdump, ehdr, n);
}
