/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 08:48:24 by aklimchu          #+#    #+#             */
/*   Updated: 2024/07/15 14:04:45 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

static void	fractal_man(t_data *img, double left_f, double top_f, double right_f, double bottom_f)
{
	t_complex	scale;
	t_complex	z;
	t_complex	c;
	double		tmp_real;
	int			x, y;
	int			maxx, maxy, count;
	int			flag_c;
	
	maxx = 1919;
	maxy = 1079;
	scale.real = (right_f - left_f) / maxx;
    scale.imag = (bottom_f - top_f) / maxy;
	draw_rect(img, (t_rect){0, 0, maxx, maxy, GREEN_PIXEL});
	y = 1;
	while (y <= maxy - 1)
	{
		x = 1;
		while (x <= maxx - 1)
		{
			c.real = x * scale.real + left_f;
			c.imag = y * scale.imag + top_f;
			z.real = 0;
			z.imag = 0;
			flag_c = 0;
			count = 0;
			while (count < MAXCOUNT)
			{
				if (z.real * z.real + z.imag * z.imag >= 4)
				{
					my_mlx_pixel_put(img, x, y, choose_color(count));
					flag_c = 1;
					break ;
				}
				tmp_real = z.real * z.real - z.imag * z.imag + c.real;
				z.imag = 2 * z.real * z.imag + c.imag;
				z.real = tmp_real;
				count++;
			}
			if (flag_c == 0)
				my_mlx_pixel_put(img, x, y, GREEN_PIXEL);
			x++;
		}
		y++;
	}
}

int	render_man(t_vars *vars)
{
	if (vars->win == NULL)
		return (1);
	double	left_f = -2 * vars->zoom;
	double	top_f = -1 * vars->zoom;
	double	right_f = 2 * vars->zoom;
	double	bottom_f = 1 * vars->zoom;
	fractal_man(&vars->img, left_f, top_f, right_f, bottom_f);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
    return (0);
}

static void	fractal_jul(t_vars *vars, double left_f, double top_f, double right_f, double bottom_f)
{
	t_complex	scale;
	t_complex	z;
	t_complex	c;
	double		tmp_real;
	int			x, y;
	int			maxx, maxy, count;
	int			flag_c;
	
	maxx = 1919;
	maxy = 1079;
	scale.real = (right_f - left_f) / maxx;
    scale.imag = (bottom_f - top_f) / maxy;
	draw_rect(&vars->img, (t_rect){0, 0, maxx, maxy, GREEN_PIXEL});
	y = 1;
	while (y <= maxy - 1)
	{
		x = 1;
		while (x <= maxx - 1)
		{
			c.real = vars->x_jul;
			c.imag = vars->y_jul;
			z.real = x * scale.real + left_f;
			z.imag = y * scale.imag + top_f;
			flag_c = 0;
			count = 0;
			while (count < MAXCOUNT)
			{
				if (z.real * z.real + z.imag * z.imag >= 4)
				{
					my_mlx_pixel_put(&vars->img, x, y, choose_color(count));
					flag_c = 1;
					break ;
				}
				tmp_real = z.real * z.real - z.imag * z.imag + c.real;
				z.imag = 2 * z.real * z.imag + c.imag;
				z.real = tmp_real;
				count++;
			}
			if (flag_c == 0)
				my_mlx_pixel_put(&vars->img, x, y, GREEN_PIXEL);
			x++;
		}
		y++;
	}
}

int	render_jul(t_vars *vars)
{
	if (vars->win == NULL)
		return (1);
	double	left_f = -2 * vars->zoom;
	double	top_f = -1 * vars->zoom;
	double	right_f = 2 * vars->zoom;
	double	bottom_f = 1 * vars->zoom;
	fractal_jul(vars, left_f, top_f, right_f, bottom_f);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
    return (0);
}