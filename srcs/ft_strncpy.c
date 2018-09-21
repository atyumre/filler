/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:22:38 by atyumre           #+#    #+#             */
/*   Updated: 2018/05/24 15:59:29 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	unsigned int iter;

	iter = 0;
	while (iter < n && src[iter])
	{
		dest[iter] = src[iter];
		iter++;
	}
	while (iter < n)
	{
		dest[iter] = '\0';
		iter++;
	}
	return (dest);
}
