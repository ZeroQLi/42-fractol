/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtangalv <mtangalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 12:17:36 by mtangalv          #+#    #+#             */
/*   Updated: 2025/05/13 12:30:37 by mtangalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define WIN_SIZE 970

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*name;
	float	zoom;
	int		x;
	int		y;
	float	zx;
	float	zy;
	float	cx;
	float	cy;
	float	off_x;
	float	off_y;
	int		iterations;
	int		color;
}	t_data;

void	ft_put_pixel(t_data *data, int x, int y, int color);
void	check_args(int argc, char **argv);
void	ft_fractal(t_data *img);
int		ft_keys(int key_code, t_data *img);
int		ft_mouse(int mouse_code, int x, int y, t_data *img);
int		ft_error(t_data *img, int errno);
int		exit_fractol(t_data *img, int errno);
t_data	*init_fractol(t_data *img);
int		draw_mandel(t_data *img);
int		draw_julia(t_data *img);
int		draw_ship(t_data *img);
#endif