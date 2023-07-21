/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/04 09:06:53 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/03/13 07:45:21 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

static void	initialize_max_min_values(t_fractol *fractol)
{
	int32_t	monit_width;
	int32_t	monit_height;

	mlx_get_monitor_size(0, &monit_width, &monit_height);
	fractol->min_max.max_iter = 1000;
	fractol->min_max.min_iter = 2;
	fractol->min_max.max_power = 100;
	fractol->min_max.min_power = 1;
	mlx_set_window_limit(fractol->window, 600, 600, monit_width, monit_height);
}

static void	initialize_starting_values(t_fractol *fractol)
{
	fractol->legend = NULL;
	fractol->rgb_string = NULL;
	fractol->width = 800;
	fractol->height = 800;
	fractol->rgb = 8;
	fractol->colour = 0x003333FF;
	fractol->last_colour = 0x7Fb2b2FF;
	fractol->set_id = 10;
	fractol->scheme = SHIFT;
}

void	initialize_default_fractol_struct(t_fractol *fractol)
{
	fractol->step_x = 0.005;
	fractol->step_y = 0.005;
	fractol->range_x = fractol->step_x * fractol->width;
	fractol->range_y = fractol->step_y * fractol->height;
	fractol->start.x = (-1) * (fractol->range_x / 2);
	fractol->end.x = fractol->range_x / 2;
	fractol->start.y = fractol->range_y / 2;
	fractol->end.y = (-1) * (fractol->range_y / 2);
	fractol->max_iter = 127;
	fractol->julia_coord.re = 0.355;
	fractol->julia_coord.im = 0.355;
	fractol->power = 3;
}

void	initialize_window(t_fractol *fract, int argc, char *argv[])
{
	initialize_starting_values(fract);
	initialize_default_fractol_struct(fract);
	parse_input(argc, argv, fract);
	fract->window = mlx_init(fract->width, fract->height, fract->title, 1);
	if (fract->window == NULL)
		ft_exit_with_error("failed to initiliaze window\n");
	initialize_max_min_values(fract);
	fract->img = mlx_new_image(fract->window, fract->width, fract->height);
	if (fract->img == NULL)
	{
		mlx_close_window(fract->window);
		mlx_terminate(fract->window);
		ft_exit_with_error("Image allocation failure\n");
	}
	if (mlx_image_to_window(fract->window, fract->img, 0, 0) == -1)
		exit_fractol_with_error(fract, "failed to put image on window\n");
	render_legend(fract);
	render_fractol(fract);
}
