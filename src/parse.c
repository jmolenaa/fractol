/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/01 08:44:04 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/07/21 09:28:58 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

static void	get_julia_coord(t_fractol *fractol, char *argv[])
{
	fractol->julia_coord.re = atod(argv[2]);
	fractol->julia_coord.im = atod(argv[3]);
}

static void	get_fractal_set(char *fractal_name, t_fractol *fractol)
{
	size_t	fractal_length;

	fractal_length = ft_strlen(fractal_name) + 1;
	if (!ft_strncmp(fractal_name, "mandelbrot", fractal_length))
		fractol->set_id = MANDELBROT;
	else if (!ft_strncmp(fractal_name, "julia", fractal_length))
		fractol->set_id = JULIA;
	else if (!ft_strncmp(fractal_name, "burning ship", fractal_length))
		fractol->set_id = BURNING_SHIP;
	else if (!ft_strncmp(fractal_name, "mandelbrot power", fractal_length))
		fractol->set_id = MANDELBROT_POWER;
	else if (!ft_strncmp(fractal_name, "julia power", fractal_length))
		fractol->set_id = JULIA_POWER;
	else if (!ft_strncmp(fractal_name, "tricorn", fractal_length))
		fractol->set_id = TRICORN;
	else if (!ft_strncmp(fractal_name, "boar", fractal_length))
		fractol->set_id = BOAR;
	else
		list_available_parameters_and_exit("Wrong input : \
no such available set\n");
	fractol->title = fractal_name;
}

void	parse_input(int argc, char *argv[], t_fractol *fractol)
{
	if (argc < 2 || argc > 4)
		list_available_parameters_and_exit("Wrong input : \
not enough arguments provided\n");
	get_fractal_set(argv[1], fractol);
	if (fractol->set_id >= 0 && fractol->set_id <= 3 && argc == 2)
		return ;
	else if (fractol->set_id == 4 && argc == 2)
	{
		fractol->julia_coord.re = 0.687;
		fractol->julia_coord.im = 0.818;
		return ;
	}
	else if (fractol->set_id >= 5 && fractol->set_id <= 6 && argc == 4)
	{
		get_julia_coord(fractol, argv);
		return ;
	}
	list_available_parameters_and_exit("Wrong input : \
wrong amount of arguments\n");
}
