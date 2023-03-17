/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 23:51:14 by aouchaad          #+#    #+#             */
/*   Updated: 2023/02/10 22:53:25 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	colors(int i, int col, int line, t_data *img)
{
	if (i == 0)
		my_mlx_pixel_put(img, col, line, 0x00100000);
	else
		my_mlx_pixel_put(img, col, line, 0x00100000 * i * img->color_shift);
}

int	ft_memcmp(char *string1, char *string2)
{
	int	i;

	i = 0;
	while (string1[i] != '\0')
	{
		if (string1[i] != string2[i])
			return (string1[i] - string2[i]);
		i++;
	}
	return (0);
}

int	exit_win(t_data *img)
{
	mlx_destroy_image(img->mlx.mlx_ptr, img->img);
	mlx_destroy_window(img->mlx.mlx_ptr, img->mlx.mlx_win);
	free(img->mlx.mlx_ptr);
	exit (0);
}

void	error_func(void)
{
	write (1, "Somthing went wrong !!!\n", 24);
	write (1, "To see mandlbrot set use \"mandelbrot\" or \"1\"\n", 45);
	write (1, "To see julia set use ", 21);
	write (1, "\"julia\" or \"2\" then add two values\n", 35);
	write (1, "for example use ./fractol \"julia\" \"-1.476\" \"0\"\n", 47);
	exit (1);
}
