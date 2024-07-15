/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:31:32 by aklimchu          #+#    #+#             */
/*   Updated: 2024/07/15 15:17:34 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

#include "./mlx_linux/mlx.h"
#include "./mlx_linux/mlx_int.h"	//delete? (Xlib.h?)
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "./libft/libft.h"

# define R(a) (a) >> 16
# define G(a) ((a) >> 8) & 0xFF
# define B(a) (a) & 0xFF
# define RGB(a, b, c) ((a) << 16) + ((b) << 8) + (c)

# define GREEN_PIXEL 0x0000FF00	//delete
# define BLACK_PIXEL 0x00000000	//delete
# define WHITE_PIXEL 0x00FFFFFF	//delete
# define RED_PIXEL	0x00FF0000	//delete
# define MAXCOUNT 30 			//delete

typedef struct  s_complex
{
    double  real;
    double  imag;
}               t_complex;

typedef struct  s_data
{
	void    *img;
	char    *addr;
	int     bits_per_pixel;
	int     line_length;
	int     endian;
}               t_data;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
	double	zoom;
	double	x_jul;
	double	y_jul;
	t_data	img;
}				t_vars;

typedef struct	s_rect
{
    int	x;
    int	y;
    int width;
    int height;
    int color;
}				t_rect;

/* The x and y coordinates of the rect corresponds to its upper left corner. */

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		handle_destroy(t_vars *vars);
int 	render_rect(t_data *img, t_rect rect);
int		draw_rect(t_data *img, t_rect rect);
int		choose_color(int count);
int		render_man(t_vars *vars);
int		render_jul(t_vars *vars);
double	ft_atoi_double(const char *str);

#endif