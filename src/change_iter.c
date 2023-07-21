/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   change_iter.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 17:38:45 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/03/07 14:59:24 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	change_iter_and_render(t_fractol *fractol, int jump)
{
	fractol->max_iter = fractol->max_iter + jump;
	if (fractol->max_iter > fractol->min_max.max_iter)
		fractol->max_iter = fractol->min_max.max_iter;
	else if (fractol->max_iter < fractol->min_max.min_iter)
		fractol->max_iter = fractol->min_max.min_iter;
	render_fractol(fractol);
}

void	iter_change(t_fractol *fractol)
{
	if (mlx_is_key_down(fractol->window, MLX_KEY_I))
		change_iter_and_render(fractol, 1);
	else if (mlx_is_key_down(fractol->window, MLX_KEY_U))
		change_iter_and_render(fractol, -1);
}

void	jump_iter(mlx_key_data_t keydata, t_fractol *fractol)
{
	if (keydata.key == MLX_KEY_U && keydata.action == MLX_PRESS \
		&& keydata.modifier == MLX_CONTROL)
		change_iter_and_render(fractol, -20);
	else if (keydata.key == MLX_KEY_I && keydata.action == MLX_PRESS \
		&& keydata.modifier == MLX_CONTROL)
		change_iter_and_render(fractol, 20);
	else if (keydata.key == MLX_KEY_U && keydata.action == MLX_PRESS \
		&& keydata.modifier == MLX_SUPERKEY)
		change_iter_and_render(fractol, -50);
	else if (keydata.key == MLX_KEY_I && keydata.action == MLX_PRESS \
		&& keydata.modifier == MLX_SUPERKEY)
		change_iter_and_render(fractol, 50);
}
