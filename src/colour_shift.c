/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colour_shift.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 14:49:09 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/07/21 09:27:45 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	check_if_too_big(t_fractol *fractol)
{
	int	stream_to_compare;

	stream_to_compare = 126 << fractol->rgb;
	if ((fractol->colour & stream_to_compare) < stream_to_compare)
		return (0);
	return (1);
}

static int	check_if_too_small(t_fractol *fractol)
{
	int	stream_to_compare;

	stream_to_compare = 126 << fractol->rgb;
	if ((fractol->colour & stream_to_compare) > 0)
		return (0);
	return (1);
}

int	get_colour_shift(int iter, t_fractol *fractol)
{
	int	colour;
	int	i;
	int	j;

	j = (iter / INT8_MAX) % 2;
	i = (iter % INT8_MAX);
	if (j == 0)
		colour = fractol->colour + (i << 8) + (i << 24) + (i << 16);
	else
		colour = fractol->last_colour - (i << 8) - (i << 24) - (i << 16);
	return (colour);
}

void	check_colours(t_fractol *fractol)
{
	if (mlx_is_key_down(fractol->window, MLX_KEY_EQUAL))
	{
		if (check_if_too_big(fractol))
			return ;
		fractol->colour = fractol->colour + (2 << fractol->rgb);
		fractol->last_colour = fractol->last_colour + (2 << fractol->rgb);
		render_fractol(fractol);
	}
	else if (mlx_is_key_down(fractol->window, MLX_KEY_MINUS))
	{
		if (check_if_too_small(fractol))
			return ;
		fractol->colour = fractol->colour - (2 << fractol->rgb);
		fractol->last_colour = fractol->last_colour - (2 << fractol->rgb);
		render_fractol(fractol);
	}
}
