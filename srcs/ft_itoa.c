/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:14:24 by atyumre           #+#    #+#             */
/*   Updated: 2018/05/31 15:06:27 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*ft_itoa_mem(int *iter, long int *pow, int *neg, int *n)
{
	char		*asc;

	if (*n < 0 && *n - 1 < 0)
	{
		*neg = 1;
		*n *= -1;
	}
	else if (*n < 0 && !(*n - 1 < 0))
	{
		*neg = 11;
		*n += 1;
		*n *= -1;
	}
	while (*pow <= *n)
	{
		*pow *= 10;
		(*iter)++;
	}
	*pow /= 10;
	asc = (char*)malloc(sizeof(char) * (*iter + 2));
	return (asc);
}

static void	ft_conv(char *asc, int neg, long int pow, int n)
{
	int iter;

	if (neg == 0)
		iter = 0;
	else
	{
		asc[0] = '-';
		iter = 1;
	}
	if (n == 0)
	{
		asc[0] = '0';
		iter++;
	}
	else
		while (pow > 0)
		{
			if (neg == 11 && pow == 1)
				asc[iter] = (((n / pow) - (n / (pow * 10) * 10)) + '0') + 1;
			else
				asc[iter] = ((n / pow) - (n / (pow * 10) * 10)) + '0';
			iter++;
			pow /= 10;
		}
	asc[iter] = '\0';
}

char		*ft_itoa(int n)
{
	int			iter;
	long int	pow;
	char		*asc;
	int			neg;

	iter = 0;
	pow = 1;
	neg = 0;
	asc = ft_itoa_mem(&iter, &pow, &neg, &n);
	if (asc == NULL)
		return (NULL);
	ft_conv(asc, neg, pow, n);
	return (asc);
}
