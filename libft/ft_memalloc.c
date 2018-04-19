/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ospeka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:48:03 by ospeka            #+#    #+#             */
/*   Updated: 2017/11/07 18:48:05 by ospeka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*res;
	size_t	i;

	i = 0;
	res = malloc(size);
	if (res == NULL)
		return (NULL);
	while (i < size)
	{
		*(unsigned char*)res = 0;
		res++;
		i++;
	}
	res -= i;
	return (res);
}
