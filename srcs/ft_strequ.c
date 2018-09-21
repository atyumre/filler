/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:20:28 by atyumre           #+#    #+#             */
/*   Updated: 2018/05/24 14:26:44 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	if (s1 == NULL && s2 == NULL)
		return (1);
	else if (s1 == NULL || s2 == NULL)
		return (0);
	if (ft_strcmp(s1, s2))
		return (0);
	return (1);
}
