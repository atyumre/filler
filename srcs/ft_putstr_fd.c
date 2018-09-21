/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:18:46 by atyumre           #+#    #+#             */
/*   Updated: 2018/06/11 15:29:50 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int iter;

	iter = 0;
	if (s != NULL)
		while (s[iter])
		{
			ft_putchar_fd(s[iter], fd);
			iter++;
		}
}
