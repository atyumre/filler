/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:22:55 by atyumre           #+#    #+#             */
/*   Updated: 2018/05/30 15:55:24 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_iterate(unsigned int *iter1, unsigned int *iter2)
{
	(*iter1)++;
	(*iter2)++;
}

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int iter1;
	unsigned int iter2;
	unsigned int mark;

	iter1 = 0;
	mark = 0;
	iter2 = 0;
	while (iter1 < ft_strlen(big) && iter1 < len)
	{
		iter2 = 0;
		if (big[iter1] == little[iter2])
		{
			mark = iter1;
			while (big[iter1] == little[iter2] &&
					little[iter2] && big[iter1] && iter1 < len)
				ft_iterate(&iter1, &iter2);
			iter1 = mark;
		}
		if (little[iter2] == '\0')
			break ;
		iter1++;
	}
	if (little[iter2] == '\0')
		return ((char*)big + mark);
	return (NULL);
}
