/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandel_julia_power.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 07:27:24 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/03/07 10:24:32 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

static double	fact(int i)
{
	double	factorial;

	factorial = 1;
	while (i > 1)
	{
		factorial = factorial * i;
		i--;
	}
	return (factorial);
}

static double	count_re_s(double x, double y, t_fractol *fract)
{
	double	re;
	int		i;
	int		sign;
	double	coefficient;

	re = 0;
	i = 0;
	sign = 1;
	while (i <= fract->power)
	{
		coefficient = fact(fract->power) / (fact(i) * fact(fract->power - i));
		re = re + sign * coefficient * pow(x, fract->power - i) * pow(y, i);
		sign = sign * (-1);
		i = i + 2;
	}
	return (re);
}

static double	count_im_s(double x, double y, t_fractol *fract)
{
	double	im;
	int		i;
	int		sign;
	double	coefficient;

	im = 0;
	i = 1;
	sign = 1;
	while (i <= fract->power)
	{
		coefficient = fact(fract->power) / (fact(i) * fact(fract->power - i));
		im = im + sign * coefficient * pow(x, fract->power - i) * pow(y, i);
		sign = sign * (-1);
		i = i + 2;
	}
	return (im);
}

int	calculate_julia_power(t_coord pixel_pos, t_fractol *fract)
{
	int			iter;
	t_complex	curr_iter;
	t_complex	squared;
	double		store;

	curr_iter.re = pixel_pos.x;
	curr_iter.im = pixel_pos.y;
	iter = 0;
	while (iter < fract->max_iter)
	{
		squared.re = curr_iter.re * curr_iter.re;
		squared.im = curr_iter.im * curr_iter.im;
		if (squared.re + squared.im > 4)
			return (iter);
		store = curr_iter.im;
		curr_iter.im = count_im_s(curr_iter.re, curr_iter.im, fract) \
						+ fract->julia_coord.im;
		curr_iter.re = count_re_s(curr_iter.re, store, fract) \
						+ fract->julia_coord.re;
		iter++;
	}
	return (iter);
}

int	calculate_mandelbrot_power(t_coord pixel_pos, t_fractol *fract)
{
	int			iter;
	t_complex	curr_iter;
	t_complex	squared;
	double		store;

	curr_iter.re = 0;
	curr_iter.im = 0;
	iter = 0;
	while (iter < fract->max_iter)
	{
		squared.re = curr_iter.re * curr_iter.re;
		squared.im = curr_iter.im * curr_iter.im;
		if (squared.re + squared.im > 4)
			return (iter);
		store = curr_iter.im;
		curr_iter.im = count_im_s(curr_iter.re, curr_iter.im, fract) \
						+ pixel_pos.y;
		curr_iter.re = count_re_s(curr_iter.re, store, fract) + pixel_pos.x;
		iter++;
	}
	return (iter);
}
