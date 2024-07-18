/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:31:32 by aklimchu          #+#    #+#             */
/*   Updated: 2024/07/18 15:13:09 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./mlx_linux/mlx.h"
# include "./mlx_linux/mlx_int.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>	//delete
# include "./libft/libft.h"

# define MAXCOUNT 30
# define SCREEN_W 1920
# define SCREEN_H 1080

typedef struct s_complex
{
	double	real;
	double	imag;
}				t_complex;

typedef struct s_colors
{
	int	inside;
	int	outside;
}				t_colors;

typedef struct s_dim
{
	double	left_f;
	double	top_f;
	double	right_f;
	double	bottom_f;
}				t_dim;

/*typedef struct s_calc
{
	t_complex	c;
	t_complex	scale;
	t_complex	z;
	int			x;
	int			y;
	t_dim		dim;
}				t_calc;*/

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_pyth
{
	double	x;
	double	y;
}				t_pyth;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	double		zoom;
	double		x_jul;
	double		y_jul;
	t_pyth		a;
	t_pyth		b;
	t_complex	c;
	t_complex	scale;
	t_complex	z;
	t_colors	colors;
	int			x;
	int			y;
	int			times;
	int			addtimes;
	double		shiftx;
	double		shifty;
	t_dim		dim;
	t_data		img;
}				t_vars;

typedef struct s_rect
{
	int		x;
	int		y;
	int		width;
	int		height;
	int		color;
}				t_rect;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		handle_destroy(t_vars *vars);
int		render_rect(t_data *img, t_rect rect);
int		draw_rect(t_data *img, t_rect rect);
int		choose_color(int count, int color_inside, int color_outside);
int		render_man(t_vars *vars);
int		render_jul(t_vars *vars);
double	ft_atoi_double(const char *str);
int		check_param(int argc, char *argv[]);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
void 	free_everything(t_data *img, t_vars *vars, int exit_code);
int		render_pyth(t_vars *vars);

#endif /* FRACT_OL_H */