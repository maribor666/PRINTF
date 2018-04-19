/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ospeka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 20:53:28 by ospeka            #+#    #+#             */
/*   Updated: 2017/11/10 20:53:30 by ospeka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count_size(int n)
{
	long long int	buff;
	int				size;

	size = 0;
	buff = (long long int)n;
	if (buff < 0)
		size++;
	if (n == 0)
		return (2);
	while (buff != 0)
	{
		size++;
		buff = buff / 10;
	}
	return (size + 1);
}

static char	*write_str(char *res, int i, long long int buff)
{
	while (buff != 0)
	{
		res[i] = '0' + buff % 10;
		i--;
		buff = buff / 10;
	}
	return (res);
}

char		*ft_itoa(int n)
{
	long long int	buff;
	char			*res;
	int				i;

	i = count_size(n) - 2;
	buff = (long long int)n;
	res = (char*)malloc(sizeof(char) * count_size(n));
	if (n == 0)
	{
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	if (res == NULL)
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		buff = -buff;
	}
	res[count_size(n) - 1] = '\0';
	res = write_str(res, i, buff);
	return (res);
}
