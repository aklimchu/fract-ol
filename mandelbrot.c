/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 08:48:24 by aklimchu          #+#    #+#             */
/*   Updated: 2024/07/23 12:12:01 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fractal_man_tools(t_data *img, t_vars *vars);

int	render_man(t_vars *vars)
{
	if (vars->win == NULL)
		return (1);
	vars->dim.scale_r = (vars->dim.right_f - vars->dim.left_f) / (SCREEN_W - 1);
	vars->dim.scale_i = (vars->dim.bottom_f - vars->dim.top_f) / (SCREEN_H - 1);
	draw_rect(&vars->img, (t_rect){0, 0, SCREEN_W - 1, \
		SCREEN_H - 1, 0x0069fe48});
	vars->y = 1;
	while (vars->y <= SCREEN_H - 2)
	{
		vars->x = 1;
		while (vars->x <= SCREEN_W - 2)
		{
			vars->c.real = vars->x * vars->dim.scale_r + vars->dim.left_f;
			vars->c.imag = vars->y * vars->dim.scale_i + vars->dim.top_f;
			vars->z.real = 0;
			vars->z.imag = 0;
			fractal_man_tools(&vars->img, vars);
			vars->x++;
		}
		vars->y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}

static void	fractal_man_tools(t_data *img, t_vars *vars)
{
	int		flag_c;
	int		count;
	double	tmp_real;

	flag_c = 0;
	count = 0;
	while (count < vars->max_count)
	{
		if (vars->z.real * vars->z.real + vars->z.imag * vars->z.imag >= 4)
		{
			my_mlx_pixel_put(img, vars->x, vars->y, choose_color(vars, \
				count, vars->colors.inside, vars->colors.outside));
			flag_c = 1;
			break ;
		}
		tmp_real = vars->z.real * vars->z.real - \
			vars->z.imag * vars->z.imag + vars->c.real;
		vars->z.imag = 2 * vars->z.real * vars->z.imag + vars->c.imag;
		vars->z.real = tmp_real;
		count++;
	}
	if (flag_c == 0)
		my_mlx_pixel_put(img, vars->x, vars->y, 0x0045818e);
}
