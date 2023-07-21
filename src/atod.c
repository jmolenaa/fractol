/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   atod.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/04 13:27:18 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/03/13 07:45:02 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	get_first_half(double *nbr, char *str, size_t *i)
{
	const double	max = 100;
	int				sign;

	sign = 1;
	if (*str == '-')
	{
		(*i)++;
		sign = -1;
	}
	while (*(str + *i) >= '0' && *(str + *i) <= '9')
	{
		*(nbr) = *(nbr) * 10 + *(str + *i) - 48;
		if (*(nbr) >= max)
			list_available_parameters_and_exit("Wrong input : \
coordinates outside the min/max value\n");
		(*i)++;
	}
	*(nbr) = *(nbr) * sign;
}

static int	count_decimal_spots(char *str, size_t *i)
{
	int	decimal_place;

	decimal_place = 0;
	while (*(str + *i + decimal_place) != '\0')
	{
		decimal_place++;
		if (decimal_place > 10)
			list_available_parameters_and_exit("Wrong input : \
coordinates have too many decimal spots\n");
	}
	return (decimal_place);
}

static void	get_second_half(double *nbr, char *str, size_t *i)
{
	int		dec_spots;
	double	decimal_number;
	int		sign;

	decimal_number = 0;
	sign = 1;
	if (*str == '-')
	{
		(*i)++;
		sign = -1;
	}
	dec_spots = count_decimal_spots(str, i) - 1;
	while (*(str + *i + dec_spots) != '.' && *(str + *i + dec_spots) != ',')
	{
		decimal_number = (decimal_number + *(str + *i + dec_spots) - 48) / 10;
		dec_spots--;
	}
	*nbr = *nbr + (decimal_number * sign);
}

double	atod(char *str)
{
	double	nbr;
	size_t	i;

	nbr = 0;
	i = 0;
	if (validate_string(str))
		list_available_parameters_and_exit("Wrong input - \
coordinates contain forbidden characters\n");
	get_first_half(&nbr, str, &i);
	if (*(str + i) == '\0')
		return (nbr);
	i++;
	get_second_half(&nbr, str, &i);
	return (nbr);
}
