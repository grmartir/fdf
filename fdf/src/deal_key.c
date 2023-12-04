/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grmartir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:03:53 by grmartir          #+#    #+#             */
/*   Updated: 2023/06/09 18:31:53 by grmartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	issometric(int isometric)
{
	if (isometric)
		return (0);
	else
		return (1);
}

int	is_key(int key)
{
	return (key == 24 || key == 69 || key == 27 || key == 78 || \
	key == 91 || key == 28 || key == 84 || key == 19 || \
	key == '~' || key == '}' || key == '{' || key == '|' || \
	key == 87 || key == 23 || key == 86 || key == 21 || \
	key == 49 || key == 88 || key == 22);
}

void	do_key(int key, t_dot **matrix)
{
	if (key == 24 || key == 69)
		matrix[0][0].scale += 3;
	if (key == 27 || key == 78)
		matrix[0][0].scale -= 3;
	if (key == 91 || key == 28)
		matrix[0][0].z_scale += 1;
	if (key == 84 || key == 19)
		matrix[0][0].z_scale -= 1;
	if (key == '~')
		matrix[0][0].shift_y -= 10;
	if (key == '}')
		matrix[0][0].shift_y += 10;
	if (key == '{')
		matrix[0][0].shift_x -= 10;
	if (key == '|')
		matrix[0][0].shift_x += 10;
	if (key == 49 || key == 87 || key == 23)
		matrix[0][0].is_isometric = issometric(matrix[0][0].is_isometric);
	if (key == 86 || key == 21)
		matrix[0][0].angle += 0.05;
	if (key == 88 || key == 22)
		matrix[0][0].angle -= 0.05;
}

int	deal_key(int key, t_dot **ma)
{
	if (is_key(key))
	{
		mlx_clear_window(ma[0][0].mlx_ptr, ma[0][0].win_ptr);
		do_key(key, ma);
		ma[0]->img = mlx_new_image(ma[0]->mlx_ptr, ma[0]->win_x, ma[0]->win_y);
		ma[0]->addr = mlx_get_data_addr(ma[0]->img, &ma[0]->bits_per_pixel, \
			&ma[0]->line_length, &ma[0]->endian);
		draw(ma);
		mlx_put_image_to_window(ma[0][0].mlx_ptr, ma[0][0].win_ptr, \
			ma[0][0].img, 0, 0);
		print_menu(ma[0][0]);
	}
	if (key == 3)
		new_window(key, ma);
	if (key == '5')
	{
		mlx_destroy_window(ma[0][0].mlx_ptr, ma[0][0].win_ptr);
		free(ma[0]);
		exit(0);
	}
	return (0);
}
