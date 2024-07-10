/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:31:32 by aklimchu          #+#    #+#             */
/*   Updated: 2024/07/10 10:53:09 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

#include "./mlx_linux/mlx.h"
#include "./mlx_linux/mlx_int.h"	//delete? (Xlib.h?)
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

# define R(a) (a) >> 16
# define G(a) ((a) >> 8) & 0xFF
# define B(a) (a) & 0xFF
# define RGB(a, b, c) ((a) << 16) + ((b) << 8) + (c)

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
	t_data	img;
}				t_vars;

typedef struct s_rect
{
    int	x;
    int	y;
    int width;
    int height;
    int color;
}	t_rect;

/* The x and y coordinates of the rect corresponds to its upper left corner. */

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	handle_destroy(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	vars->win = NULL;
	return (0);
}

int render_rect(t_data *img, t_rect rect)
{
	int	i;
    int j;

    i = rect.y;
    while (i < rect.y + rect.height)
    {
        j = rect.x;
        while (j < rect.x + rect.width)
            my_mlx_pixel_put(img, j++, i, rect.color);
        ++i;
    }
    return (0);
}

int	draw_rect(t_data *img, t_rect rect)
{
	int x;
	int y;
	
	x = rect.x;
	y = rect.y;
	while (x < rect.x + rect.width)
	{
		my_mlx_pixel_put(img, x, y, rect.color);
		x++;
	}
	while (y < rect.y + rect.height)
	{
		my_mlx_pixel_put(img, x, y, rect.color);
		y++;
	}
	while (x > rect.x)
	{
		my_mlx_pixel_put(img, x, y, rect.color);
		x--;
	}
	while (y > rect.y)
	{
		my_mlx_pixel_put(img, x, y, rect.color);
		y--;
	}
}

#endif