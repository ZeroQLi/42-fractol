/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtangalv <mtangalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:04:08 by mtangalv          #+#    #+#             */
/*   Updated: 2025/05/13 12:27:13 by mtangalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_zoom(int x, int y, int zoom, t_data *img)
{
	float	z_level;

	z_level = 1.31;
	if (zoom == 1)
	{
		img->off_x = (x / img->zoom + img->off_x)
			- (x / (img->zoom * z_level));
		img->off_y = (y / img->zoom + img->off_y)
			- (y / (img->zoom * z_level));
		img->zoom *= z_level;
	}
	else if (zoom == -1)
	{
		img->off_x = (x / img->zoom + img->off_x)
			- (x / (img->zoom / z_level));
		img->off_y = (y / img->zoom + img->off_y)
			- (y / (img->zoom / z_level));
		img->zoom /= z_level;
	}
	else
		return ;
}

static void	ft_color(int key_code, t_data *img)
{
	if (key_code == 18)
		img->color = 0x900c3f;
	if (key_code == 19)
		img->color = 0x0a6d0e8;
	if (key_code == 20)
		img->color = 0xBADBED;
	if (key_code == 21)
		img->color = 0xbeeeef;
	if (key_code == 23)
		img->color = 0xe0ac1b;
	if (key_code == 22)
		img->color = 0xa7f926;
	if (key_code == 26)
		img->color = 0xBE5103;
	if (key_code == 28)
		img->color = 0x0A8671;
	if (key_code == 25)
		img->color = 0x860A5D;
}

int	ft_keys(int key_code, t_data *img)
{
	if (key_code == 53)
		exit_fractol(img, 0);
	if (key_code == 0 || key_code == 123)
		img->off_x -= 35 / img->zoom;
	if (key_code == 2 || key_code == 124)
		img->off_x += 35 / img->zoom;
	if (key_code == 13 || key_code == 126)
		img->off_y -= 35 / img->zoom;
	if (key_code == 1 || key_code == 125)
		img->off_y += 35 / img->zoom;
	if (key_code >= 18 && key_code <= 28)
		ft_color(key_code, img);
	ft_fractal(img);
	return (0);
}

int	ft_mouse(int mouse_code, int x, int y, t_data *img)
{
	if (mouse_code == 4)
		ft_zoom(x, y, 1, img);
	if (mouse_code == 5)
		ft_zoom(x, y, -1, img);
	ft_fractal(img);
	return (0);
}
