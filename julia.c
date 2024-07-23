/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:22:43 by aklimchu          #+#    #+#             */
/*   Updated: 2024/07/23 08:12:08 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fractal_jul_tools(t_data *img, t_vars *vars);

int	render_jul(t_vars *vars)
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
			vars->c.real = vars->x_jul;
			vars->c.imag = vars->y_jul;
			vars->z.real = vars->x * vars->dim.scale_r + vars->dim.left_f;
			vars->z.imag = vars->y * vars->dim.scale_i + vars->dim.top_f;
			fractal_jul_tools(&vars->img, vars);
			vars->x++;
		}
		vars->y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}

static void	fractal_jul_tools(t_data *img, t_vars *vars)
{
	int		flag_c;
	int		count;
	double	tmp_real;

	flag_c = 0;
	count = 0;
	while (count < MAXCOUNT)
	{
		if (vars->z.real * vars->z.real + vars->z.imag * vars->z.imag >= 4)
		{
			my_mlx_pixel_put(img, vars->x, vars->y, \
				choose_color(count, vars->colors.inside, vars->colors.outside));
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
