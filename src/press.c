/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   press.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/02 09:39:31 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/03/13 07:45:41 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

static void	check_mouse(t_fractol *fractol)
{
	int32_t	mouse_x;
	int32_t	mouse_y;

	if (mlx_is_mouse_down(fractol->window, MLX_MOUSE_BUTTON_LEFT))
	{
		mlx_get_mouse_pos(fractol->window, &mouse_x, &mouse_y);
		fractol->julia_coord.re = fractol->start.x + mouse_x * fractol->step_x;
		fractol->julia_coord.im = fractol->start.y - mouse_y * fractol->step_y;
		if (fractol->set_id >= 4)
			render_fractol(fractol);
	}
}

static int	check_modifier_keys(t_fractol *fractol)
{
	if (mlx_is_key_down(fractol->window, MLX_KEY_LEFT_CONTROL) || \
		mlx_is_key_down(fractol->window, MLX_KEY_RIGHT_CONTROL) || \
		mlx_is_key_down(fractol->window, MLX_KEY_RIGHT_SUPER) || \
		mlx_is_key_down(fractol->window, MLX_KEY_LEFT_SUPER))
		return (1);
	return (0);
}

static void	move_smoothly(t_fractol *fractol)
{
	double	jumpx;
	double	jumpy;

	jumpx = fractol->width / 100;
	jumpy = fractol->height / 100;
	if (mlx_is_key_down(fractol->window, MLX_KEY_D))
		move_window_right(fractol, jumpx);
	else if (mlx_is_key_down(fractol->window, MLX_KEY_A))
		move_window_left(fractol, jumpx);
	else if (mlx_is_key_down(fractol->window, MLX_KEY_S))
		move_window_down(fractol, jumpy);
	else if (mlx_is_key_down(fractol->window, MLX_KEY_W))
		move_window_up(fractol, jumpy);
}

void	press_event(void *param)
{
	t_fractol	*fractol;

	fractol = param;
	if (check_modifier_keys(fractol))
		return ;
	iter_change(param);
	move_smoothly(param);
	check_mouse(param);
	check_colours(param);
}
