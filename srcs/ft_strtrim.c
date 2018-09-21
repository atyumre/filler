/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:23:56 by atyumre           #+#    #+#             */
/*   Updated: 2018/05/24 14:34:14 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	set_star_end(char const *s, int *start, int *end)
{
	while (s[*start] && (s[*start] == ' ' ||
				s[*start] == '\t' || s[*start] == '\n'))
		(*start)++;
	while (*end >= 0 && (s[*end] == ' ' || s[*end] == '\t' || s[*end] == '\n'))
		(*end)--;
}

char		*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	char	*trim;
	int		iter;

	if (s == NULL)
		return (NULL);
	iter = 0;
	start = 0;
	end = ft_strlen(s) - 1;
	set_star_end(s, &start, &end);
	if ((end - start) > 0)
		trim = (char*)malloc(sizeof(char) * (end - start + 2));
	else
		trim = (char*)malloc(sizeof(char) * 1);
	if (trim == NULL)
		return (NULL);
	while (start <= end)
	{
		trim[iter] = s[start];
		iter++;
		start++;
	}
	trim[iter] = '\0';
	return (trim);
}
