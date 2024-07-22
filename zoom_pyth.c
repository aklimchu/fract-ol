/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_pyth.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 10:52:19 by aklimchu          #+#    #+#             */
/*   Updated: 2024/07/22 14:56:01 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mouse_zoom_pyth(t_vars *vars, int x, int y, double zoom)
{
		
	/* double	scaled_x;
	double	scaled_y;
	double	add_real;
	double	add_imag;
	 */
	double	diff_x;
	double	diff_y;
	/* double	center_x;
	double	center_y; */

	printf("x: %d\n", x);	// delete all printf stuff
	printf("y: %d\n", y);
	printf("a.x: %f\n", vars->a.x);
	printf("a.y: %f\n", vars->a.y);
	printf("b.x: %f\n", vars->b.x);
	printf("b.y: %f\n", vars->b.y);
	/* dim->center_r = (dim->right_f - dim->left_f) / 2 + dim->left_f;
	dim->center_i = (dim->bottom_f - dim->top_f) / 2 + dim->top_f;
	printf("center_r: %f\n", dim->center_r);
	printf("center_i: %f\n", dim->center_i);
	scaled_x = (dim->center_r - x * dim->scale_r + (dim->right_f - dim->left_f) / 2) / 2;
	scaled_y = (dim->center_i - y * dim->scale_i + (dim->bottom_f - dim->top_f) / 2) / 2;
	printf("scaled_x: %f\n", scaled_x);
	printf("scaled_y: %f\n", scaled_y); */
	/* if (zoom < 1)
	{
		add_real = (scaled_x - dim->center_r) * (zoom / 1.4 - 1);
		add_imag = (scaled_y - dim->center_i) * (zoom / 1.4 - 1);
		printf("add_real: %f\n", add_real);
		printf("add_imag: %f\n", add_imag);
	}
	if (zoom > 1)
	{
		add_real = (scaled_x - dim->center_r) * (zoom * 1.1 - 1);
		add_imag = (scaled_y - dim->center_i) * (zoom * 1.1 - 1);
		printf("add_real: %f\n", add_real);
		printf("add_imag: %f\n", add_imag);
	}
	dim->right_f += add_real;
	dim->left_f += add_real;
	dim->top_f += add_imag;
	dim->bottom_f += add_imag; */
	
/* 	center_x = vars->a.y;
	center_y = vars->b.x;
	printf("center_x: %f\n", vars->a.y);
	printf("center_y: %f\n", vars->b.x); */
	
	diff_x = vars->b.x - vars->a.x;
	diff_y = vars->a.y - vars->b.y;
	
if (zoom < 1)
	{
		if (vars->a.x - (x - vars->a.x) * zoom / 10 > 0 && \
		vars->a.y - (y - vars->a.y) * zoom / 10 + (vars->a.y - (y - vars->a.y) * zoom / 10 - vars->b.y - (y - vars->b.y) * zoom / 10) > 0 && \
		/*vars->a.y + (vars->a.y - vars->b.y) + shifty * -200 < SCREEN_H - 200 */ \
		vars->b.y - (y - vars->b.y) * zoom / 10 < SCREEN_H && \
		vars->b.x - (x - vars->b.x) * zoom / 10 + (vars->b.x - (x - vars->b.x) * zoom / 10 - vars->a.x - (x - vars->a.x) * zoom / 10) < SCREEN_W)
		{
			vars->a.x = vars->a.x - (x - vars->a.x) * zoom / 10;
			vars->a.y = vars->a.y - (y - vars->a.y) * zoom / 10;
			vars->b.x = vars->b.x - (x - vars->b.x) * zoom / 10;
			vars->b.y = vars->b.y - (y - vars->b.y) * zoom / 10;
		}
	}
	
if (zoom > 1)
	{
		if (vars->a.x - (x - vars->a.x) / zoom / 20 > 0 && \
		vars->a.y - (y - vars->a.y) / zoom / 20 + (vars->a.y - (y - vars->a.y) / zoom / 20 - vars->b.y - (y - vars->b.y) / zoom / 20) > 0 && \
		/*vars->a.y + (vars->a.y - vars->b.y) + shifty * -200 < SCREEN_H - 200 */ \
		vars->b.y - (y - vars->b.y) / zoom / 20 < SCREEN_H && \
		vars->b.x - (x - vars->b.x) / zoom / 20 + (vars->b.x - (x - vars->b.x) / zoom / 20 - vars->a.x - (x - vars->a.x) / zoom / 20) < SCREEN_W)
		{
			vars->a.x = vars->a.x + (x - vars->a.x) / zoom / 20;
			vars->a.y = vars->a.y + (y - vars->a.y) / zoom / 20;
			vars->b.x = vars->b.x + (x - vars->b.x) / zoom / 20;
			vars->b.y = vars->b.y + (y - vars->b.y) / zoom / 20;
		}
	}

	printf("new a.x: %f\n", vars->a.x);
	printf("new a.y: %f\n", vars->a.y);
	printf("new b.x: %f\n", vars->b.x);
	printf("new b.y: %f\n", vars->b.y);
	printf("\n\n\n");
	printf("\n\n\n");


	/* if (zoom > 1)
	{
		vars->b.x -= sqrt((diff_y * diff_y + diff_x * diff_x) * (zoom - 1) / 1000);	//100
		vars->b.y -= sqrt((diff_y * diff_y + diff_x * diff_x) * (zoom - 1) / 1000);
	}
	if (zoom < 1)
	{
		vars->b.x += sqrt((diff_y * diff_y + diff_x * diff_x) * (zoom + 1) / 7600);	//760
		vars->b.y += sqrt((diff_y * diff_y + diff_x * diff_x) * (zoom + 1) / 7600);
	} */



	/* if (zoom < 1)
	{
		vars->a.x = (x - vars->a.x) * (zoom / 1.4 - 1);
		vars->a.y = (y - vars->a.y) * (zoom / 1.4 - 1);
		vars->b.x = (x - vars->b.x) * (zoom / 1.4 - 1);
		vars->b.y = (y - vars->b.x) * (zoom / 1.4 - 1);
	} */
	
	/* printf("final a.x: %f\n", vars->a.x);
	printf("final a.y: %f\n", vars->a.y);
	printf("final b.x: %f\n", vars->b.x);
	printf("final b.y: %f\n", vars->b.y); */
}