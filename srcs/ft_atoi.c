/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:12:48 by atyumre           #+#    #+#             */
/*   Updated: 2018/05/30 14:52:24 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_invalid_char(int *iter, int *neg, char const *nptr, int *len)
{
	while ((!ft_isdigit(nptr[*iter]) && (nptr[*iter] != '-' && nptr[*iter]
					!= '+')) || ((nptr[*iter] == '-' || nptr[*iter] == '+') &&
					!ft_isdigit(nptr[*iter + 1])))
	{
		if ((nptr[*iter] == '-' || nptr[*iter] == '+') &&
				!ft_isdigit(nptr[*iter + 1]))
			return (0);
		else if ((nptr[*iter] < '\t' || nptr[*iter] > '\r') &&
				nptr[*iter] != ' ')
			return (0);
		(*iter)++;
	}
	while (((nptr[*iter] == '-' || nptr[*iter] == '+') && (*iter == 0 ?
					ft_isdigit(nptr[*iter + 1]) : ft_isdigit(nptr[*iter + 1]) &&
					!ft_isdigit(nptr[*iter - 1]))) || ft_isdigit(nptr[*iter]))
	{
		if (nptr[*iter] == '-')
			*neg = -1;
		(*iter)++;
		(*len)++;
	}
	(*len)--;
	(*iter)--;
	return (1);
}

static int	ft_num_add(char c, int *pow, long *num, int neg)
{
	if (*num < 0 && neg == -1)
		return (0);
	if (*num < 0)
		return (-1);
	(*num) += ((c - '0') * (*pow));
	(*pow) *= 10;
	return (1);
}

int			ft_atoi(const char *nptr)
{
	long	num;
	int		iter;
	int		pow;
	int		len;
	int		neg;

	len = 0;
	neg = 0;
	iter = 0;
	num = 0;
	pow = 1;
	if (ft_invalid_char(&iter, &neg, nptr, &len) == 0)
		return (0);
	while (len >= 0)
	{
		if (ft_isdigit(nptr[iter]))
		{
			if (ft_num_add(nptr[iter], &pow, &num, neg) != 1)
				return (ft_num_add(nptr[iter], &pow, &num, neg));
		}
		iter--;
		len--;
	}
	(neg == -1) ? num *= neg : num;
	return (num);
}
