/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 11:01:32 by atyumre           #+#    #+#             */
/*   Updated: 2018/07/31 11:03:20 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	cut_clean(t_game *game)
{
	game->x_first = -1;
	game->x_last = -1;
	game->y_first = -1;
	game->y_last = -1;
}

void	cut_numbers(t_game *game, int k, int l)
{
	if (game->x_first == -1 || game->x_first > l)
		game->x_first = l;
	if (game->x_last == -1 || game->x_last < l)
		game->x_last = l;
	if (game->y_first == -1 || game->y_first > k)
		game->y_first = l;
	if (game->y_last == -1 || game->y_last < k)
		game->y_last = k;
}

void	cut_token(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (game->token[i])
	{
		j = 0;
		while (game->token[i][j])
		{
			cut_numbers(game, i, j);
			j++;
		}
		i++;
	}
}

int		fill(t_game *game)
{
	(void)game;
	return (0);
}

int		ft_distance(int tx, int ty, int mx, int my)
{
	return (ft_square(tx - mx) + ft_square(ty - my));
}
