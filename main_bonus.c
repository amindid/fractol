/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:01:32 by aouchaad          #+#    #+#             */
/*   Updated: 2023/02/10 21:29:42 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_func(t_data *img)
{
	img->zoom = 1;
	img->col = 0;
	img->line = 0;
	img->nx = HEIGHT / 4;
	img->ny = WIDTH / 4;
	img->mand.center_x = 0;
	img->mand.center_y = 0;
	img->mand.shift_x = 0;
	img->mand.shift_y = 0;
	img->color_shift = 1;
	img->shift = 0.1;
}

static void	mlx_hook_functs(t_data *img)
{
	mlx_hook (img->mlx.mlx_win, 17, 0, exit_win, img);
	mlx_mouse_hook (img->mlx.mlx_win, mouse_houk_bonus, img);
	mlx_hook (img->mlx.mlx_win, 2, 0, key_hook_bonus, img);
}

static void	error_func_bonus(void)
{
	write (1, "Somthing went wrong !!!\n", 24);
	write (1, "To see mandlbrot set use \"mandelbrot\" or \"1\"\n", 45);
	write (1, "To see julia set use", 20);
	write (1, " \"julia\" or \"2\" then add two values\n", 36);
	write (1, "for example use ./fractol_bonus \"julia\" \"-1.476\" \"0\"\n", 53);
	write (1, "To see burning ship set use \"burning ship\" or \"3\"\n",
		50);
	exit (1);
}

static void	mlx_funcs(t_data *img)
{
	img->mlx.mlx_ptr = mlx_init();
	img->mlx.mlx_win = mlx_new_window(img->mlx.mlx_ptr,
			WIDTH, HEIGHT, "fract'ol");
	img->img = mlx_new_image (img->mlx.mlx_ptr, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr (img->img,
			&img->bits_per_pixel, &img->line_length, &img->endian);
	fract_ol_bonus (img->mand.ca, img->mand.cb, img);
	mlx_put_image_to_window (img->mlx.mlx_ptr,
		img->mlx.mlx_win, img->img, 0, 0);
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
	else if (ac == 2 && (ft_memcmp (av[1],
				"burning ship") == 0 || ft_memcmp (av[1], "3") == 0))
		img.fractal = 3;
	else
		error_func_bonus ();
	init_func (&img);
	mlx_funcs(&img);
	mlx_hook_functs (&img);
	mlx_loop (img.mlx.mlx_ptr);
}
