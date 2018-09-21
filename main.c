/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 13:08:20 by atyumre           #+#    #+#             */
/*   Updated: 2018/07/24 15:12:23 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "filler.h"
#include "libft.h"
#include "get_next_line.h"

int	main(void)
{
	char	*line;
	t_game	*game;

	game = (t_game*)malloc(sizeof(t_game));
	get_next_line(0, &line);
	ft_init(game, &line);
	while (game->over != 1)
	{
		get_next_line(0, &line);
		if (line != NULL)
		{
			game->num_moves = 0;
			game->map_y = ft_atoi(&line[8]);
			game->map_x = ft_atoi(&line[11]);
			get_map(game->map_y, game);
			get_token(game);
			find_moves(game);
			put_token(read_moves(game, strategy(game)));
			clear_game(game);
			free(line);
			line = NULL;
		}
	}
	free(game);
	return (0);
}
