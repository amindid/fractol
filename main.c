/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 23:51:01 by aouchaad          #+#    #+#             */
/*   Updated: 2023/02/10 21:29:53 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_func(t_data *img)
{
	img->zoom = 1;
	img->col = 0;
	img->line = 0;
	img->ny = HEIGHT / 4;
	img->nx = WIDTH / 4;
}

static void	mlx_hook_functs(t_data *img)
{
	mlx_hook (img->mlx.mlx_win, 17, 0, exit_win, img);
	mlx_mouse_hook (img->mlx.mlx_win, mouse_houk, img);
	mlx_hook (img->mlx.mlx_win, 2, 0, key_hook, img);
}

int	main(int ac, char *av[])
{
	t_data	img;

	if (ac == 2 && (ft_memcmp (av[1],
				"mandelbrot") == 0 || ft_memcmp (av[1], "1") == 0))
		img.fractal = 1;
	else if (ac == 4 && (ft_memcmp (av[1],
				"julia") == 0 || ft_memcmp (av[1], "2") == 0))
	{
		img.fractal = 2;
		img.mand.ca = ft_atod(av[2]);
		img.mand.cb = ft_atod(av[3]);
	}
	else
		error_func ();
	init_func (&img);
	img.mlx.mlx_ptr = mlx_init();
	img.mlx.mlx_win = mlx_new_window(img.mlx.mlx_ptr,
			WIDTH, HEIGHT, "fract'ol");
	img.img = mlx_new_image (img.mlx.mlx_ptr, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr (img.img,
			&img.bits_per_pixel, &img.line_length, &img.endian);
	fract_ol (img.mand.ca, img.mand.cb, &img);
	mlx_put_image_to_window (img.mlx.mlx_ptr, img.mlx.mlx_win, img.img, 0, 0);
	mlx_hook_functs(&img);
	mlx_loop (img.mlx.mlx_ptr);
}
