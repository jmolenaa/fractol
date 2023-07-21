/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_fractals.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/04 20:21:52 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/03/08 07:07:59 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

int	calculate_mandelbrot(t_coord pixel_pos, t_fractol *fractol)
{
	int			iter;
	t_complex	current_iter;
	t_complex	squared;

	current_iter.re = 0;
	current_iter.im = 0;
	iter = 0;
	while (iter < fractol->max_iter)
	{
		squared.re = current_iter.re * current_iter.re;
		squared.im = current_iter.im * current_iter.im;
		if (squared.re + squared.im > 4)
			return (iter);
		current_iter.im = 2 * current_iter.re * current_iter.im + pixel_pos.y;
		current_iter.re = squared.re - squared.im + pixel_pos.x;
		iter++;
	}
	return (iter);
}

int	calculate_julia(t_coord pixel_pos, t_fractol *fract)
{
	int			iter;
	t_complex	curr_iter;
	t_complex	squared;

	curr_iter.re = pixel_pos.x;
	curr_iter.im = pixel_pos.y;
	iter = 0;
	while (iter < fract->max_iter)
	{
		squared.re = curr_iter.re * curr_iter.re;
		squared.im = curr_iter.im * curr_iter.im;
		if (squared.re + squared.im > 4)
			return (iter);
		curr_iter.im = 2 * curr_iter.re * curr_iter.im + fract->julia_coord.im;
		curr_iter.re = squared.re - squared.im + fract->julia_coord.re;
		iter++;
	}
	return (iter);
}

int	calculate_burning_ship(t_coord pixel_pos, t_fractol *fractol)
{
	int			iter;
	t_complex	curr_iter;
	t_complex	squared;

	curr_iter.re = 0;
	curr_iter.im = 0;
	iter = 0;
	while (iter < fractol->max_iter)
	{
		squared.re = curr_iter.re * curr_iter.re;
		squared.im = curr_iter.im * curr_iter.im;
		if (squared.re + squared.im > 4)
			return (iter);
		curr_iter.im = 2 * abs_val(curr_iter.re * curr_iter.im) - pixel_pos.y;
		curr_iter.re = squared.re - squared.im - pixel_pos.x;
		iter++;
	}
	return (iter);
}

int	calculate_tricorn(t_coord pixel_pos, t_fractol *fractol)
{
	int			iter;
	t_complex	curr_iter;
	t_complex	squared;

	curr_iter.re = 0;
	curr_iter.im = 0;
	iter = 0;
	while (iter < fractol->max_iter)
	{
		squared.re = curr_iter.re * curr_iter.re;
		squared.im = curr_iter.im * curr_iter.im;
		if (squared.re + squared.im > 4)
			return (iter);
		curr_iter.im = -2 * curr_iter.re * curr_iter.im + pixel_pos.y;
		curr_iter.re = squared.re - squared.im + pixel_pos.x;
		iter++;
	}
	return (iter);
}

int	calculate_boar(t_coord pixel_pos, t_fractol *fract)
{
	int			iter;
	t_complex	curr_iter;
	t_complex	squared;

	curr_iter.re = pixel_pos.x;
	curr_iter.im = pixel_pos.y;
	iter = 0;
	while (iter < fract->max_iter)
	{
		squared.re = curr_iter.re * curr_iter.re;
		squared.im = curr_iter.im * curr_iter.im;
		if (squared.re + squared.im > 4)
			return (iter);
		curr_iter.im = ((2 * squared.re * curr_iter.im) \
						+ pow(fract->julia_coord.re, 3));
		curr_iter.re = (squared.re - squared.im \
						+ pow(fract->julia_coord.im, 3));
		iter++;
	}
	return (iter);
}
