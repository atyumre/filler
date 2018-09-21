/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:20:18 by atyumre           #+#    #+#             */
/*   Updated: 2018/05/17 13:32:53 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		iter;
	char	*dup;

	iter = 0;
	dup = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (dup == NULL)
		return (NULL);
	while (s[iter])
	{
		dup[iter] = s[iter];
		iter++;
	}
	dup[iter] = '\0';
	return (dup);
}
