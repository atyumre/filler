/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 11:52:04 by atyumre           #+#    #+#             */
/*   Updated: 2018/05/21 12:47:03 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *node;
	t_list *map;
	t_list *head;

	node = lst;
	if (node != NULL)
	{
		map = (*f)(node);
		head = map;
		node = node->next;
	}
	while (node != NULL)
	{
		map->next = (*f)(node);
		node = node->next;
		map = map->next;
	}
	return (head);
}
