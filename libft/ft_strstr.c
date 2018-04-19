/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ospeka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:23:40 by ospeka            #+#    #+#             */
/*   Updated: 2017/11/06 19:23:41 by ospeka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t i;
	size_t j;
	size_t n;

	i = 0;
	n = ft_strlen(s2);
	if (*s2 == '\0')
		return ((char*)s1);
	while (s1[i])
	{
		j = 0;
		while (s2[j] == s1[i + j] && s2[j] != '\0')
			j++;
		if (n == j)
			return ((char*)s1 + i);
		i++;
	}
	return (NULL);
}
