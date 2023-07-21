/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/01 10:46:53 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/03/13 07:45:13 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol.h"

void	list_available_parameters_and_exit(char *reason)
{
	ft_putstr_fd(reason, 1);
	ft_putstr_fd("usage:\n\
	./fractol [name] [coordinates]\n\
	name - \"mandelbrot\", \"julia\" , \"burning ship\", \"tricorn\", \
\"boar\", \"mandelbrot power\" or \"julia power\"\n\
	coordinates - coordinates for the julia sets, \
coordinates should be between 100 and -100 \
and have at most 10 decimal places\n", 1);
	exit(1);
}

void	exit_fractol(void *param)
{
	t_fractol	*fractol;

	fractol = param;
	clear_legend(fractol);
	mlx_delete_image(fractol->window, fractol->img);
	mlx_close_window(fractol->window);
}

void	exit_fractol_with_error(t_fractol *fractol, char *str)
{
	clear_legend(fractol);
	mlx_delete_image(fractol->window, fractol->img);
	mlx_close_window(fractol->window);
	mlx_terminate(fractol->window);
	ft_exit_with_error(str);
}

double	abs_val(double number)
{
	if (number < 0)
		number = number * (-1);
	return (number);
}
