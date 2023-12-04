/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grmartir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:05:15 by grmartir          #+#    #+#             */
/*   Updated: 2023/06/09 18:05:17 by grmartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_dots_from_line(char *line, t_dot **matrix_of_dots, int y)
{
	char	**dots;
	int		x;

	dots = ft_strsplit(line, ' ');
	x = 0;
	while (dots[x])
	{
		matrix_of_dots[y][x].z = ft_atoi(dots[x]);
		matrix_of_dots[y][x].x = x;
		matrix_of_dots[y][x].y = y;
		matrix_of_dots[y][x].is_last = 0;
		free(dots[x++]);
	}
	free(dots);
	free(line);
	matrix_of_dots[y][--x].is_last = 1;
	return (x);
}

t_dot	**memory_allocete(char *file_name)
{
	t_dot	**new;
	int		x;
	int		y;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	if (fd <= 0)
		ft_error("file does not exist");
	get_next_line(fd, &line);
	x = ft_wdcounter(line, ' ');
	xwd_validator(x);
	free(line);
	y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		y++;
		free(line);
	}
	free(line);
	new = (t_dot **)malloc(sizeof(t_dot *) * (++y + 1));
	while (y > 0)
		new[--y] = (t_dot *)malloc(sizeof(t_dot) * (x + 1));
	close(fd);
	return (new);
}

void	x_validator(int x1, int x)
{
	if (x != x1)
		ft_error("Wrong map!");
}

void	xwd_validator(int x)
{
	if (x == 0)
		ft_error("Wrong map!");
}

t_dot	**read_map(char *file_name, int x, int y1)
{
	t_dot	**matrix_of_dots;
	int		y;
	int		fd;
	int		x1;
	char	*line;

	matrix_of_dots = memory_allocete(file_name);
	fd = open(file_name, O_RDONLY, 0);
	y = 0;
	x1 = 0;
	while (get_next_line(fd, &line) > 0)
	{
		x = get_dots_from_line(line, matrix_of_dots, y++);
		if (y1)
		{
			x1 = x;
			y1--;
		}
		x_validator(x1, x);
	}
	free(line);
	matrix_of_dots[y] = NULL;
	close(fd);
	return (matrix_of_dots);
}
