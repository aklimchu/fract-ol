/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_pyth.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 10:52:19 by aklimchu          #+#    #+#             */
/*   Updated: 2024/07/23 09:06:20 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	zoom_tools(t_vars *vars, int x, int y, double zoom);

static int	zoom_tools_2(t_vars *vars, int x, int y, double zoom);

void	mouse_zoom_pyth(t_vars *vars, int x, int y, double zoom)
{
	double	diff_x;
	double	diff_y;

	diff_x = vars->b.x - vars->a.x;
	diff_y = vars->a.y - vars->b.y;
	if (zoom < 1 && zoom_tools(vars, x, y, zoom) == 0)
	{
		vars->a.x = vars->a.x - (x - vars->a.x) * zoom / 10;
		vars->a.y = vars->a.y - (y - vars->a.y) * zoom / 10;
		vars->b.x = vars->b.x - (x - vars->b.x) * zoom / 10;
		vars->b.y = vars->b.y - (y - vars->b.y) * zoom / 10;
	}
	if (zoom > 1 && zoom_tools_2(vars, x, y, zoom) == 0)
	{
		vars->a.x = vars->a.x + (x - vars->a.x) / zoom / 20;
		vars->a.y = vars->a.y + (y - vars->a.y) / zoom / 20;
		vars->b.x = vars->b.x + (x - vars->b.x) / zoom / 20;
		vars->b.y = vars->b.y + (y - vars->b.y) / zoom / 20;
	}
}

static int	zoom_tools(t_vars *vars, int x, int y, double zoom)
{
	if (vars->a.x - (x - vars->a.x) * zoom / 10 > 0 && \
		vars->a.y - (y - vars->a.y) * zoom / 10 + \
		(vars->a.y - (y - vars->a.y) * zoom / 10 - vars->b.y - \
		(y - vars->b.y) * zoom / 10) > 0 && \
		vars->b.y - (y - vars->b.y) * zoom / 10 < SCREEN_H && \
		vars->b.x - (x - vars->b.x) * zoom / 10 + (vars->b.x - \
		(x - vars->b.x) * zoom / 10 - vars->a.x - (x - vars->a.x) \
		* zoom / 10) < SCREEN_W)
		return (0);
	return (1);
}

static int	zoom_tools_2(t_vars *vars, int x, int y, double zoom)
{
	if (vars->a.x - (x - vars->a.x) / zoom / 20 > 0 && \
		vars->a.y - (y - vars->a.y) / zoom / 20 + (vars->a.y - \
		(y - vars->a.y) / zoom / 20 - vars->b.y - (y - vars->b.y) \
		/ zoom / 20) > 0 && \
		vars->b.y - (y - vars->b.y) / zoom / 20 < SCREEN_H && \
		vars->b.x - (x - vars->b.x) / zoom / 20 + (vars->b.x - \
		(x - vars->b.x) / zoom / 20 - vars->a.x - (x - vars->a.x) \
		/ zoom / 20) < SCREEN_W)
		return (0);
	return (1);
}
