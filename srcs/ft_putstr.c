/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:18:32 by atyumre           #+#    #+#             */
/*   Updated: 2018/06/11 15:26:51 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	int iter;

	iter = 0;
	if (s != NULL)
		while (s[iter])
		{
			ft_putchar(s[iter]);
			iter++;
		}
}
