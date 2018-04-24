//
// Created by Oleh SPEKA on 3/29/18.
//

#ifndef PRINTF_FT_PRINTF_H
#define PRINTF_FT_PRINTF_H
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
#include <string.h>

typedef struct s_mods{
    char    flags[3];
    int     width;
    int     precision;
    char    mod[2];
    char    id;
    char    *s;
}               t_modes;

int     ft_printf(const char *str, ...);
char    *make_value(t_modes mods, ssize_t arg);
char    *make_padding(t_modes mods, char *prefix, char *value);
char    *make_prefix(t_modes mods, ssize_t arg);
char    *create_and_fill(int count, char filler);
char    *append(char *source, char *to_append);
int     print_d(t_modes mods, ssize_t arg);
int     print_mod(t_modes mods, va_list ap);
ssize_t caster(t_modes mods, ssize_t arg);
int		ft_atoi(const char *str);
int     ft_count_num(int num);
char	*ft_itoa(ssize_t n);
void	ft_putstr(char const *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
int     print_o(t_modes mods, size_t arg);
size_t  caster_o(t_modes mods, size_t arg);
char    *make_prefix_o(t_modes mods, size_t arg);
char    *make_value_o(t_modes mods, size_t arg);
char    *append(char *source, char *to_append);
char    *create_and_fill(int count, char filler);
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
