/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ospeka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:09:43 by ospeka            #+#    #+#             */
/*   Updated: 2017/11/06 19:09:44 by ospeka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t len1;
	size_t count;

	count = 0;
	len1 = 0;
	i = 0;
	while (s1[len1] != '\0')
		len1++;
	while (s2[i] != '\0' && count < n)
	{
		s1[len1 + i] = s2[i];
		i++;
		count++;
	}
	s1[len1 + i] = '\0';
	return (s1);
}
