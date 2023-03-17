/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:58:44 by aouchaad          #+#    #+#             */
/*   Updated: 2023/02/10 22:28:15 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	iter_func(double ca, double cb, t_data *img)
{
	img->i = 0;
	img->mand.real = img->mand.x_maped;
	img->mand.imagi = img->mand.y_maped;
	while (img->i <= MAX_ITER)
	{
		img->mand.temp = img->mand.real;
		img->mand.real = ((img->mand.real * img->mand.real) -(
					img->mand.imagi * img->mand.imagi) + ca);
		img->mand.imagi = ((2 * fabs(img->mand.temp * img->mand.imagi)) + cb);
		if (((img->mand.real * img->mand.real) + (
					img->mand.imagi * img->mand.imagi)) >= 4)
			break ;
		(img->i)++;
	}
	if (img->i == (MAX_ITER + 1))
		my_mlx_pixel_put (img, img->col,
			img->line, 0x16213E00 * img->color_shift);
}

void	burning_ship(double ca, double cb, t_data *img)
{
	img->plan_x = WIDTH / img->nx;
	img->plan_y = HEIGHT / img->ny;
	img->line = 0;
	while (img->line < HEIGHT)
	{
		img->col = 0;
		img->mand.y_maped = img->mand.center_y + (
				img->line / img->ny) - (img->plan_y / 2) + img->mand.shift_y;
		while (img->col < WIDTH)
		{
			img->mand.x_maped = img->mand.center_x + (
					img->col / img->nx) - (img->plan_x / 2) + img->mand.shift_x;
			if (img->fractal == 3)
			{
				ca = img->mand.x_maped;
				cb = img->mand.y_maped;
			}
			iter_func (ca, cb, img);
			if (img->i != MAX_ITER + 1)
				colors (img->i, img->col, img->line, img);
			img->col++;
		}
		img->line++;
	}
}
