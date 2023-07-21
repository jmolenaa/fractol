/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scroll.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/01 14:45:21 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/03/13 07:45:59 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	redraw_fractal(t_fractol *fractol)
{
	fractol->step_x = fractol->range_x / fractol->width;
	fractol->step_y = fractol->range_y / fractol->height;
	render_fractol(fractol);
}

static void	zoom_out(t_fractol *fractol, t_mouse mouse)
{
	double	zoom_back;

	zoom_back = 0.25;
	fractol->range_x = fractol->range_x + fractol->range_x * zoom_back;
	fractol->start.x = mouse.mouse_pos.x - (fractol->range_x * mouse.prop_x);
	fractol->end.x = fractol->start.x + fractol->range_x;
	fractol->range_y = fractol->range_y + fractol->range_y * zoom_back;
	fractol->start.y = mouse.mouse_pos.y + (fractol->range_y * mouse.prop_y);
	fractol->end.y = fractol->start.y - fractol->range_y;
	redraw_fractal(fractol);
}

static void	zoom_in(t_fractol *fractol, t_mouse mouse)
{
	double	zoom;

	zoom = 0.2;
	fractol->range_x = fractol->range_x - fractol->range_x * zoom;
	fractol->start.x = mouse.mouse_pos.x - (fractol->range_x * mouse.prop_x);
	fractol->end.x = fractol->start.x + fractol->range_x;
	fractol->range_y = fractol->range_y - fractol->range_y * zoom;
	fractol->start.y = mouse.mouse_pos.y + (fractol->range_y * mouse.prop_y);
	fractol->end.y = fractol->start.y - fractol->range_y;
	redraw_fractal(fractol);
}

static void	get_mouse_info(t_fractol *fractol, t_mouse *mouse)
{
	int32_t	new_center_x;
	int32_t	new_center_y;

	mlx_get_mouse_pos(fractol->window, &new_center_x, &new_center_y);
	mouse->mouse_pos.x = fractol->start.x + new_center_x * fractol->step_x;
	mouse->mouse_pos.y = fractol->start.y - new_center_y * fractol->step_y;
	mouse->prop_x = new_center_x / fractol->width;
	mouse->prop_y = new_center_y / fractol->height;
}

void	scroll_event(double xdelta, double ydelta, void *fractol)
{
	t_mouse	mouse;

	(void)xdelta;
	get_mouse_info(fractol, &mouse);
	if (ydelta > 0)
		zoom_out(fractol, mouse);
	if (ydelta < 0)
		zoom_in(fractol, mouse);
}
