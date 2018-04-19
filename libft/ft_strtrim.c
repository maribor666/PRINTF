/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ospeka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:46:51 by ospeka            #+#    #+#             */
/*   Updated: 2017/11/10 19:46:52 by ospeka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	char	*res;
	size_t	start;
	size_t	end;

	if (s == NULL)
		return (NULL);
	end = ft_strlen(s) - 1;
	start = 0;
	while (is_space(s[start]) == 1 && s[start] != '\0')
		start++;
	if (start == ft_strlen(s))
	{
		res = malloc(sizeof(char) * 1);
		res[0] = '\0';
		return (res);
	}
	while (is_space(s[end]) == 1)
		end--;
	res = (char*)malloc(sizeof(char) * (end - start + 2));
	if (res == NULL)
		return (NULL);
	res = ft_strncpy(res, (char*)(&s[start]), (end - start + 1));
	res[end - start + 1] = '\0';
	return (res);
}
