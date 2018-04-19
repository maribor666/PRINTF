/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ospeka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 16:06:15 by ospeka            #+#    #+#             */
/*   Updated: 2018/01/09 16:06:17 by ospeka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(f)(t_list *elem))
{
	t_list *curr1;
	t_list *res;
	t_list *curr2;

	if (lst == NULL)
		return (NULL);
	curr1 = lst;
	res = ft_lstnew(f(curr1)->content, f(curr1)->content_size);
	if (res == NULL)
		return (NULL);
	curr1 = curr1->next;
	curr2 = res;
	while (curr1 != NULL)
	{
		curr2->next = ft_lstnew(f(curr1)->content, f(curr1)->content_size);
		curr1 = curr1->next;
		curr2 = curr2->next;
	}
	return (res);
}
