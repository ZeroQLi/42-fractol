/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtangalv <mtangalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 10:45:08 by mtangalv          #+#    #+#             */
/*   Updated: 2025/05/13 12:29:26 by mtangalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	calc_julia(t_data *img)
{
	int		i;
	double	tmp;

	img->zx = img->x / img->zoom + img->off_x;
	img->zy = img->y / img->zoom + img->off_y;
	i = 0;
	while (i < img->iterations)
	{
		tmp = img->zx;
		img->zx = img->zx * img->zx - img->zy * img->zy + img->cx;
		img->zy = 2 * img->zy * tmp + img->cy;
		if (img->zx * img->zx + img->zy * img->zy >= __FLT_MAX__)
			break ;
		i++;
	}
	if (i == img->iterations)
		ft_put_pixel(img, img->x, img->y, 0x000000);
	else
		ft_put_pixel(img, img->x, img->y, img->color * i);
}

int	draw_julia(t_data *img)
{
	img->x = 0;
	img->y = 0;
	while (img->x < WIN_SIZE)
	{
		while (img->y < WIN_SIZE)
		{
			calc_julia(img);
			img->y++;
		}
		img->x++;
		img->y = 0;
	}
	return (0);
}
