/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtangalv <mtangalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:46:21 by mtangalv          #+#    #+#             */
/*   Updated: 2025/05/13 12:27:25 by mtangalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	exit_fractol(t_data *img, int errno)
{
	if (img->img)
		mlx_destroy_image(img->mlx, img->img);
	if (img->mlx_win)
		mlx_destroy_window(img->mlx, img->mlx_win);
	if (img->mlx)
	{
		free(img->mlx);
		img->mlx = NULL;
	}
	if (img)
	{
		free(img);
		img = NULL;
	}
	exit(errno);
	return (0);
}

int	ft_error(t_data *img, int errno)
{
	perror("fractol: ");
	exit_fractol(img, errno);
	return (0);
}
