/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   legend_functions.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 14:09:59 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/03/09 14:18:01 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_legend_visibility(t_fractol *fractol)
{
	int		boolean;
	t_list	*temp;

	temp = fractol->legend;
	boolean = (((mlx_image_t *)(temp->content))->enabled + 1) % 2;
	while (temp != NULL)
	{
		((mlx_image_t *)(temp->content))->enabled = boolean;
		temp = temp->next;
	}
	fractol->rgb_string->enabled = boolean;
}

void	clear_legend(t_fractol *fractol)
{
	t_list	*temp;
	t_list	*store;

	if (fractol->rgb_string != NULL)
		mlx_delete_image(fractol->window, fractol->rgb_string);
	temp = fractol->legend;
	if (temp != NULL)
	{
		while (temp != NULL)
		{
			store = temp;
			mlx_delete_image(fractol->window, temp->content);
			temp = temp->next;
			free(store);
		}
		fractol->legend = NULL;
	}
}
