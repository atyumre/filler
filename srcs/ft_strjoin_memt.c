/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_memt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 14:50:10 by atyumre           #+#    #+#             */
/*   Updated: 2018/07/24 14:50:25 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin_memt(char **s1, char **s2)
{
	int		iter1;
	int		iter2;
	char	*join;

	iter1 = 0;
	iter2 = 0;
	if (*s1 == NULL || *s2 == NULL)
		return (NULL);
	join = (char*)malloc(sizeof(char) * (ft_strlen(*s1) + ft_strlen(*s2) + 1));
	if (join == NULL)
		return (NULL);
	while ((*s1)[iter1])
	{
		join[iter1] = (*s1)[iter1];
		iter1++;
	}
	while ((*s2)[iter2])
	{
		join[iter1++] = (*s2)[iter2++];
	}
	join[iter1] = '\0';
	free(*s1);
	free(*s2);
	return (join);
}
