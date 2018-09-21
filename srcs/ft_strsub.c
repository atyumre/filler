/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:23:45 by atyumre           #+#    #+#             */
/*   Updated: 2018/05/24 14:30:07 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int		iter;
	char				*sub;

	iter = 0;
	sub = (char*)malloc(sizeof(char) * (len + 1));
	if (sub == NULL || s == NULL)
		return (NULL);
	while (iter < len)
	{
		sub[iter] = s[start];
		start++;
		iter++;
	}
	sub[iter] = '\0';
	return (sub);
}
