
#include "ft_printf.h"

int     print_s(t_modes mods, wchar_t *arg)
{
    char    *padding;
    char    *value;
    int     len;

    if ((ft_strcmp(mods.mod, "l") == 0 || mods.id == 'S') && arg != NULL)
        return (format_print_us(mods, arg));
    else
    {
        value = make_value_s(mods, (char*)arg);
        padding = make_padding_s(mods, (int)ft_strlen(value));
        len = make_res_s(mods, value,padding);
        return (len);
    }
}

int     make_res_s(t_modes mods, char *value, char *padding)
{
    int     len;
    char    *res;

    if (ft_strchr(mods.flags,'-') != NULL)
    {
        res = ft_strjoin(value, padding);
        len = (int)ft_strlen(res);
        ft_putstr(res);
        free(padding);
        free(value);
        free(res);
        return (len);
    }
    else
    {
        res = ft_strjoin(padding,value);
        len = (int)ft_strlen(res);
        ft_putstr(res);
        free(padding);
        free(value);
        free(res);
        return (len);
    }
}

int     format_print_us(t_modes mods, wchar_t *arg)
{
    char    *padding;
    int     res;

    res = 0;
    padding = make_padding_s(mods, count_len_us(arg, mods.precision, 0));
    if (ft_strchr(mods.flags,'-') != NULL)
    {
        res += print_res_us(mods, arg);
        ft_putstr(padding);
        res += ft_strlen(padding);
        free(padding);
    }
    else
    {
        ft_putstr(padding);
        res += ft_strlen(padding);
        res += print_res_us(mods, arg);
        free(padding);
    }
    return (res);
}

int     print_res_us(t_modes mods, wchar_t *arg)
{
    int res;

    res = 0;
    if (mods.precision != -1)
        res += print_us_prec(arg, mods.precision);
    else
        res += print_us(arg);
    return (res);
}

int     count_len_us(wchar_t *arg, int prec, int res)
{
    int i;
    int *uchar;

    i = 0;
    if (prec == -1)
        return (count_len_wo_prec(arg));
    while (arg[i] != '\0' && prec > 0)
    {
        if (arg[i] <= 127)
        {
            i++;
            res++;
            prec--;
        }
        else
        {
            uchar = make_uchar_for_s((int)(arg[i]));
            prec -= count_bytes_in_intarr(uchar);
            if (prec >= 0)
                res += count_bytes_in_intarr(uchar);
            free(uchar);
            i++;
        }
    }
    return (res);
}

int     count_len_wo_prec(wchar_t *arg)
{
    int res;
    int i;
    int *uchar;

    i = 0;
    res = 0;
    while (arg[i] != '\0')
    {
        if (arg[i] <= 127)
        {
            i++;
            res++;
        }
        else
        {
            uchar = make_uchar_for_s((int)(arg[i]));
            res += count_bytes_in_intarr(uchar);
            free(uchar);
            i++;
        }
    }
    return (res);
}

int     print_us_prec(wchar_t *arg, int prec)
{
    int res;
    int i;
    int *uchar;

    i = 0;
    res = 0;
    while (arg[i] != '\0' && prec > 0)
    {
        if (arg[i] <= 127)
            res += print_us_prec_c(arg, &i, &prec);
        else
        {
            uchar = make_uchar_for_s((int) (arg[i]));
            prec -= count_bytes_in_intarr(uchar);
            if (prec >= 0)
            {
                res += count_bytes_in_intarr(uchar);
                write_arr_of_bits(uchar);
            }
            else
                free(uchar);
            i++;
        }
    }
    return (res);
}

int     print_us_prec_c(wchar_t *arg, int *i, int *prec)
{
    ft_putchar((char)arg[(*i)]);
    (*i)++;
    (*prec)--;
    return (1);
}

int     print_us(wchar_t *arg)
{
    int res;
    int i;
    int *uchar;

    i = 0;
    res = 0;
    while (arg[i] != '\0')
    {
        if (arg[i] <= 127)
        {
            ft_putchar((char)arg[i]);
            i++;
            res++;
        }
        else {
            uchar = make_uchar_for_s((int) (arg[i]));
            res += count_bytes_in_intarr(uchar);
            write_arr_of_bits(uchar);
            i++;
        }
    }
    return (res);
}

int     *make_uchar_for_s(int c)
{
    char *bits_str;
    char *mask;
    char *after_mask_imp;
    char **arr_of_bits;
    int *res;

    bits_str = ft_itoabase(c, 2);
    mask = get_mask(count_bits(c));
    after_mask_imp = imp_mask(bits_str, mask);
    arr_of_bits = ft_strsplit(after_mask_imp, ' ');
    free(after_mask_imp);
    res = conv_arr(arr_of_bits, after_mask_imp);
    return (res);
}

int     count_bytes_in_intarr(int   *arr)
{
    int i;

    i = 0;
    while (arr[i] != -1)
        i++;
    return (i);
}

char    *make_padding_s(t_modes mods, int value_len)
{
    char    *res;
    char    filler;
    int     count_to_fill;

    filler = ' ';
    if (ft_strchr(mods.flags, '0') != NULL)
        filler = '0';
    res = ft_strdup("");
    if (mods.precision == -1 && mods.width == -1)
        return (res);
    if (mods.width != -1)
    {
        free(res);
        count_to_fill = mods.width - value_len;
        res = create_and_fill(count_to_fill, filler);
    }
    return (res);
}

char    *make_value_s(t_modes mods, char *arg)
{
    char    *res;
    int     i;

    i = 0;
    arg = arg == NULL ? "(null)" : arg;
    res = ft_strdup("");
    if (mods.width == -1 && mods.precision == -1 && arg != NULL)
        return (append(res, arg));
    if (mods.width != -1 && mods.precision == -1)
    {
        while (arg[i] != '\0')
        {
            res = append_char(res, arg[i]);
            i++;
        }
    }
    if (mods.precision != -1)
    {
        while (i < mods.precision && arg[i] != '\0')
        {
            res = append_char(res, arg[i]);
            i++;
        }
    }
    return(res);
}

char    *append_char(char *source, char to_append)
{
    char *res;
    char c[2];

    c[1] = '\0';
    c[0] = to_append;
    res = ft_strjoin(source, c);
    free(source);
    return (res);
}
