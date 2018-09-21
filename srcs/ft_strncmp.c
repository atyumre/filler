/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:22:24 by atyumre           #+#    #+#             */
/*   Updated: 2018/05/24 13:17:03 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int iter;

	iter = 0;
	if (n == 0)
		return (0);
	while (iter < ft_strlen(s1) && iter < n - 1 && s1[iter] == s2[iter])
		iter++;
	return (((unsigned char*)s1)[iter] - ((unsigned char*)s2)[iter]);
}
