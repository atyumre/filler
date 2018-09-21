/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:16:20 by atyumre           #+#    #+#             */
/*   Updated: 2018/05/24 14:40:39 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int iter;

	iter = 0;
	while (iter < n)
	{
		((char*)dest)[iter] = ((char*)src)[iter];
		iter++;
	}
	return (dest);
}
