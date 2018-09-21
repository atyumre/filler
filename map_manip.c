/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 13:43:44 by atyumre           #+#    #+#             */
/*   Updated: 2018/07/31 10:16:08 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "get_next_line.h"
#include "filler.h"

void	get_map(int len, t_game *game)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	game->map = (char**)malloc(sizeof(char*) * (len + 2));
	while (i < len + 1)
	{
		get_next_line(0, &line);
		(game->map)[i] = ft_strdup(line);
		free(line);
		i++;
	}
	(game->map)[i] = 0;
}

void	get_token(t_game *game)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	get_next_line(0, &line);
	if (line != NULL)
	{
		game->token_y = ft_atoi(&line[6]);
		game->token_x = ft_atoi(&line[8]);
		free(line);
		game->token = (char**)malloc(sizeof(char*) * (game->token_y + 1));
		while (i < game->token_y)
		{
			get_next_line(0, &line);
			(game->token)[i] = ft_strdup(line);
			free(line);
			i++;
		}
		(game->token)[i] = 0;
	}
	cut_clean(game);
	cut_token(game);
}

void	find_moves(t_game *game)
{
	int i;
	int j;
	int connect;

	i = 1;
	while ((game->map)[i])
	{
		j = 4;
		while ((game->map)[i][j])
		{
			connect = token_iter(game, i, j);
			if (connect == 1 && error_check(game, i, j))
				insert_move(game, i - 1 - game->y_first, j - 4 - game->x_first);
			j++;
		}
		i++;
	}
}

int		error_check(t_game *game, int y, int x)
{
	int k;
	int l;

	k = game->y_first;
	while (k <= game->y_last)
	{
		l = game->x_first;
		while (l <= game->x_last)
		{
			if (x + l <= game->map_x + 4 && y + k <= game->map_y)
				if ((game->token)[k][l] == '*' && ((game->map)[y + k][x + l]
						== game->enemy || (game->map)[y + k][x + l]
						== ft_tolower(game->enemy)))
					return (0);
			l++;
		}
		k++;
	}
	if (game->y_last + y > game->map_y)
		return (0);
	if (game->x_last + x > game->map_x + 3)
		return (0);
	return (1);
}

void	insert_move(t_game *game, int y, int x)
{
	char *chary;
	char *charx;

	charx = ft_itoa(x);
	chary = ft_itoa(y);
	if (game->moves == NULL)
	{
		game->moves = ft_strnew(1);
		game->moves = ft_strjoin_memo(&(game->moves), "[");
		game->moves = ft_strjoin_memt(&(game->moves), &chary);
		game->moves = ft_strjoin_memo(&(game->moves), " ");
		game->moves = ft_strjoin_memt(&(game->moves), &charx);
		game->moves = ft_strjoin_memo(&(game->moves), "],");
		(game->num_moves)++;
	}
	else
	{
		game->moves = ft_strjoin_memo(&(game->moves), "[");
		game->moves = ft_strjoin_memt(&(game->moves), &chary);
		game->moves = ft_strjoin_memo(&(game->moves), " ");
		game->moves = ft_strjoin_memt(&(game->moves), &charx);
		game->moves = ft_strjoin_memo(&(game->moves), "],");
		(game->num_moves)++;
	}
}
