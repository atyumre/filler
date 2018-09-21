/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:15:13 by atyumre           #+#    #+#             */
/*   Updated: 2018/05/24 13:26:43 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int iter;

	iter = 0;
	if (n == 0)
		return (0);
	while (iter < n - 1 &&
			((unsigned char*)s1)[iter] == ((unsigned char*)s2)[iter])
		iter++;
	return (((unsigned char*)s1)[iter] - ((unsigned char*)s2)[iter]);
}
