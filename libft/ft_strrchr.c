/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ospeka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:30:46 by ospeka            #+#    #+#             */
/*   Updated: 2017/11/06 17:30:48 by ospeka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t i;
	size_t k;

	i = 0;
	k = 0;
	while (s[i] != '\0')
		i++;
	if ((char)c == '\0')
		return ((char*)(s + i));
	while (i != (size_t)-1)
	{
		if ((char)c == (unsigned char)s[i])
			return ((char*)(s + ft_strlen(s) - k));
		i--;
		k++;
	}
	return (NULL);
}
