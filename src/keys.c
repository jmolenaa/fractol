/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keys.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/01 14:32:59 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/03/13 07:45:26 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

static void	change_power_and_render(t_fractol *fractol, int change)
{
	fractol->power = fractol->power + change;
	if (fractol->power > fractol->min_max.max_power)
		fractol->power = fractol->min_max.max_power;
	else if (fractol->power < fractol->min_max.min_iter)
		fractol->power = fractol->min_max.min_iter;
	render_fractol(fractol);
}

static void	change_power(t_fractol *fractol, mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_RIGHT_BRACKET && keydata.action == MLX_PRESS)
	{
		if (keydata.modifier == MLX_SUPERKEY)
			change_power_and_render(fractol, 10);
		else if (keydata.modifier == MLX_CONTROL)
			change_power_and_render(fractol, 5);
		else
			change_power_and_render(fractol, 1);
	}
	else if (keydata.action == MLX_PRESS)
	{
		if (keydata.modifier == MLX_SUPERKEY)
			change_power_and_render(fractol, -10);
		else if (keydata.modifier == MLX_CONTROL)
			change_power_and_render(fractol, -5);
		else
			change_power_and_render(fractol, -1);
	}
}

static void	change_set_and_render(t_fractol *fractol, char *str, int id)
{
	if (id == BOAR)
	{
		fractol->julia_coord.re = 0.687;
		fractol->julia_coord.im = 0.818;
	}
	fractol->set_id = id;
	mlx_set_window_title(fractol->window, str);
	render_fractol(fractol);
}

static void	change_set(t_fractol *fractol, mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_1 && keydata.action == MLX_PRESS)
		change_set_and_render(fractol, "mandelbrot", MANDELBROT);
	else if (keydata.key == MLX_KEY_2 && keydata.action == MLX_PRESS)
		change_set_and_render(fractol, "julia", JULIA);
	else if (keydata.key == MLX_KEY_3 && keydata.action == MLX_PRESS)
		change_set_and_render(fractol, "burning ship", BURNING_SHIP);
	else if (keydata.key == MLX_KEY_4 && keydata.action == MLX_PRESS)
		change_set_and_render(fractol, "tricorn", TRICORN);
	else if (keydata.key == MLX_KEY_5 && keydata.action == MLX_PRESS)
		change_set_and_render(fractol, "boar", BOAR);
	else if (keydata.key == MLX_KEY_6 && keydata.action == MLX_PRESS)
		change_set_and_render(fractol, "mandelbrot power", MANDELBROT_POWER);
	else if (keydata.key == MLX_KEY_7 && keydata.action == MLX_PRESS)
		change_set_and_render(fractol, "julia power", JULIA_POWER);
}

void	key_event(mlx_key_data_t keydata, void *param)
{
	if (keydata.key >= MLX_KEY_RIGHT && keydata.key <= MLX_KEY_UP)
		move_window(param, keydata);
	else if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
	{
		initialize_default_fractol_struct(param);
		render_fractol(param);
	}
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit_fractol(param);
	else if (keydata.key == MLX_KEY_U || keydata.key == MLX_KEY_I)
		jump_iter(keydata, param);
	else if (keydata.key >= MLX_KEY_0 && keydata.key <= MLX_KEY_9)
		change_set(param, keydata);
	else if (keydata.key == MLX_KEY_LEFT_BRACKET \
			|| keydata.key == MLX_KEY_RIGHT_BRACKET)
		change_power(param, keydata);
	else if (keydata.key == MLX_KEY_EQUAL || keydata.key == MLX_KEY_MINUS)
		change_rgb(param, keydata);
	else if (keydata.key == MLX_KEY_TAB && keydata.action == MLX_PRESS)
		change_colour_scheme(param);
	else if (keydata.key == MLX_KEY_H && keydata.action == MLX_PRESS)
		change_legend_visibility(param);
}
