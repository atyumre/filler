/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 13:04:47 by atyumre           #+#    #+#             */
/*   Updated: 2018/07/31 11:09:17 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "filler.h"

int		move_iter(t_game *game, int *j, int start)
{
	int i;

	i = 0;
	while (i < start && i < game->num_moves - 1)
	{
		if ((game->moves)[*j] == ',')
			i++;
		(*j)++;
	}
	if ((game->moves)[*j] == ',' && (game->moves)[(*j) + 1] != '\0')
		(*j) += 2;
	return (*j);
}

char	*read_moves(t_game *game, int start)
{
	int		i;
	int		j;
	int		k;
	char	*move;

	j = 0;
	if (game->moves == NULL || (game->moves)[0] == '\0')
	{
		game->over = 1;
		return (NULL);
	}
	k = move_iter(game, &j, start);
	while ((game->moves)[k] != ']')
		k++;
	move = (char*)malloc(sizeof(char) * (k - j + 2));
	i = 0;
	j++;
	while (j < k)
	{
		move[i] = (game->moves)[j];
		j++;
		i++;
	}
	move[i] = '\0';
	return (move);
}

void	put_token(char *move)
{
	int i;

	i = 0;
	if (move != NULL)
	{
		ft_putnbr(ft_atoi(move));
		ft_putchar(' ');
		while (move[i] != ' ')
			i++;
		i++;
		ft_putnbr(ft_atoi(&move[i]));
		ft_putchar('\n');
		free(move);
	}
	else
	{
		ft_putnbr(0);
		ft_putchar(' ');
		ft_putnbr(0);
		ft_putchar('\n');
	}
}

void	clear_game(t_game *game)
{
	int i;

	i = 0;
	while ((game->map)[i])
	{
		free((game->map)[i]);
		i++;
	}
	free(game->map);
	i = 0;
	while ((game->token)[i])
	{
		free((game->token)[i]);
		i++;
	}
	free(game->token);
	ft_strdel(&(game->moves));
}
