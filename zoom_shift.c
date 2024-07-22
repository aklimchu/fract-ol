/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_shift.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 08:29:55 by aklimchu          #+#    #+#             */
/*   Updated: 2024/07/22 13:53:55 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mouse_zoom(t_dim *dim, int x, int y, double zoom)
{
	double	scaled_x;
	double	scaled_y;
	double	add_real;
	double	add_imag;
	
	/* printf("x: %d\n", x);	// delete all printf stuff
	printf("y: %d\n", y);
	printf("left_f: %f\n", dim->left_f);
	printf("right_f: %f\n", dim->right_f);
	printf("top_f: %f\n", dim->top_f);
	printf("bottom_f: %f\n", dim->bottom_f); */
	dim->center_r = (dim->right_f - dim->left_f) / 2 + dim->left_f;
	dim->center_i = (dim->bottom_f - dim->top_f) / 2 + dim->top_f;
	/* printf("center_r: %f\n", dim->center_r);
	printf("center_i: %f\n", dim->center_i); */
	scaled_x = (dim->center_r - x * dim->scale_r + (dim->right_f - dim->left_f) / 2) / 2;
	scaled_y = (dim->center_i - y * dim->scale_i + (dim->bottom_f - dim->top_f) / 2) / 2;
	/* printf("scaled_x: %f\n", scaled_x);
	printf("scaled_y: %f\n", scaled_y); */
	if (zoom < 1)
	{
		add_real = (scaled_x - dim->center_r) * (zoom / 1.4 - 1);
		add_imag = (scaled_y - dim->center_i) * (zoom / 1.4 - 1);
		/* printf("add_real: %f\n", add_real);
		printf("add_imag: %f\n", add_imag); */
	}
	if (zoom > 1)
	{
		add_real = (scaled_x - dim->center_r) * (zoom * 1.1 - 1);
		add_imag = (scaled_y - dim->center_i) * (zoom * 1.1 - 1);
		/* printf("add_real: %f\n", add_real);
		printf("add_imag: %f\n", add_imag); */
	}
	dim->right_f += add_real;
	dim->left_f += add_real;
	dim->top_f += add_imag;
	dim->bottom_f += add_imag;
	
	dim->right_f *= zoom;
	dim->left_f *= zoom;
	dim->top_f *= zoom;
	dim->bottom_f *= zoom;
}

void	shift_fract(t_vars *vars, double shiftx, double shifty)
{
	vars->dim.left_f += shiftx;
	vars->dim.right_f += shiftx;
	vars->dim.top_f += shifty;
	vars->dim.bottom_f += shifty;
	
	printf("new d.y %f\n", vars->a.y + (vars->a.y - vars->b.y) + shifty * -200);
	printf("new c.x %f\n", vars->b.x + (vars->b.x - vars->a.x) + shiftx * -200);
	printf("new b.y %f\n", vars->b.y + shifty * -200);
	printf("\n\n\n");
	
	if (vars->a.x + shiftx * -200 >= 0 /*&& vars->b.y + shifty * -200 >= 0*/ && \
		vars->a.y + (vars->a.y - vars->b.y) + shifty * -200  >= 0 \
		/*vars->a.y + (vars->a.y - vars->b.y) + shifty * -200 < SCREEN_H - 200 */&& \
		vars->b.y + shifty * -200 < SCREEN_H && \
		vars->b.x + (vars->b.x - vars->a.x) + shiftx * -200 < SCREEN_W)
	{
		vars->a.x += shiftx * -200;
		vars->b.x += shiftx * -200;
		vars->a.y += shifty * -200;
		vars->b.y += shifty * -200;
	}
}