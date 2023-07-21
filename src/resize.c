/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   resize.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 10:19:46 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/03/13 07:45:56 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	adjust_x_values(t_fractol *fractol, double width)
{
	double	middle_x;

	fractol->width = width;
	middle_x = fractol->start.x + (fractol->range_x) / 2;
	fractol->range_x = fractol->width * fractol->step_x;
	fractol->start.x = middle_x - (fractol->range_x) / 2;
	fractol->end.x = fractol->start.x + fractol->range_x;
}

static void	adjust_y_values(t_fractol *fractol, double height)
{
	double	middle_y;

	fractol->height = height;
	middle_y = fractol->start.y - (fractol->range_y) / 2;
	fractol->range_y = fractol->height * fractol->step_y;
	fractol->start.y = middle_y + (fractol->range_y) / 2;
	fractol->end.y = fractol->start.y - fractol->range_y;
}

void	resize_event(int32_t width, int32_t height, void *param)
{
	t_fractol	*fractol;

	fractol = param;
	mlx_resize_image(fractol->img, width, height);
	adjust_x_values(fractol, width);
	adjust_y_values(fractol, height);
	clear_legend(fractol);
	render_legend(fractol);
	render_fractol(fractol);
}
