/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ospeka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 15:26:18 by ospeka            #+#    #+#             */
/*   Updated: 2017/11/02 15:26:20 by ospeka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		*(unsigned char*)dst = *(unsigned char*)src;
		src++;
		dst++;
		i++;
	}
	src -= n;
	dst -= n;
	return (dst);
}
