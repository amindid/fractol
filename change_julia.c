/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_julia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:26:52 by aouchaad          #+#    #+#             */
/*   Updated: 2023/02/06 18:18:33 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	key_j_func(t_data *img)
{
	if (img->mand.ca >= 1)
	{
		img->mand.cb += 0.01;
		img->mand.ca *= -1;
	}
	else if (img->mand.ca <= -2)
	{
		img->mand.ca *= -1;
		img->mand.cb -= 0.01;
	}
	img->mand.ca += 0.01;
}

static void	key_k_func(t_data *img)
{
	if (img->mand.ca >= 1)
	{
		img->mand.cb -= 0.01;
		img->mand.ca *= -1;
	}
	else if (img->mand.ca <= -2)
	{
		img->mand.ca *= -1;
		img->mand.cb += 0.01;
	}
	img->mand.ca -= 0.01;
}

void	change_julia(int keycode, t_data *img)
{
	if (keycode == J_KEY)
		key_j_func (img);
	else if (keycode == K_KEY)
		key_k_func (img);
}
