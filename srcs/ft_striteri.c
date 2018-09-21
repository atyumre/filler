/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:20:52 by atyumre           #+#    #+#             */
/*   Updated: 2018/05/24 14:22:55 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int iter;

	iter = 0;
	if (s != NULL && f != NULL)
		while (s[iter])
		{
			(*f)(iter, &s[iter]);
			iter++;
		}
}
