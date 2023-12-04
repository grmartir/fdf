/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grmartir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:05:05 by grmartir          #+#    #+#             */
/*   Updated: 2023/06/09 18:05:06 by grmartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_menu(t_dot param)
{
	char	*menu;

	menu = "up, down, left, right: move picture";
	mlx_string_put(param.mlx_ptr, param.win_ptr, 10, 5, 0xffffff, menu);
	menu = "5, spase: 3d/2d mode; +, -: zoom";
	mlx_string_put(param.mlx_ptr, param.win_ptr, 10, 20, 0xffffff, menu);
	menu = "8, 2: z-scale; 4, 6: rotation";
	mlx_string_put(param.mlx_ptr, param.win_ptr, 10, 35, 0xffffff, menu);
	menu = "f: full screen mode";
	mlx_string_put(param.mlx_ptr, param.win_ptr, 10, 50, 0xffffff, menu);
}
