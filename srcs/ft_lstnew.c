/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 12:11:03 by atyumre           #+#    #+#             */
/*   Updated: 2018/06/19 14:31:30 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	ft_content(t_list *node, void const *content, size_t content_size)
{
	node->content = (void*)malloc(content_size);
	ft_memcpy(node->content, content, content_size);
}

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*node;

	node = (t_list*)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	if (content == NULL)
	{
		node->content = NULL;
		node->content_size = 0;
		node->next = NULL;
	}
	else
	{
		ft_content(node, content, content_size);
		node->content_size = content_size;
		node->next = NULL;
	}
	return (node);
}
