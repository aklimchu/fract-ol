/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pythagoras.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:26:03 by aklimchu          #+#    #+#             */
/*   Updated: 2024/07/18 15:13:34 by aklimchu         ###   ########.fr       */
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
	vars->a.x = 300;
	vars->a.y = 300;
	vars->b.x = 350;
	vars->b.y = 350;
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

	vars->img.color = gradient(0x00562952, 0x00F8FA70, MAXTIMES + 1, times);
	c.x = b.x - (a.y - b.y);
	c.y = b.y - (b.x - a.x);
	d.x = a.x - (a.y - b.y);
	d.y = a.y - (b.x - a.x);
	e.x = d.x + (b.x - a.x - (a.y - b.y)) / 2;
	e.y = d.y - (b.x - a.x + a.y - b.y) / 2;
	if (times > 0)
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
