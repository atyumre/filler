/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:14:50 by atyumre           #+#    #+#             */
/*   Updated: 2018/05/30 15:18:52 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int	iter;
	int				found;

	iter = 0;
	found = 0;
	if (n == 0)
		return (NULL);
	while (iter < n && found == 0)
	{
		((unsigned char*)dest)[iter] = ((unsigned char*)src)[iter];
		if (((unsigned char*)src)[iter] == (unsigned char)c)
			found = 1;
		iter++;
	}
	if (found == 0)
		return (NULL);
	return ((unsigned char*)dest + (iter));
}
