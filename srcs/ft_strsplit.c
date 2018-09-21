/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:23:17 by atyumre           #+#    #+#             */
/*   Updated: 2018/05/31 14:43:39 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	lengths(char const *s, int *longest, int *strings, char c)
{
	int		cur;
	int		iter;

	iter = 0;
	while (s[iter])
	{
		cur = 0;
		while (s[iter] != c && s[iter])
		{
			iter++;
			cur++;
		}
		if (iter != 0 && (s[iter] == c || s[iter] == '\0') && s[iter - 1] != c)
			(*strings)++;
		if (cur > *longest)
			*longest = cur;
		iter++;
	}
}

static void	ft_dosplit(const char *s, char c, char **fin)
{
	int		iter;
	int		row;
	int		col;

	iter = 0;
	row = 0;
	col = 0;
	while (s[iter])
	{
		while (s[iter] != c && s[iter])
		{
			fin[col][row] = s[iter];
			row++;
			iter++;
		}
		if (iter != 0 && (s[iter] == c || s[iter] == '\0') && s[iter - 1] != c)
		{
			fin[col][row] = '\0';
			row = 0;
			col++;
		}
		if (s[iter])
			iter++;
	}
	fin[col] = 0;
}

char		**ft_strsplit(char const *s, char c)
{
	char	**fin;
	int		longest;
	int		strings;
	int		iter;

	iter = 0;
	longest = 0;
	strings = 0;
	if (s == NULL)
		return (NULL);
	lengths(s, &longest, &strings, c);
	fin = (char**)malloc(sizeof(char*) * (strings + 1));
	if (fin == NULL)
		return (NULL);
	while (iter <= strings + 1)
	{
		fin[iter] = (char*)malloc(sizeof(char) * (longest + 1));
		if (fin[iter] == NULL)
			return (NULL);
		iter++;
	}
	ft_dosplit(s, c, fin);
	return (fin);
}
