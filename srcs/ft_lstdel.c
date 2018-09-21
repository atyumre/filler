/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 11:32:04 by atyumre           #+#    #+#             */
/*   Updated: 2018/05/24 14:45:28 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *node;

	while (*alst != NULL)
	{
		(*del)((*alst)->content, (*alst)->content_size);
		free(*alst);
		node = (*alst)->next;
		*alst = NULL;
		*alst = node;
	}
}
