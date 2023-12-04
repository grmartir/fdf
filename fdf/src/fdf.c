/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grmartir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 21:27:42 by grmartir          #+#    #+#             */
/*   Updated: 2023/06/09 21:27:43 by grmartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_default(t_dot *param)
{
	param->scale = 20;
	param->z_scale = 1;
	param->is_isometric = 1;
	param->angle = 0.523599;
	param->win_x = 2000;
	param->win_y = 1000;
	param->shift_x = param->win_x / 3;
	param->shift_y = param->win_y / 3;
	param->mlx_ptr = mlx_init();
	param->win_ptr = \
	mlx_new_window(param->mlx_ptr, param->win_x, param->win_y, "FDF");
	param->img = mlx_new_image(param->mlx_ptr, param->win_x, param->win_y);
	param->addr = mlx_get_data_addr(param->img, &param->bits_per_pixel,
			&param->line_length, &param->endian);
}

int	main(int argc, char **argv)
{
	t_dot	**matrix;

	if (argc != 2)
		ft_error("usage: ./fdf map.fdf");
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".fdf", 4) != 0)
		ft_error("Incorrect file!");
	matrix = read_map(*++argv, 0, 1);
	set_default(&matrix[0][0]);
	draw(matrix);
	mlx_put_image_to_window(matrix[0]->mlx_ptr, matrix[0]->win_ptr, \
	matrix[0]->img, 0, 0);
	print_menu(matrix[0][0]);
	mlx_hook(matrix[0][0].win_ptr, 17, (1L << 17), red_cross, &matrix[0][0]);
	mlx_key_hook(matrix[0][0].win_ptr, deal_key, matrix);
	mlx_loop(matrix[0][0].mlx_ptr);
	return (0);
}
