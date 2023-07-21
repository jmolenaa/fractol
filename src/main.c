/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/24 15:01:45 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/03/13 07:52:10 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	setup_hooks(t_fractol *fractol)
{
	mlx_key_hook(fractol->window, key_event, fractol);
	mlx_scroll_hook(fractol->window, scroll_event, fractol);
	mlx_close_hook(fractol->window, exit_fractol, fractol);
	mlx_resize_hook(fractol->window, resize_event, fractol);
	if (!mlx_loop_hook(fractol->window, press_event, fractol))
		exit_fractol_with_error(fractol, "failed to setup hook\n");
}

int	main(int argc, char *argv[])
{
	t_fractol	fractol;

	initialize_window(&fractol, argc, argv);
	setup_hooks(&fractol);
	mlx_loop(fractol.window);
	mlx_terminate(fractol.window);
	return (0);
}
