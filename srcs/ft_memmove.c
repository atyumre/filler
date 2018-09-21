/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:16:41 by atyumre           #+#    #+#             */
/*   Updated: 2018/05/31 11:48:41 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	iter;
	void			*temp;

	temp = (char*)ft_memalloc(sizeof(char) * n);
	iter = 0;
	while (iter < n)
	{
		((char*)temp)[iter] = ((char*)src)[iter];
		iter++;
	}
	iter = 0;
	while (iter < n)
	{
		((char*)dest)[iter] = ((char*)temp)[iter];
		iter++;
	}
	ft_memdel(&temp);
	return (dest);
}
