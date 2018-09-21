/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:21:41 by atyumre           #+#    #+#             */
/*   Updated: 2018/05/24 14:35:28 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		iter;
	char	*fin;

	if (s == NULL || f == NULL)
		return (NULL);
	iter = 0;
	fin = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (fin == NULL)
		return (NULL);
	while (s[iter])
	{
		fin[iter] = (*f)(s[iter]);
		iter++;
	}
	fin[iter] = '\0';
	return (fin);
}
