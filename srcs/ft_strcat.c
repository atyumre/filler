/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:18:58 by atyumre           #+#    #+#             */
/*   Updated: 2018/06/07 13:52:23 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int iter;
	int srciter;

	srciter = 0;
	iter = ft_strlen(dest);
	while (src[srciter])
	{
		dest[iter] = src[srciter];
		iter++;
		srciter++;
	}
	dest[iter] = '\0';
	return (dest);
}
