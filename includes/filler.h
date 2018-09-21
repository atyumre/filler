/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 13:04:41 by atyumre           #+#    #+#             */
/*   Updated: 2018/08/01 08:48:34 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

typedef struct	s_game
{
	int			x_first;
	int			x_last;
	int			y_first;
	int			y_last;
	char		player;
	char		enemy;
	int			map_x;
	int			map_y;
	int			token_x;
	int			token_y;
	char		**map;
	char		**token;
	char		*moves;
	int			num_moves;
	int			over;
	int			*dist;
}				t_game;

void			cut_token(t_game *game);
void			cut_clean(t_game *game);
void			cut_numbers(t_game *game, int k, int l);
void			get_map(int len, t_game *game);
void			get_token(t_game *game);
void			find_moves(t_game *game);
void			put_token(char *move);
int				error_check(t_game *game, int y, int x);
void			insert_move(t_game *game, int y, int x);
char			*read_moves(t_game *game, int start);
void			clear_game(t_game *game);
int				strategy(t_game *game);
int				surround(t_game *game);
int				ft_distance(int tx, int ty, int mx, int my);
int				ft_outer(int x, int y, t_game *game);
int				ft_shortest(t_game *game, int tx, int ty);
int				fill(t_game *game);
int				*move_distance(t_game *game);
int				ft_square(int c);
void			ft_init(t_game *game, char **line);
int				move_iter(t_game *game, int *j, int start);
int				token_iter(t_game *game, int i, int j);

#endif
