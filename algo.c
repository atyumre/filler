/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 13:06:03 by atyumre           #+#    #+#             */
/*   Updated: 2018/07/31 11:09:20 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "filler.h"
#include "libft.h"

int		strategy(t_game *game)
{
	int f;

	f = 0;
	if (game->moves != NULL && (game->moves)[0] != '\0')
	{
		if ((f = surround(game)) != -1)
			return (f);
		else if ((f = fill(game)) != -1)
			return (f);
	}
	return (0);
}

int		surround(t_game *game)
{
	int			i;
	int			lowest;
	static int	flip = 0;

	lowest = -1;
	i = (flip == 0) ? 0 : game->num_moves;
	game->dist = move_distance(game);
	if (flip == 0)
		while (i < game->num_moves)
		{
			if (lowest == -1 || game->dist[lowest] > game->dist[i])
				lowest = i;
			i++;
			flip = 1;
		}
	else
		while (i >= 0)
		{
			if (lowest == -1 || game->dist[lowest] > game->dist[i])
				lowest = i;
			i--;
			flip = 0;
		}
	return ((game->dist[lowest] > 0) ? lowest : -1);
}

int		ft_outer(int x, int y, t_game *game)
{
	int empty;

	empty = 0;
	if (game->map[y][x - 1] == '.')
		empty++;
	if (game->map[y + 1][x - 1] == '.')
		empty++;
	if (game->map[y + 1][x] == '.')
		empty++;
	if (game->map[y + 1][x + 1] == '.')
		empty++;
	if (game->map[y][x + 1] == '.')
		empty++;
	if (game->map[y - 1][x + 1] == '.')
		empty++;
	if (game->map[y - 1][x] == '.')
		empty++;
	if (game->map[y - 1][x - 1] == '.')
		empty++;
	if (empty >= 3)
		return (1);
	else
		return (0);
}

int		ft_shortest(t_game *game, int tx, int ty)
{
	int x;
	int y;
	int distance;

	distance = -1;
	y = 0;
	while ((game->map)[y])
	{
		x = 0;
		while ((game->map)[y][x])
		{
			if ((game->map)[y][x] == game->enemy ||
				(game->map)[y][x] == ft_tolower(game->enemy))
			{
				if (x > 0 && y > 3 && x < game->map_x && y < game->map_y)
					if (ft_outer(x, y, game))
						if (distance == -1 || distance >
								ft_distance(tx, ty, x, y))
							distance = ft_distance(tx, ty, x, y);
			}
			x++;
		}
		y++;
	}
	return (distance);
}

int		*move_distance(t_game *game)
{
	int		*dist;
	int		i;
	int		x;
	char	*temp;

	i = 0;
	dist = (int*)malloc(sizeof(int) * game->num_moves);
	while (i < game->num_moves)
	{
		temp = read_moves(game, i);
		x = 0;
		while (temp[x] != ' ')
			x++;
		dist[i] = ft_shortest(game, ft_atoi(&temp[x]), ft_atoi(temp));
		i++;
		free(temp);
	}
	return (dist);
}
