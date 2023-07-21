/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colour_functions.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 16:55:25 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/03/13 07:45:08 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_rgb(t_fractol *fractol, mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_EQUAL && keydata.action == MLX_PRESS \
		&& keydata.modifier == MLX_SUPERKEY && fractol->rgb < 24)
	{
		fractol->rgb = fractol->rgb + 8;
		add_current_stream(fractol);
	}
	else if (keydata.key == MLX_KEY_MINUS && keydata.action == MLX_PRESS \
		&& keydata.modifier == MLX_SUPERKEY && fractol->rgb > 8)
	{
		fractol->rgb = (fractol->rgb - 8);
		add_current_stream(fractol);
	}
}

void	change_colour_scheme(t_fractol *fractol)
{
	fractol->scheme = (fractol->scheme + 1) % 2;
	render_fractol(fractol);
}

int	get_colour_rainbow(int iter, t_fractol *fractol)
{
	int	i;
	int	mod;
	int	colour;
	int	j;

	(void)fractol;
	i = 1;
	mod = iter % 46;
	colour = 0x00003F00;
	while (i < mod)
	{
		j = 0;
		while (j < 4 && i < mod)
		{
			colour = colour << 4;
			i++;
			j++;
		}
		if (i == mod)
			break ;
		colour = (colour >> 16) * 2;
		i++;
	}
	colour = colour + 0x000000FF;
	return (colour);
}
