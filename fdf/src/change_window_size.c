/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_window_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grmartir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:03:41 by grmartir          #+#    #+#             */
/*   Updated: 2023/06/09 18:14:55 by grmartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_win_size(int key, t_dot **matrix)
{
	if ((key == 0 && matrix[0][0].win_y <= 500) || \
	(key == 6 && matrix[0][0].win_x <= 500))
		return (1);
	if ((key == 1 && matrix[0][0].win_y > 1000) || \
	(key == 7 && matrix[0][0].win_x > 2000))
		return (1);
	return (0);
}

void	full_screen(t_dot **matrix)
{
	static int	old_x;
	static int	old_y;

	if (matrix[0][0].win_x != 2560)
	{
		old_x = matrix[0][0].win_x;
		old_y = matrix[0][0].win_y;
	}
	if (matrix[0][0].win_x == 2560)
		matrix[0][0].win_x = old_x;
	else
		matrix[0][0].win_x = 2560;
	if (matrix[0][0].win_y == 1400)
		matrix[0][0].win_y = old_y;
	else
		matrix[0][0].win_y = 1400;
}

void	change_window_size(int key, t_dot **matrix)
{
	if (check_win_size(key, matrix))
		return ;
	if (key == 6)
		matrix[0][0].win_x -= 100;
	if (key == 7)
		matrix[0][0].win_x += 100;
	if (key == 0)
		matrix[0][0].win_y -= 100;
	if (key == 1)
		matrix[0][0].win_y += 100;
	if (key == 3)
		full_screen(matrix);
}

void	new_window(int key, t_dot **ma)
{
	change_window_size(key, ma);
	mlx_destroy_window(ma[0][0].mlx_ptr, \
	ma[0][0].win_ptr);
	ma[0][0].mlx_ptr = mlx_init();
	ma[0][0].win_ptr = mlx_new_window(ma[0][0].mlx_ptr, \
	ma[0][0].win_x, ma[0][0].win_y, "FDF");
	ma[0][0].shift_x = ma[0][0].win_x / 3;
	ma[0][0].shift_y = ma[0][0].win_y / 3;
	ma[0]->img = mlx_new_image(ma[0]->mlx_ptr, ma[0]->win_x, ma[0]->win_y);
	ma[0]->addr = mlx_get_data_addr(ma[0]->img, &ma[0]->bits_per_pixel, \
		&ma[0]->line_length, &ma[0]->endian);
	draw(ma);
	mlx_put_image_to_window(ma[0][0].mlx_ptr, ma[0][0].win_ptr, \
		ma[0][0].img, 0, 0);
	print_menu(ma[0][0]);
	mlx_key_hook(ma[0][0].win_ptr, deal_key, ma);
	mlx_loop(ma[0][0].mlx_ptr);
}
