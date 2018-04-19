#include "ft_printf.h"

t_modes write_mods(const char *s, t_modes mods)
{
    char *id_s;
    char *res;


    if (*s == '-' || *s == '+' || *s == ' ' || *s == '#' || *s == '0')
    {
        mods.flags[0] = *s;
        s++;
    }
    if (*s == '-' || *s == '+' || *s == ' ' || *s == '#' || *s == '0')
    {
        mods.flags[1] = *s;
        s++;
    }
    if (*s == '-' || *s == '+' || *s == ' ' || *s == '#' || *s == '0')
    {
        mods.flags[2] = *s;
        s++;
    }
    //made func write_flags with appending flags
    if (*s >= '0' && *s <= '9')
        mods.width = ft_atoi(s);
    while (*s >= '0' && *s <= '9')
        s++;
    if (*s == '.')
    {
        s++;
        mods.precision = ft_atoi(s);
    }
    while (*s >= '0' && *s <= '9')
        s++;
    if (*s == 'h' || *s == 'l' || *s == 'j' || *s == 'z')
    {
        mods.mod[0] = *s;
        s++;
    }
    if (*s == 'h' && mods.mod[0] == 'h')
    {
        mods.mod[1] = 'h';
        s++;
    }
    if (*s == 'l' && mods.mod[1] == 'l')
    {
        mods.mod[1] = 'h';
        s++;
    }
    id_s = "sSpdDioOuUxXcC";
    res = ft_strchr(id_s, *s);
    if (res != NULL)
    {
        mods.id = *res;
        s++;
    }
    mods.s = (char*)s;
    return (mods);
}

void    print_mod(t_modes mods, va_list ap)
{
    if (mods.id == 'd')
        print_d(mods, va_arg(ap, int));
//    if (mods.id == 'с')
//        print_с(mods, va_arg(ap, char));
//    if (mods.id == 's')
//        print_s(mods, va_arg(ap, char*));
//    if (mods.id == 'p')
//        print_p(mods, va_arg(ap, int));
}

t_modes set_modes(t_modes mods)
{
    mods.flags[0] = '_';
    mods.flags[1] = '_';
    mods.flags[2] = '_';
    mods.width = -1;
    mods.precision = -1;
    mods.mod[0] = '_';
    mods.mod[1] = '_';
    mods.id = '_';
    mods.s = NULL;
    return (mods);
}
int     ft_printf(const char *str, ...)
{
    va_list ap;
    int i;
    t_modes mods;

    i = 0;
    va_start(ap, str);
    mods = set_modes(mods);
    while (*str != '\0')
    {
        if (str[i] == '%')
        {
            mods = write_mods((&str[i] + 1), mods);
            print_mod(mods, ap); //  smt like write end return numbers of chars printed
            str += (mods.s - str);
            mods = set_modes(mods);
            continue ;
            //inc str(or i) to the next non mod char
            //clear modes -> continue
        }
        write(1, &(*str), 1);
        str++;
    }
    va_end(ap);
    return (1);
}

//int main()
//{
//
//    ft_printf("|%011.111d|rest\n", -42);
//       printf("|%011.111d|rest\n", -42);
//    system("leaks PRINTF | grep Process | tail -n 1");
////    ft_printf("|%- 12.4s|rest\n", "42");
////    printf("|%- 12.4s| rest\n", "42");
//    //printf("%u", 42);
////    printf("|%010+hhllh.42l0d|rest\n", 42);
////     printf("'%25hhhllljzi' '%-i'\n", -9223372036854775808, -42);
//
//    return 0;
//}













