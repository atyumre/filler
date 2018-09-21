/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:14:37 by atyumre           #+#    #+#             */
/*   Updated: 2018/05/15 08:14:39 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *mem;

	mem = (void*)malloc(sizeof(void*) * size);
	if (mem == NULL)
		return (NULL);
	ft_memset(mem, 0, size);
	return (mem);
}
