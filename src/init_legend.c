/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_legend.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/08 09:02:42 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/03/13 07:45:18 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	get_legend_strings(char **str)
{
	str[0] = "'cmd' or 'ctrl' + [] or u,i - inc/dec by bigger amounts";
	str[1] = "'[' and ']' - inc/dec power";
	str[2] = "'u' and 'i' - inc/dec iterations";
	str[3] = "'esc' - quit program";
	str[4] = "'R' - reset fractal";
	str[5] = "'+' or '-' - adjust current stream";
	str[6] = "cmd '+' or '-' - change current stream";
	str[7] = "tab - change colour scheme";
	str[8] = "arrow keys or WASD - move window";
	str[9] = "1-7 - change generated fractal";
	str[10] = "'H' - hide/unhide legend";
	str[11] = NULL;
}

static void	create_legend_node(t_fractol *fractol, char *str, int i)
{
	mlx_image_t	*new_img;
	t_list		*new;
	int			spot;

	spot = fractol->height - 20 * (i + 1);
	new_img = mlx_put_string(fractol->window, str, 0, spot);
	if (new_img == NULL)
		exit_fractol_with_error(fractol, "failed to create image\n");
	new = ft_lstnew(new_img);
	if (new == NULL)
	{
		mlx_delete_image(fractol->window, new_img);
		exit_fractol_with_error(fractol, "memory allocation failure\n");
	}
	ft_lstadd_back(&(fractol->legend), new);
}

void	add_current_stream(t_fractol *fractol)
{
	if (fractol->rgb_string != NULL)
		mlx_delete_image(fractol->window, fractol->rgb_string);
	if (fractol->rgb == 8)
		fractol->rgb_string = mlx_put_string(fractol->window, \
		"current stream : blue", 0, 0);
	else if (fractol->rgb == 16)
		fractol->rgb_string = mlx_put_string(fractol->window, \
		"current stream : green", 0, 0);
	else if (fractol->rgb == 24)
		fractol->rgb_string = mlx_put_string(fractol->window, \
		"current stream : red", 0, 0);
	if (fractol->rgb_string == NULL)
		exit_fractol_with_error(fractol, "failed to create image\n");
}

void	render_legend(t_fractol *fractol)
{
	char		*str[12];
	int			i;

	get_legend_strings(str);
	i = 0;
	while (*(str + i) != NULL)
	{
		create_legend_node(fractol, *(str + i), i);
		i++;
	}
	add_current_stream(fractol);
}
