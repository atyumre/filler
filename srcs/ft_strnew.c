/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:22:46 by atyumre           #+#    #+#             */
/*   Updated: 2018/05/18 15:10:43 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*str;
	unsigned int	iter;

	iter = 0;
	str = (char*)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	while (iter < size + 1)
	{
		str[iter] = '\0';
		iter++;
	}
	return (str);
}
