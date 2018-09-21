/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:23:08 by atyumre           #+#    #+#             */
/*   Updated: 2018/05/24 14:46:59 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	iter;
	int				found;

	found = 0;
	iter = ft_strlen(s);
	while (iter > 0 && s[iter] != (char)c)
		iter--;
	if (iter != 0 && s[iter] == (char)c)
		found = 1;
	if (s[0] == (char)c && found == 0)
		return ((char*)s);
	if (s[iter] == (char)c)
		return ((char*)s + iter);
	return (NULL);
}
