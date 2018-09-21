/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:19:09 by atyumre           #+#    #+#             */
/*   Updated: 2018/05/15 12:48:24 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int iter;

	iter = 0;
	while (iter < ft_strlen(s) && s[iter] != (char)c)
		iter++;
	if (s[iter] == (char)c)
		return ((char*)s + iter);
	return (NULL);
}
