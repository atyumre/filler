/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 15:04:07 by atyumre           #+#    #+#             */
/*   Updated: 2018/07/19 16:46:36 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "libft.h"

void	ft_gnl_overflow(char **full, char *del, char **line)
{
	int		x;
	char	*hold;

	x = 1;
	hold = (char*)malloc(sizeof(char) * (ft_strlen(del) + 1));
	while (del[x])
	{
		hold[x - 1] = del[x];
		x++;
	}
	hold[x - 1] = '\0';
	*del = '\0';
	*line = ft_strnew(ft_strlen(*full));
	ft_strcpy(*line, *full);
	ft_strcpy(*full, hold);
	free(hold);
}

void	ft_gnl_alloc(char *buf, char **full)
{
	char	*hold;

	if (*full != NULL)
	{
		hold = *full;
		*full = ft_strjoin((*full), buf);
		free(hold);
	}
	else
	{
		*full = ft_strnew(BUFF_SIZE + 1);
		ft_strcpy(*full, buf);
	}
}

int		ft_last_line(char **full, char **line)
{
	int		n;

	n = 0;
	if (*full != NULL && **full != '\0')
	{
		while ((*full)[n] != '\n' && (*full)[n] != '\0')
			n++;
		if ((*full)[n] == '\n')
		{
			ft_gnl_overflow(full, &(*full)[n], line);
			return (1);
		}
		*line = ft_strnew(ft_strlen(*full));
		ft_strcpy(*line, *full);
		free(*full);
		*full = NULL;
		return (1);
	}
	if (*full != NULL)
	{
		free(*full);
		*full = NULL;
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	char			*buf;
	static char		*full = NULL;
	int				x;
	int				i;

	i = -1;
	buf = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (read(fd, buf, 0) < 0 || fd < 0 || line == NULL)
		return (-1);
	while ((x = read(fd, buf, BUFF_SIZE)) > 0 && BUFF_SIZE != 0)
	{
		i++;
		buf[x] = '\0';
		ft_gnl_alloc(buf, &full);
		if (ft_memchr(buf, '\n', BUFF_SIZE))
		{
			ft_gnl_overflow(&full, ft_strchr(full + (BUFF_SIZE * i), '\n'),
					line);
			free(buf);
			return (1);
		}
	}
	free(buf);
	return (ft_last_line(&full, line));
}
