/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_shift.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 08:29:55 by aklimchu          #+#    #+#             */
/*   Updated: 2024/07/24 15:04:57 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	mouse_zoom_tools(t_dim *dim, double add_real, \
	double add_imag, double zoom);

//The function calculates zooming to mouse cursor for mandelbrot
//and julia fractals

void	mouse_zoom(t_dim *dim, int x, int y, double zoom)
{
	double	scaled_x;
	double	scaled_y;
	double	add_real;
	double	add_imag;

	dim->center_r = (dim->right_f - dim->left_f) / 2 + dim->left_f;
	dim->center_i = (dim->bottom_f - dim->top_f) / 2 + dim->top_f;
	scaled_x = (dim->center_r - x * dim->scale_r + \
		(dim->right_f - dim->left_f) / 2) / 2;
	scaled_y = (dim->center_i - y * dim->scale_i + \
		(dim->bottom_f - dim->top_f) / 2) / 2;
	if (zoom < 1)
	{
		add_real = (scaled_x - dim->center_r) * (zoom / 1.4 - 1);
		add_imag = (scaled_y - dim->center_i) * (zoom / 1.4 - 1);
	}
	if (zoom > 1)
	{
		add_real = (scaled_x - dim->center_r) * (zoom * 1.1 - 1);
		add_imag = (scaled_y - dim->center_i) * (zoom * 1.1 - 1);
	}
	mouse_zoom_tools(dim, add_real, add_imag, zoom);
}

//The function calculates new dimensions after shifting the fractal

void	shift_fract(t_vars *vars, double shiftx, double shifty)
{
	vars->dim.left_f += shiftx;
	vars->dim.right_f += shiftx;
	vars->dim.top_f += shifty;
	vars->dim.bottom_f += shifty;
	if (vars->a.x + shiftx * -200 >= 0 && \
		vars->a.y + (vars->a.y - vars->b.y) + shifty * -200 >= 0 && \
		vars->b.y + shifty * -200 < SCREEN_H && \
		vars->b.x + (vars->b.x - vars->a.x) + shiftx * -200 < SCREEN_W)
	{
		vars->a.x += shiftx * -200;
		vars->b.x += shiftx * -200;
		vars->a.y += shifty * -200;
		vars->b.y += shifty * -200;
	}
}

static void	mouse_zoom_tools(t_dim *dim, double add_real, \
	double add_imag, double zoom)
{
	dim->right_f += add_real;
	dim->left_f += add_real;
	dim->top_f += add_imag;
	dim->bottom_f += add_imag;
	dim->right_f *= zoom;
	dim->left_f *= zoom;
	dim->top_f *= zoom;
	dim->bottom_f *= zoom;
}
