/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtangalv <mtangalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:36:19 by mtangalv          #+#    #+#             */
/*   Updated: 2025/05/13 12:25:38 by mtangalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_data	*init_fractol(t_data *img)
{
	img->mlx = mlx_init();
	if (img->mlx == NULL)
		ft_error(img, 1);
	img->mlx_win = mlx_new_window(img->mlx, WIN_SIZE, WIN_SIZE, "Fractol");
	if (img->mlx_win == NULL)
		ft_error(img, 1);
	img->img = mlx_new_image(img->mlx, WIN_SIZE, WIN_SIZE);
	if (img->img == NULL)
		ft_error(img, 1);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	img->x = 0;
	img->y = 0;
	img->color = 0x0006b1;
	img->zoom = 300;
	img->off_x = -2.178;
	img->off_y = -1.512;
	img->iterations = 70;
	return (img);
}

void	ft_put_pixel(t_data *data, int x, int y, int color)
{
	char	*pxl;

	if ((x >= 0 && x < WIN_SIZE) && (y >= 0 && y < WIN_SIZE))
	{
		pxl = data->addr + (y * data->line_length + x
				* (data->bits_per_pixel / 8));
		*(unsigned int *)pxl = color;
	}
}

void	check_args(int argc, char **argv)
{
	if (argc < 2 || argc > 4)
	{
		ft_printf("Invalid arguments\n");
		ft_printf("Usage: ./fractol [mandelbrot, julia, ship]\n");
		exit(1);
	}
	if (ft_strcmp(argv[1], "mandelbrot") != 0 && ft_strcmp(argv[1], "julia")
		!= 0 && ft_strcmp(argv[1], "ship") != 0)
	{
		ft_printf("Invalid fractal\n");
		ft_printf("Usage: ./fractol [mandelbrot, julia, ship]\n");
		exit(1);
	}
	if (ft_strcmp(argv[1], "julia") != 0 && argc != 2)
	{
		ft_printf("Invalid arguments\n");
		ft_printf("Usage: ./fractol [mandelbrot, julia, ship]\n");
		exit(1);
	}
	if (ft_strcmp(argv[1], "julia") == 0 && (argc != 4 && argc != 2))
	{
		ft_printf("Invalid julia arguments\n");
		ft_printf("Usage: ./fractol julia [z, c]\n");
		exit(1);
	}
}
