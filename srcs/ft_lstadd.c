/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 11:36:27 by atyumre           #+#    #+#             */
/*   Updated: 2018/05/21 11:45:47 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list *node;
	t_list *head;

	node = new;
	head = new;
	while (*alst != NULL)
	{
		node->next = *alst;
		*alst = (*alst)->next;
		node = node->next;
	}
	*alst = head;
}
