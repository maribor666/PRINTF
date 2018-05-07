#include  "ft_printf.h"

int    print_d(t_modes mods, ssize_t arg)
{
    char *prefix;
    char *value;
    char *padding;
    char *res;
    char *buff;
    int len;

    arg = caster(mods, arg);
    prefix = make_prefix(mods, arg);
    value = make_value(mods, arg);
    padding = make_padding(mods, prefix, value);

    //dprintf(2, "1");
    if (ft_strchr(mods.flags, '0') != NULL && ft_strchr(mods.flags, '-') == NULL)
    {
        dprintf(2,"1");
        buff = ft_strjoin(prefix, padding);
        res = ft_strjoin(buff, value);
        free(buff);

    }
    else {
        if (ft_strchr(mods.flags, '-') != NULL)
        {
            buff = ft_strjoin(prefix, value);
            res = ft_strjoin(buff, padding);
            free(buff);
        }
        else
        {
            buff = ft_strjoin(prefix, value);
            res = ft_strjoin(padding, buff);
            free(buff);
        }
    }
    ft_putstr(res);
    free(prefix);
    free(padding);
    free(value);
    len = (int)ft_strlen(res);
    free(res);
    return (len);
}

ssize_t caster(t_modes mods, ssize_t arg)
{
    if (ft_strcmp(mods.mod, "h") == 0 && mods.id == 'D')
        return ((unsigned short)arg);
    if (ft_strcmp(mods.mod, "h") == 0)
        return ((short)arg);
    if (ft_strcmp(mods.mod, "hh") == 0 && mods.id == 'D')
        return ((unsigned short)arg);
    if (ft_strcmp(mods.mod, "hh") == 0)
        return ((signed char)arg);
    if (ft_strcmp(mods.mod, "l") == 0)
        return ((long)arg);
    if (ft_strcmp(mods.mod, "ll") == 0)
        return ((long long) arg);
    if (ft_strcmp(mods.mod, "j") == 0)
        return ((intmax_t)arg);
    if (ft_strcmp(mods.mod, "z") == 0)
        return ((size_t)arg);
    if (mods.id == 'D')
        return ((long int)arg);
    return ((int)arg);
}

char    *make_value(t_modes mods, ssize_t arg)
{
    char *value;
    char *p;
    char *num;

    if (arg < 0)
        arg *= -1;
    num = ft_itoa(arg);
    if (arg == 0 && mods.precision == 0)
        return (ft_strdup(""));
    if (mods.precision != -1)
    {
        if (mods.precision >= ft_count_num(arg))
        {
            p = create_and_fill(mods.precision - ft_count_num(arg), '0');
            value = ft_strjoin(p, num);
            free(num);
            free(p);
        }
        else
        {
            value = ft_strdup(num);
            free(num);
        }
        return (value);
    }
    return (num);
}

char    *make_padding(t_modes mods, char *prefix, char *value)
{
    char    *padding;
    char    filler;
    int     count_to_fill;

    padding = ft_strdup("");
    filler = ' ';
    if (ft_strchr(mods.flags, '0') != NULL &&
            ft_strchr(mods.flags, '-') == NULL && mods.precision == -1)
        filler = '0';
    if (mods.precision == -1 && mods.width != -1)
    {
        count_to_fill = mods.width - ft_strlen(prefix) - ft_strlen(value);
        free(padding);
        padding = create_and_fill(count_to_fill, filler);
    }
    if (mods.precision != -1 && mods.width != -1)
    {
        count_to_fill = mods.width - ft_strlen(prefix) - ft_strlen(value);
        if (count_to_fill >= 0)
        {
            free(padding);
            padding = create_and_fill(count_to_fill, filler);
        }
    }
    return (padding);
}

char    *make_prefix(t_modes mods, ssize_t arg)
{
    char *prefix;

    prefix = ft_strdup("");
    if (ft_strchr(mods.flags, '+') != NULL)
    {
        if (arg < 0)
            prefix = append(prefix, "-");
        else
            prefix = append(prefix, "+");
        return (prefix);
    }
    if (ft_strchr(mods.flags, ' ') != NULL)
    {
        if (arg < 0)
            prefix = append(prefix, "-");
        else
            prefix = append(prefix, " ");
        return (prefix);
    }
    if (arg < 0)
        prefix = append(prefix, "-");
    return (prefix);
}

char    *create_and_fill(int count, char filler)
{
    char    *res;
    int     i;

    i = 0;
    if (count <= 0)
        return (ft_strdup(""));
    res = malloc(sizeof(char) * (count + 1));
    res[count] = '\0';
    while (i < count)
    {
        res[i] = filler;
        i++;
    }
    return (res);
}

char    *append(char *source, char *to_append)//source allocated with malloc but to_append is stack located
{
    char *res;

    res = ft_strjoin(source, to_append);
    free(source);
    return (res);
}
