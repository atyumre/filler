/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:21:16 by atyumre           #+#    #+#             */
/*   Updated: 2018/05/24 16:16:51 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	iter1;
	unsigned int	iter2;
	unsigned int	dstinit;

	dstinit = ft_strlen(dst);
	iter1 = ft_strlen(dst);
	iter2 = 0;
	while (size == 0 ? iter1 < size : iter1 < size - 1 && src[iter2])
	{
		dst[iter1] = src[iter2];
		iter1++;
		iter2++;
	}
	if (size != 0 && iter1 < size)
		dst[iter1] = '\0';
	if (ft_strlen(dst) > size)
		return (ft_strlen(dst) + ft_strlen(src) - (ft_strlen(dst) - size));
	else
		return (dstinit + ft_strlen(src));
}
