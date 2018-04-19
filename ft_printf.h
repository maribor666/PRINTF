//
// Created by Oleh SPEKA on 3/29/18.
//

#ifndef PRINTF_FT_PRINTF_H
#define PRINTF_FT_PRINTF_H
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"


typedef struct s_mods{
    char    flags[3];
    int     width;
    int     precision;
    char    mod[2];
    char    id;
    char    *s;
}               t_modes;


char    *make_value(t_modes mods, int arg);
char    *make_padding(t_modes mods, int arg, char *prefix, char *value);
char    *make_prefix(t_modes mods, int arg);
char    *create_and_fill(int count, char filler);
char    *append(char *source, char *to_append);
int     print_d(t_modes mods, int arg);
int     print_mod(t_modes mods, va_list ap);
//void    print_fillers(char filler, int count);
//void    print_d(t_modes mods, int arg);
//void    print_d_simple(t_modes mods, int arg);
//void    print_d_minus(t_modes mods, int arg);
//void    print_d_space(t_modes mods, int arg);
//void    print_d_plus(t_modes mods, int arg);
//void    print_d_zero(t_modes mods, int arg);
//void    print_d_plus_minus(t_modes mods, int arg);
//void    print_d_minus_space(t_modes mods, int arg);
//void    print_d_plus_zero(t_modes mods, int arg);
#endif //PRINTF_FT_PRINTF_H
