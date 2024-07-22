/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pythagoras.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:26:03 by aklimchu          #+#    #+#             */
/*   Updated: 2024/07/22 14:34:06 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	draw_line(t_data *img, t_pyth a, t_pyth b);

static void	draw_next_point(t_data *img, t_pyth a, t_pyth b, t_pyth d);

static void	fractal_pyth(t_vars *vars, t_pyth a, t_pyth b, int times);

int	render_pyth(t_vars *vars)
{
	if (vars->win == NULL)
		return (1);
	
	mlx_destroy_image(vars->mlx, vars->img.img);
	vars->img.img = mlx_new_image(vars->mlx, SCREEN_W, SCREEN_H);
	if (vars->img.img == NULL)
		free_everything(NULL, vars, 1);
	vars->img.addr = mlx_get_data_addr(vars->img.img, \
		&vars->img.bits_per_pixel, &vars->img.line_length, &vars->img.endian);
	if (vars->img.addr == NULL)
		free_everything(vars->img.img, vars, 1);

	/* vars->a.x = vars->dim.left_f;
	vars->a.y = vars->dim.top_f;
	vars->b.x = vars->dim.right_f;
	vars->b.y = vars->dim.bottom_f; */
	vars->times = (1 + vars->addtimes);
	draw_rect(&vars->img, (t_rect){0, 0, SCREEN_W - 1, \
		SCREEN_H - 1, 0x0069fe48});
	fractal_pyth(vars, vars->a, vars->b, vars->times);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}

static void	fractal_pyth(t_vars *vars, t_pyth a, t_pyth b, int times)
{
	t_pyth	c;
	t_pyth	d;
	t_pyth	e;
		
	vars->img.color = gradient(vars->startcolor, vars->endcolor, MAXTIMES + 1, times);
	c.x = b.x - (a.y - b.y);
	c.y = b.y - (b.x - a.x);
	d.x = a.x - (a.y - b.y);
	d.y = a.y - (b.x - a.x);
	e.x = d.x + (b.x - a.x - (a.y - b.y)) / 2;
	e.y = d.y - (b.x - a.x + a.y - b.y) / 2;
	if (times > 0 && a.x >= 0 && a.y >=0 && b.x >= 0 && b.y >=0 && c.x >= 0 && \
		c.y >=0 && d.x >= 0 && d.y >=0 && e.x >= 0 && e.y >=0 && \
		a.x < SCREEN_W && a.y < SCREEN_H && b.x < SCREEN_W && b.y < SCREEN_H && c.x < SCREEN_W && \
		c.y < SCREEN_H && d.x < SCREEN_W && d.y < SCREEN_H && e.x < SCREEN_W && e.y < SCREEN_H)
	{
		draw_line(&vars->img, a, b);
		draw_line(&vars->img, b, c);
		draw_line(&vars->img, d, c);
		draw_line(&vars->img, a, d);
		draw_next_point(&vars->img, a, b, d);
		fractal_pyth(vars, d, e, times - 1);
		fractal_pyth(vars, e, c, times - 1);
	}
}

static void	draw_line(t_data *img, t_pyth a, t_pyth b)
{
	double	x;
	double	y;
	double	diff_x;
	double	diff_y;
	int		pixels;

	diff_x = b.x - a.x;
	diff_y = b.y - a.y;
	pixels = sqrt(diff_x * diff_x + diff_y * diff_y);
	diff_x /= pixels;
	diff_y /= pixels;
	x = a.x;
	y = a.y;
	while (pixels)
	{
		my_mlx_pixel_put(img, x, y, img->color);
		x += diff_x;
		y += diff_y;
		--pixels;
	}
}

static void	draw_next_point(t_data *img, t_pyth a, t_pyth b, t_pyth d)
{
	double	diff_x;
	double	diff_y;
	int		pixels;

	diff_x = d.x - a.x;
	diff_y = d.y - a.y;
	pixels = sqrt(diff_x * diff_x + diff_y * diff_y);
	diff_x /= pixels;
	diff_y /= pixels;
	a.x += diff_x;
	a.y += diff_y;
	b.x += diff_x;
	b.y += diff_y;
	draw_line(img, a, b);
	if (pixels > 1)
		draw_next_point(img, a, b, d);
}
