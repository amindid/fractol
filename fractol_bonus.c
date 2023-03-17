/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:04:49 by aouchaad          #+#    #+#             */
/*   Updated: 2023/02/10 23:54:10 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	iter_func(double ca, double cb, t_data *img)
{
	if (img->fractal == 1)
	{
		ca = img->mand.x_maped;
		cb = img->mand.y_maped;
	}
	img->i = 0;
	img->mand.real = img->mand.x_maped;
	img->mand.imagi = img->mand.y_maped;
	while (img->i <= MAX_ITER)
	{
		img->mand.temp = img->mand.real;
		img->mand.real = ((img->mand.real * img->mand.real) -(
					img->mand.imagi * img->mand.imagi) + ca);
		img->mand.imagi = ((2 * img->mand.temp * img->mand.imagi) + cb);
		if (((img->mand.real * img->mand.real) + (
					img->mand.imagi * img->mand.imagi)) >= 4)
			break ;
		(img->i)++;
		if (img->i == (MAX_ITER + 1))
			my_mlx_pixel_put (img, img->col, img->line,
				0x16213E00 * img->color_shift);
	}
}

void	fract_ol_bonus(double ca, double cb, t_data *img)
{
	if (img->fractal == 3)
	{
		burning_ship(ca, cb, img);
		return ;
	}
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
			iter_func (ca, cb, img);
			if (img->i < MAX_ITER + 1)
				colors (img->i, img->col, img->line, img);
			img->col++;
		}
		img->line++;
	}
}

static void	clear_image(t_data *img)
{
	mlx_clear_window (img->mlx.mlx_ptr, img->mlx.mlx_win);
	fract_ol_bonus (img->mand.ca, img->mand.cb, img);
	mlx_put_image_to_window (img->mlx.mlx_ptr,
		img->mlx.mlx_win, img->img, 0, 0);
}

int	key_hook_bonus(int keycode, t_data *img)
{
	if (keycode == RIGHT_FLECH)
		img->mand.shift_x -= img->shift;
	else if (keycode == LEFT_FLECH)
		img->mand.shift_x += img->shift;
	else if (keycode == UP_FLECH)
		img->mand.shift_y += img->shift;
	else if (keycode == DOWN_FLECH)
		img->mand.shift_y -= img->shift;
	else if (keycode == A_KEY)
		img->color_shift += 10;
	else if (keycode == S_KEY)
		img->color_shift -= 10;
	else if (keycode == K_ESC)
		exit_win(img);
	else if (img->fractal == 2 && (keycode == J_KEY || keycode == K_KEY))
		change_julia(keycode, img);
	else
		return (0);
	clear_image(img);
	return (0);
}

int	mouse_houk_bonus(int keycode, int x, int y, t_data *img)
{
	img->mous_x = ((x / img->nx) - (img->plan_x / 2)) * (-1);
	img->mous_y = (y / img->ny) - (img->plan_y / 2);
	if (keycode == SCROLL_DOWN)
	{
		img->nx *= ZOOM;
		img->ny *= ZOOM;
		img->shift /= ZOOM;
		img->mand.center_x -= img->mous_x / 6;
		img->mand.center_y += img->mous_y / 6;
	}
	if (keycode == SCROLL_UP)
	{
		img->nx /= ZOOM;
		img->ny /= ZOOM;
		img->shift *= ZOOM;
		img->mand.center_x += img->mous_x / 6;
		img->mand.center_y -= img->mous_y / 6;
	}
	clear_image(img);
	return (0);
}
