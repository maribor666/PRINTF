/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcountnumb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ospeka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 16:06:25 by ospeka            #+#    #+#             */
/*   Updated: 2018/01/12 16:06:32 by ospeka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstcountnumb(t_list **alst)
{
	int		i;
	t_list	*curr;

	i = 0;
	curr = *alst;
	while (curr != NULL)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}
