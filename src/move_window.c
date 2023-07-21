/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_window.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/01 14:33:56 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/03/04 15:47:18 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_window_right(t_fractol *fractol, double jump)
{
	fractol->start.x = fractol->start.x + fractol->step_x * jump;
	fractol->end.x = fractol->end.x + fractol->step_x * jump;
	render_fractol(fractol);
}

void	move_window_left(t_fractol *fractol, double jump)
{
	fractol->start.x = fractol->start.x - fractol->step_x * jump;
	fractol->end.x = fractol->end.x - fractol->step_x * jump;
	render_fractol(fractol);
}

void	move_window_down(t_fractol *fractol, double jump)
{
	fractol->start.y = fractol->start.y - fractol->step_y * jump;
	fractol->end.y = fractol->end.y - fractol->step_y * jump;
	render_fractol(fractol);
}

void	move_window_up(t_fractol *fractol, double jump)
{
	fractol->start.y = fractol->start.y + fractol->step_y * jump;
	fractol->end.y = fractol->end.y + fractol->step_y * jump;
	render_fractol(fractol);
}

void	move_window(t_fractol *fractol, mlx_key_data_t keydata)
{
	double	jumpx;
	double	jumpy;

	jumpx = fractol->width / 5;
	jumpy = fractol->height / 5;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		move_window_right(fractol, jumpx);
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		move_window_left(fractol, jumpx);
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		move_window_down(fractol, jumpy);
	else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		move_window_up(fractol, jumpy);
}
