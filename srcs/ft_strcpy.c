/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:19:55 by atyumre           #+#    #+#             */
/*   Updated: 2018/05/15 12:49:26 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int iter;

	iter = 0;
	while (src[iter])
	{
		dest[iter] = src[iter];
		iter++;
	}
	dest[iter] = '\0';
	return (dest);
}
