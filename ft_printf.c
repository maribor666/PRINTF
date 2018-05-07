#include "ft_printf.h"

t_modes write_mods(const char *s, t_modes mods)
{
    int i;
    int j;
    int is_dot;

    is_dot = 0;
    j = 0;
    i = 0;
    while(is_mods(s[i]) == 1 && s[i] != '\0')
        i++;
    if (s[i] != '\0')
        mods.id = s[i];
    while (j < i)
    {
        if (is_flag(s[j]) == 1)
        {
            if (s[j - 1] == '.' && s[j] == '0')
                j++;
            else
            {
                mods.flags = append_char(mods.flags, s[j]);
                j++;
            }
        }
        if (ft_isdigit(s[j]) == 1 && is_dot == 0 && s[j] != '0')
        {
            mods.width = ft_atoi(&(s[j]));
            while (ft_isdigit(s[j]) == 1)
                j++;
        }
        if (s[j] == '.')
        {
            is_dot = 1;
            j++;
            if (s[j] == '0' || ft_isdigit(s[j]) == 0)
                mods.precision = 0;
        }
        if (ft_isdigit(s[j]) == 1 && is_dot == 1 && s[j] != '0')
        {
            mods.precision = ft_atoi(&(s[j]));
            while (ft_isdigit(s[j]) == 1)
                j++;
        }
        if (is_mod(s[j]) == 1)
        {
            mods.mod = append_char(mods.mod, s[j]);
            j++;
        }
    }
    mods.mod = rewrite_mod(mods.mod);
    mods.s = (char*)(s + i + 1);
    return (mods);
}

char    *rewrite_mod(char  *mod)
{
    char *res;


    if (ft_strlen(mod) <= 1)
        return (mod);
    res = ft_strdup("");
    if (mod[ft_strlen(mod) - 1] == 'z' || mod[ft_strlen(mod) - 1] == 'j')
    {
        res = append_char(res, mod[ft_strlen(mod) - 1]);
        free(mod);
        return (res);
    }
    else
    {
        if (mod[ft_strlen(mod) - 1] == mod[ft_strlen(mod) - 2])
        {
            res = append(res, &(mod[ft_strlen(mod) - 2]));
            free(mod);
        }
        else
        {
            res = append(res, &(mod[ft_strlen(mod) - 1]));
            free(mod);
        }
        return (res);
    }
}

int     is_mods(char c)
{
    if (ft_isdigit(c) == 1 || is_flag(c) == 1
        || is_mod(c) == 1 || c == '.')
        return (1);
    else
        return (0);
}

int     is_mod(char c)
{
    if (c == 'h' || c == 'l' || c == 'j' || c == 'z')
        return (1);
    else
        return (0);
}

int     is_flag(char c)
{
    if (c == '+' || c == '-' || c == '0'
        || c == '#' || c == ' ')
        return (1);
    else
        return (0);
}

int     print_mod(t_modes mods, va_list ap)
{
    if (mods.id == 'd' || mods.id == 'i' || mods.id == 'D')
        return (print_d(mods, va_arg(ap, ssize_t)));
    if (mods.id == 'o' || mods.id == 'O')
        return (print_o(mods, va_arg(ap, size_t)));
    if (mods.id == 'x' || mods.id == 'X')
        return (print_x(mods, va_arg(ap, size_t)));
    if (mods.id == 'u' || mods.id == 'U')
        return (print_u(mods, va_arg(ap, size_t)));
    if (mods.id == 'c' || mods.id == 'C')
        return (print_c(mods, va_arg(ap, int)));
    if (mods.id == 's' || mods.id == 'S')
        return (print_s(mods, va_arg(ap, wchar_t*)));
    if (mods.id == 'p')
        return(print_p(mods, va_arg(ap, size_t)));
    if (mods.id == '%')
        return (print_percent(mods));
    if (ft_strchr("sSpdDioOuUxXcC%", mods.id) == NULL)
        return (print_c(mods, mods.id));
    return (0);
}

t_modes free_modes(t_modes mods)
{
    free(mods.flags);
    mods.width = -1;
    mods.precision = -1;
    free(mods.mod);
    mods.id = '_';
    mods.s = NULL;
    return (mods);
}

t_modes set_modes(void)
{
    t_modes mods;

    mods.flags = ft_strdup("");
    mods.width = -1;
    mods.precision = -1;
    mods.mod = ft_strdup("");
    mods.id = '_';
    mods.s = NULL;
    return (mods);
}

int     ft_printf(const char *str, ...)
{
    va_list ap;
    int     i;
    t_modes mods;
    int     res;

    res = 0;
    i = 0;
    va_start(ap, str);
    while (*str != '\0')
    {
        mods = set_modes();
        if (str[i] == '%' && str[i + 1] != '\0')
        {
            mods = write_mods((&str[i] + 1), mods);
            res += print_mod(mods, ap);
            str += (mods.s - str);
            mods = free_modes(mods);
            continue ;
        }
        else
            free_modes(mods);
        if (*str != '%')
            write(1, &(*str), 1);
        *str != '%' ? res++ : res;
        str++;
    }
    va_end(ap);
    return (res);
}
//
//#include <limits.h>
//#include <locale.h>
//
//int main(void)
//{
//    int r1;
//    int r2;
//    char* l = setlocale(LC_ALL, "");
//
//
//       r1 = printf("|%ls|\n", L"暖炉");
//    r2 = ft_printf("|%ls|\n", L"暖炉");
//    printf("r1 = %d; r2 = %d\n", r1, r2);
//    //system("leaks PRINTF");
//    system("leaks PRINTF | grep Process | tail -n 1");
////    printf("|%010+hhl12lh.4hh-84d|rest\n", 42);
////
////   printf("'%25zi' '%-i'\n", -9223372036854775808, -42);
//
//    return 0;
//}