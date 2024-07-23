/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:31:32 by aklimchu          #+#    #+#             */
/*   Updated: 2024/07/23 12:18:52 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./mlx_linux/mlx.h"	//	do we need both?
# include "./mlx_linux/mlx_int.h"	//	do we need both?
# include <math.h>
# include "./libft/libft.h"

# define MAXTIMES 10
# define SCREEN_W 2000 // 1080
# define SCREEN_H 2000 // 1080
# define ZOOM 1.2

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
	double	scale_r;
	double	scale_i;
	double	right_f;
	double	left_f;
	double	bottom_f;
	double	top_f;
	double	center_r;
	double	center_i;
}				t_dim;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		color;
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
	double		x_jul;
	double		y_jul;
	t_pyth		a;
	t_pyth		b;
	t_complex	c;
	t_complex	scale;
	t_complex	z;
	t_colors	colors;
	int			startcolor;
	int			endcolor;
	int			x;
	int			y;
	int			times;
	int			addtimes;
	int			max_count;
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
int		choose_color(t_vars *vars, int count, int color_in, int color_out);
int		render_man(t_vars *vars);
int		render_jul(t_vars *vars);
double	ft_atoi_double(const char *str);
int		check_param(int argc, char *argv[]);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
void	free_everything(t_data *img, t_vars *vars, int exit_code);
int		render_pyth(t_vars *vars);
int		gradient(int startcolor, int endcolor, int len, int pos);
void	mouse_zoom(t_dim *dim, int x, int y, double zoom);
void	shift_fract(t_vars *vars, double shiftx, double shifty);
void	mouse_zoom_pyth(t_vars *vars, int x, int y, double zoom);
int		handle_keypress(int keysym, t_vars *vars);
int		mouse_hook(int button, int x, int y, t_vars *vars);

#endif /* FRACT_OL_H */