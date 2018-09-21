/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:22:07 by atyumre           #+#    #+#             */
/*   Updated: 2018/05/24 13:14:54 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	unsigned int iter1;
	unsigned int iter2;

	iter1 = ft_strlen(dest);
	iter2 = 0;
	while (iter2 < n && src[iter2])
	{
		dest[iter1] = src[iter2];
		iter1++;
		iter2++;
	}
	dest[iter1] = '\0';
	return (dest);
}
