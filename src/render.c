/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/04 14:08:54 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/03/13 07:28:11 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	choose_fractal(t_coord pixel_pos, t_fractol *fractol)
{
	int	iter;
	int	(*func[7])(t_coord, t_fractol *);

	func[MANDELBROT] = calculate_mandelbrot;
	func[JULIA] = calculate_julia;
	func[BURNING_SHIP] = calculate_burning_ship;
	func[TRICORN] = calculate_tricorn;
	func[BOAR] = calculate_boar;
	func[MANDELBROT_POWER] = calculate_mandelbrot_power;
	func[JULIA_POWER] = calculate_julia_power;
	iter = func[fractol->set_id](pixel_pos, fractol);
	return (iter);
}

static int	choose_colour_scheme(int iter, t_fractol *fractol)
{
	int	colour;
	int	(*func[2])(int, t_fractol *);

	func[SHIFT] = get_colour_shift;
	func[RAINBOW] = get_colour_rainbow;
	colour = func[fractol->scheme](iter, fractol);
	return (colour);
}

static void	put_pixel(t_coord pixel_pos, t_fractol *fractol, int i, int j)
{
	int	iter;
	int	colour;

	iter = choose_fractal(pixel_pos, fractol);
	if (iter == fractol->max_iter)
		mlx_put_pixel(fractol->img, i, j, 0x000000FF);
	else
	{
		colour = choose_colour_scheme(iter, fractol);
		mlx_put_pixel(fractol->img, i, j, colour);
	}
}

void	render_fractol(t_fractol *fractol)
{
	t_coord	pixel_pos;
	int		i;
	int		j;

	i = 0;
	while (i < fractol->width)
	{
		j = 0;
		pixel_pos.x = fractol->start.x + i * fractol->step_x;
		while (j < fractol->height)
		{
			pixel_pos.y = fractol->start.y - j * fractol->step_y;
			put_pixel(pixel_pos, fractol, i, j);
			j++;
		}
		i++;
	}
}
