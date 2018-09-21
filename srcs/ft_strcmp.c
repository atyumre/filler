/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:19:36 by atyumre           #+#    #+#             */
/*   Updated: 2018/05/15 08:19:38 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int iter;

	iter = 0;
	while (iter < ft_strlen(s1) && s1[iter] == s2[iter])
		iter++;
	return (((unsigned char*)s1)[iter] - ((unsigned char*)s2)[iter]);
}
