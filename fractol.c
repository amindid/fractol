/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:48:27 by aouchaad          #+#    #+#             */
/*   Updated: 2023/02/10 22:55:37 by aouchaad         ###   ########.fr       */
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
		img->mand.real = ((img->mand.real * img->mand.real) - (
					img->mand.imagi * img->mand.imagi) + ca);
		img->mand.imagi = ((2 * img->mand.temp * img->mand.imagi) + cb);
		if (((img->mand.real * img->mand.real) + (
					img->mand.imagi * img->mand.imagi)) >= 4)
			break ;
		(img->i)++;
		if (img->i == (MAX_ITER + 1))
			my_mlx_pixel_put (img, img->col, img->line, 0x16213E00);
	}
}

static void	color(int i, int col, int line, t_data *img)
{
	if (i == 0)
		my_mlx_pixel_put(img, col, line, 0x00100000);
	else
		my_mlx_pixel_put(img, col, line, 0x00100000 * i);
}

void	fract_ol(double ca, double cb, t_data *img)
{
	img->line = 0;
	img->plan_x = WIDTH / img->nx;
	img->plan_y = HEIGHT / img->ny;
	while (img->line < HEIGHT)
	{
		img->col = 0;
		img->mand.y_maped = (img->line / img->ny) - (img->plan_y / 2);
		while (img->col < WIDTH)
		{
			img->mand.x_maped = (img->col / img->nx) - (img->plan_x / 2);
			if (img->fractal == 1)
			{
				ca = img->mand.x_maped;
				cb = img->mand.y_maped;
			}
			iter_func (ca, cb, img);
			if (img->i < MAX_ITER + 1)
				color (img->i, img->col, img->line, img);
			img->col++;
		}
		img->line++;
	}
}

int	key_hook(int keycode, t_data *img)
{
	if (keycode == K_ESC)
		exit_win (img);
	return (0);
}

int	mouse_houk(int keycode, int x, int y, t_data *img)
{
	(void)x;
	(void)y;
	if (keycode == SCROLL_DOWN)
	{
		img->nx *= ZOOM;
		img->ny *= ZOOM;
	}
	if (keycode == SCROLL_UP)
	{
		img->nx /= ZOOM;
		img->ny /= ZOOM;
	}
	mlx_clear_window (img->mlx.mlx_ptr, img->mlx.mlx_win);
	fract_ol (img->mand.ca, img->mand.cb, img);
	mlx_put_image_to_window (img->mlx.mlx_ptr,
		img->mlx.mlx_win, img->img, 0, 0);
	return (0);
}
