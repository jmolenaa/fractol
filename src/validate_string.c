/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_string.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/04 13:27:37 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/03/08 09:13:47 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	validate_first_half(char *str, size_t *i)
{
	if (*str == '-')
		(*i)++;
	if (*(str + *i) == '0' && *(str + *i + 1) != ',' && \
		*(str + *i + 1) != '.' && *(str + *i + 1) != '\0')
		return (1);
	while (*(str + *i) >= '0' && *(str + *i) <= '9')
		(*i)++;
	return (0);
}

static int	validate_middle(char *str, size_t *i)
{
	if (*(str + *i) == '\0')
		return (0);
	if (*(str + *i) != '.' && *(str + *i) != ',')
		return (1);
	if (*(str + *i - 1) < '0' || *(str + *i - 1) > '9')
		return (1);
	if (*(str + *i + 1) < '0' || *(str + *i + 1) > '9')
		return (1);
	(*i)++;
	return (0);
}

static int	validate_second_half(char *str, size_t *i)
{
	if (*(str + *i) == '\0')
		return (0);
	while (*(str + *i) >= '0' && *(str + *i) <= '9')
		(*i)++;
	if (*(str + *i) != '\0')
		return (1);
	return (0);
}

int	validate_string(char *str)
{
	size_t	i;

	i = 0;
	if (validate_first_half(str, &i))
		return (1);
	if (validate_middle(str, &i))
		return (1);
	if (validate_second_half(str, &i))
		return (1);
	return (0);
}
