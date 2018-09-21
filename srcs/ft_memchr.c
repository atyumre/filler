/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:15:03 by atyumre           #+#    #+#             */
/*   Updated: 2018/05/30 15:25:18 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int iter;

	iter = 0;
	if (n == 0)
		return (NULL);
	while (iter < n - 1 && ((unsigned char*)s)[iter] != (unsigned char)c)
		iter++;
	if (((unsigned char*)s)[iter] == (unsigned char)c)
	{
		return ((unsigned char*)s + iter);
	}
	else
		return (NULL);
}
