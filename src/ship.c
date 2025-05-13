/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtangalv <mtangalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:30:49 by mtangalv          #+#    #+#             */
/*   Updated: 2025/05/13 12:28:34 by mtangalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	calc_ship(t_data *img)
{
	int		i;
	float	x_temp;

	i = 0;
	img->zx = 0.0;
	img->zy = 0.0;
	img->cx = (img->x / img->zoom) + img->off_x;
	img->cy = (img->y / img->zoom) + img->off_y;
	while (i < img->iterations)
	{
		x_temp = (img->zx * img->zx) - (img->zy * img->zy) + img->cx;
		img->zy = fabs(2. * img->zx * img->zy) + img->cy;
		img->zx = fabs(x_temp);
		if ((img->zx * img->zx) + (img->zy * img->zy) >= __FLT_MAX__)
			break ;
		++i;
	}
	if (i == img->iterations)
		ft_put_pixel(img, img->x, img->y, 0x222222);
	else
		ft_put_pixel(img, img->x, img->y, (img->color * i));
}

int	draw_ship(t_data *img)
{
	img->x = 0;
	img->y = 0;
	while (img->x < WIN_SIZE)
	{
		while (img->y < WIN_SIZE)
		{
			calc_ship(img);
			img->y++;
		}
		img->x++;
		img->y = 0;
	}
	return (0);
}
