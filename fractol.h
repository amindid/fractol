/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 23:51:36 by aouchaad          #+#    #+#             */
/*   Updated: 2023/02/10 22:53:12 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <mlx.h>
# include <stdlib.h>
# include <math.h>

# define HEIGHT 800
# define WIDTH 800
# define K_ESC 53
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define J_KEY 38
# define K_KEY 40
# define A_KEY 0
# define S_KEY 1
# define LEFT_FLECH 123
# define RIGHT_FLECH 124
# define UP_FLECH 126
# define DOWN_FLECH 125
# define ZOOM 1.2
# define MAX_ITER 60

typedef struct s_atod
{
	int		sign;
	int		res;
	int		i;
	int		count;
	int		check;
}	t_atod;

typedef struct s_fractol
{
	double	x_maped;
	double	y_maped;
	double	center_x;
	double	center_y;
	double	shift_x;
	double	shift_y;
	double	imagi;
	double	real;
	double	temp;
	double	ca;
	double	cb;
}	t_fractol;

typedef struct s_vars
{
	void	*mlx_ptr;
	void	*mlx_win;
}	t_vars;

typedef struct s_data
{
	int				col;
	double			nx;
	double			ny;
	int				i;
	double			zoom;
	unsigned int	color_shift;
	int				line;
	void			*img;
	char			*addr;
	t_vars			mlx;
	t_fractol		mand;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				fractal;
	double			plan_x;
	double			plan_y;
	double			mous_x;
	double			mous_y;
	double			shift;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	colors(int i, int A, int B, t_data *img);
int		ft_memcmp(char *string1, char *string2);
int		exit_win(t_data *img);
void	error_func(void);
void	fract_ol(double ca, double cb, t_data *img);
void	fract_ol_bonus(double ca, double cb, t_data *img);
int		key_hook(int keycode, t_data *img);
int		key_hook_bonus(int keycode, t_data *img);
int		mouse_houk(int keycode, int x, int y, t_data *img);
int		mouse_houk_bonus(int keycode, int x, int y, t_data *img);
double	ft_atod(char *string);
void	burning_ship(double ca, double cb, t_data *img);
void	change_julia(int keycode, t_data *img);

#endif
