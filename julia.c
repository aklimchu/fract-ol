/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:22:43 by aklimchu          #+#    #+#             */
/*   Updated: 2024/07/16 14:35:17 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fractal_jul_tools(t_data *img, t_calc calc);

static void	fractal_jul(t_vars *vars, t_data *img, t_calc calc);

int	render_jul(t_vars *vars)
{
	t_calc	calc;

	if (vars->win == NULL)
		return (1);
	calc.dim.left_f = -2 * vars->zoom;
	calc.dim.top_f = -1 * vars->zoom;
	calc.dim.right_f = 2 * vars->zoom;
	calc.dim.bottom_f = 1 * vars->zoom;
	calc.scale.real = (calc.dim.right_f - calc.dim.left_f) / (SCREEN_W - 1);
	calc.scale.imag = (calc.dim.bottom_f - calc.dim.top_f) / (SCREEN_H - 1);
	draw_rect(&vars->img, (t_rect){0, 0, SCREEN_W - 1, \
		SCREEN_H - 1, GREEN_PIXEL});
	fractal_jul(vars, &vars->img, calc);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}

static void	fractal_jul(t_vars *vars, t_data *img, t_calc calc)
{
	calc.y = 1;
	while (calc.y <= SCREEN_H - 2)
	{
		calc.x = 1;
		while (calc.x <= SCREEN_W - 2)
		{
			calc.c.real = vars->x_jul;
			calc.c.imag = vars->y_jul;
			calc.z.real = calc.x * calc.scale.real + calc.dim.left_f;
			calc.z.imag = calc.y * calc.scale.imag + calc.dim.top_f;
			fractal_jul_tools(img, calc);
			calc.x++;
		}
		calc.y++;
	}
}

static void	fractal_jul_tools(t_data *img, t_calc calc)
{
	int		flag_c;
	int		count;
	double	tmp_real;

	flag_c = 0;
	count = 0;
	while (count < MAXCOUNT)
	{
		if (calc.z.real * calc.z.real + calc.z.imag * calc.z.imag >= 4)
		{
			my_mlx_pixel_put(img, calc.x, calc.y, choose_color(count));
			flag_c = 1;
			break ;
		}
		tmp_real = calc.z.real * calc.z.real - \
			calc.z.imag * calc.z.imag + calc.c.real;
		calc.z.imag = 2 * calc.z.real * calc.z.imag + calc.c.imag;
		calc.z.real = tmp_real;
		count++;
	}
	if (flag_c == 0)
		my_mlx_pixel_put(img, calc.x, calc.y, GREEN_PIXEL);
}
