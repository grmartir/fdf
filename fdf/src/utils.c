/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grmartir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 20:22:58 by grmartir          #+#    #+#             */
/*   Updated: 2023/06/09 20:30:25 by grmartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mmax(int a, int b)
{
	int	result;

	if (a > b)
		result = a;
	else
		result = b;
	return (result);
}

int	red_cross(int key, t_dot *utils)
{
	(void)key;
	(void)utils;
	exit(0);
}

void	my_mlx_pixel_put(t_dot *data, int x, int y, int color)
{
	char	*dst;

	if (data->addr && x > 0 && x < data->win_x && y > 0 && y < data->win_y)
	{
		dst = data->addr + (y * data->line_length + x * \
		(data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}
