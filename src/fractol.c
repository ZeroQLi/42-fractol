/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtangalv <mtangalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 12:15:37 by mtangalv          #+#    #+#             */
/*   Updated: 2025/05/13 12:35:15 by mtangalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_fractal(t_data *img)
{
	if (!ft_strcmp(img->name, "mandelbrot"))
		draw_mandel(img);
	else if (!ft_strcmp(img->name, "julia"))
	{
		if (!img->cx && !img->cy)
		{
			img->cx = -0.74929;
			img->cy = 0.05;
		}
		img->off_x = -1.68;
		draw_julia(img);
	}
	else if (!ft_strcmp(img->name, "ship"))
		draw_ship(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_data	*img;

	check_args(argc, argv);
	img = ft_calloc(1, sizeof(t_data));
	init_fractol(img);
	img->name = argv[1];
	if (ft_strlen(img->name) == 5 && argc == 4)
	{
		img->cx = ft_atof(argv[2]);
		img->cy = ft_atof(argv[3]);
	}
	ft_fractal(img);
	mlx_key_hook(img->mlx_win, ft_keys, img);
	mlx_mouse_hook(img->mlx_win, ft_mouse, img);
	mlx_hook(img->mlx_win, 17, 0, exit_fractol, img);
	mlx_loop(img->mlx);
}
