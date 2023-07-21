/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/24 15:02:31 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/03/13 07:47:51 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42.h"
# include "libft.h"

typedef struct s_coord
{
	double	x;
	double	y;
}				t_coord;

typedef struct s_complex
{
	double	re;
	double	im;
}				t_complex;

typedef struct s_min_max
{
	int	max_power;
	int	min_power;
	int	max_iter;
	int	min_iter;
}				t_min_max;

typedef enum e_set
{
	MANDELBROT,
	BURNING_SHIP,
	TRICORN,
	MANDELBROT_POWER,
	BOAR,
	JULIA,
	JULIA_POWER
}	t_set;

typedef enum e_colour
{
	SHIFT,
	RAINBOW,
}	t_colour;

typedef struct s_fractol
{
	mlx_t		*window;
	mlx_image_t	*img;
	char		*title;
	t_coord		start;
	t_coord		end;
	double		step_x;
	double		step_y;
	double		height;
	double		width;
	double		range_x;
	double		range_y;
	int			max_iter;
	t_min_max	min_max;
	t_complex	julia_coord;
	t_set		set_id;
	double		power;
	int			colour;
	int			last_colour;
	int			rgb;
	t_colour	scheme;
	t_list		*legend;
	mlx_image_t	*rgb_string;
}				t_fractol;

typedef struct s_mouse
{
	t_coord	mouse_pos;
	double	prop_x;
	double	prop_y;
}				t_mouse;

// event functions

void	press_event(void *fractol);
void	key_event(mlx_key_data_t keydata, void *fractol);
void	scroll_event(double xdelta, double ydelta, void *fractol);
void	resize_event(int32_t width, int32_t height, void *param);

// functions used for parsing

void	parse_input(int argc, char *argv[], t_fractol *fractol);
int		validate_string(char *str);
double	atod(char *str);

// functions for fractol calculation

void	render_fractol(t_fractol *fractol);
int		calculate_mandelbrot(t_coord pixel_pos, t_fractol *mandelbrot);
int		calculate_julia(t_coord pixel_pos, t_fractol *julia);
int		calculate_burning_ship(t_coord pixel_pos, t_fractol *burning_ship);
int		calculate_mandelbrot_power(t_coord pixel_pos, t_fractol *test);
int		calculate_tricorn(t_coord pixel_pos, t_fractol *fractol);
int		calculate_julia_power(t_coord pixel_pos, t_fractol *test);
int		calculate_boar(t_coord pixel_pos, t_fractol *fractol);

// window movement functions

void	move_window(t_fractol *fractol, mlx_key_data_t keydata);
void	move_window_right(t_fractol *fractol, double jump);
void	move_window_left(t_fractol *fractol, double jump);
void	move_window_down(t_fractol *fractol, double jump);
void	move_window_up(t_fractol *fractol, double jump);

// initialization functions

void	initialize_default_fractol_struct(t_fractol *fractol);
void	initialize_window(t_fractol *fract, int argc, char *argv[]);

// iteration change functions

void	jump_iter(mlx_key_data_t keydata, t_fractol *fractol);
void	iter_change(t_fractol *fractol);

// utility functions

double	abs_val(double number);
void	list_available_parameters_and_exit(char *reason);
void	exit_fractol(void *param);
void	exit_fractol_with_error(t_fractol *fractol, char *str);

// colour functions

int		get_colour_rainbow(int iter, t_fractol *fractol);
int		get_colour_shift(int iter, t_fractol *fractol);
void	check_colours(t_fractol *fractol);
void	change_rgb(t_fractol *fractol, mlx_key_data_t keydata);
void	change_colour_scheme(t_fractol *fractol);

// legend functions

void	render_legend(t_fractol *fractol);
void	change_legend_visibility(t_fractol *fractol);
void	clear_legend(t_fractol *fractol);
void	add_current_stream(t_fractol *fractol);

#endif
