/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:23:29 by atyumre           #+#    #+#             */
/*   Updated: 2018/05/24 11:30:17 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_iterat(unsigned int *iter1, unsigned int *iter2)
{
	(*iter1)++;
	(*iter2)++;
}

char		*ft_strstr(const char *haystack, const char *needle)
{
	unsigned int iter1;
	unsigned int iter2;
	unsigned int mark;

	iter1 = 0;
	mark = 0;
	iter2 = 0;
	while (iter1 < ft_strlen(haystack))
	{
		iter2 = 0;
		if (haystack[iter1] == needle[iter2])
		{
			mark = iter1;
			while (haystack[iter1] == needle[iter2] &&
					needle[iter2] && haystack[iter1])
				ft_iterat(&iter1, &iter2);
			iter1 = mark;
		}
		if (needle[iter2] == '\0')
			break ;
		iter1++;
	}
	if (needle[iter2] == '\0')
		return ((char*)haystack + mark);
	return (NULL);
}
