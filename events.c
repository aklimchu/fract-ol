/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 08:12:45 by aklimchu          #+#    #+#             */
/*   Updated: 2024/07/23 12:07:58 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	handle_keypress_tools(int keysym, t_vars *vars);

int	handle_keypress(int keysym, t_vars *vars)
{
	if (keysym == XK_q && vars->addtimes < MAXTIMES)
		vars->addtimes += 1;
	if (keysym == XK_Left)
		shift_fract(vars, 0.05, 0);
	if (keysym == XK_Right)
		shift_fract(vars, -0.05, 0);
	if (keysym == XK_Up)
		shift_fract(vars, 0, 0.05);
	if (keysym == XK_Down)
		shift_fract(vars, 0, -0.05);
	if (keysym == XK_z)
	{
		vars->colors.inside = 0x00854442;
		vars->colors.outside = 0x00ff6d2b;
	}
	handle_keypress_tools(keysym, vars);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	if (button == 4)
	{
		vars->max_count++;
		mouse_zoom(&vars->dim, x, y, 1 / ZOOM);
		mouse_zoom_pyth(vars, x, y, 1 / ZOOM);
	}
	if (button == 5)
	{
		if (vars->max_count > 0)
			vars->max_count--;
		mouse_zoom(&vars->dim, x, y, ZOOM);
		mouse_zoom_pyth(vars, x, y, ZOOM);
	}
	return (0);
}

static void	handle_keypress_tools(int keysym, t_vars *vars)
{
	if (keysym == XK_x)
	{
		vars->colors.inside = 0x00EF8383;
		vars->colors.outside = 0x00B3BD17;
	}
	if (keysym == XK_r)
	{
		vars->startcolor = vars->startcolor + 1000;
		vars->endcolor = vars->endcolor + 1000;
	}
	if (keysym == XK_Escape)
		free_everything(vars->img.img, vars, 0);
}
