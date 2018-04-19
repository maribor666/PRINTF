/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ospeka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:39:39 by ospeka            #+#    #+#             */
/*   Updated: 2017/11/07 14:39:41 by ospeka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cheker(const char *haystack, const char *needle, size_t len)
{
	if (haystack[0] == '\0' || ft_strlen(needle) > len ||
		ft_strlen(haystack) < ft_strlen(needle))
		return (1);
	else
		return (0);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	j = 0;
	i = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	if (cheker(haystack, needle, len) == 1)
		return (NULL);
	while (i < len)
	{
		while (haystack[i] == needle[j])
		{
			if (i > len)
				return (NULL);
			i++;
			j++;
			if (needle[j] == '\0')
				return ((char*)&haystack[i - ft_strlen(needle)]);
		}
		i -= j;
		j = 0;
		i++;
	}
	return (NULL);
}
