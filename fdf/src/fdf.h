/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grmartir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:04:31 by grmartir          #+#    #+#             */
/*   Updated: 2023/06/09 20:20:41 by grmartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <math.h>
# include "../minilibx_macos/mlx.h"
//# define MOD(a) ((a < 0) ? -a : a)

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

typedef struct s_dot
{
	float		x;
	float		y;
	float		z;
	int			is_last;

	int			color;
	int			scale;
	int			z_scale;
	int			shift_x;
	int			shift_y;
	int			is_isometric;
	double		angle;
	int			win_x;
	int			win_y;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	char		*addr;
	char		*path;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			w;
	int			h;
}				t_dot;

t_dot	**read_map(char *file_name, int x, int y1);
void	isometric(t_dot *dot, double angle);
void	draw(t_dot **matrix);
int		deal_key(int key, t_dot **ma);
void	set_param(t_dot *a, t_dot *b, t_dot *param);
void	print_menu(t_dot param);
void	ft_error(char *msg);
void	new_window(int key, t_dot **ma);
int		mmax(int a, int b);
int		red_cross(int key, t_dot *utils);
void	my_pixel_put(t_dot *util);
void	my_mlx_pixel_put(t_dot *data, int x, int y, int color);
void	mlx_kanchox(void *mlx_ptr, void *win_ptr, t_dot param);
void	xwd_validator(int x);

#endif