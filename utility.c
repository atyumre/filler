/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 13:11:52 by atyumre           #+#    #+#             */
/*   Updated: 2018/07/31 11:09:23 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "filler.h"
#include "libft.h"

void	ft_init(t_game *game, char **line)
{
	game->player = ((*line)[10] == '1') ? 'O' : 'X';
	game->enemy = ((*line)[10] == '1') ? 'X' : 'O';
	game->moves = NULL;
	game->over = 0;
	free(*line);
}

int		token_iter(t_game *game, int i, int j)
{
	int connect;
	int k;
	int l;

	k = game->y_first;
	connect = 0;
	while (k <= game->y_last)
	{
		l = game->x_first;
		while (l <= game->x_last)
		{
			if (j + l <= game->map_x + 4 && i + k <= game->map_y)
				if ((game->token)[k][l] == '*' && ((game->map)[i + k][j + l]
					== game->player || (game->map)[i + k][j + l]
					== ft_tolower(game->player)))
					connect++;
			l++;
		}
		k++;
	}
	return (connect);
}

int		ft_square(int c)
{
	c = c * c;
	return (c);
}
