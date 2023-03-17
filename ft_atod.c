/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:08:27 by aouchaad          #+#    #+#             */
/*   Updated: 2023/02/10 22:29:38 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	funct_init(t_atod *stru)
{
	stru->sign = 1;
	stru->res = 0;
	stru->i = 0;
	stru->count = 0;
	stru->check = 0;
}

static void	check_white_spcs_sign(t_atod *stru, char *string)
{
	while (string[stru->i] == 32 || (
			string[stru->i] >= 9 && string[stru->i] <= 13))
		stru->i++;
	if (string[stru->i] == '-' || string[stru->i] == '+')
	{
		if (string[stru->i++] == '-')
			stru->sign = -1;
	}
}

double	ft_atod(char *string)
{
	t_atod	stru;

	funct_init (&stru);
	check_white_spcs_sign(&stru, string);
	if (string[stru.i] < 48 && string[stru.i] > 57)
		return (0);
	while ((string[stru.i] >= 48 && string[stru.i] <= 57) || (
			string[stru.i] == '.') || string[stru.i] == ',')
	{
		if (string[stru.i] == '.' || string[stru.i] == ',')
		{
			stru.check += 1;
			stru.i++;
		}
		if (stru.check > 1)
			return (0);
		if (stru.check == 1)
			stru.count += 1;
		stru.res *= 10;
		stru.res += string[stru.i++] - 48;
	}
	return ((stru.res * stru.sign) / pow(10, stru.count));
}
