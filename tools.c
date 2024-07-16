/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 08:48:36 by aklimchu          #+#    #+#             */
/*   Updated: 2024/07/16 11:42:02 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	handle_destroy(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	vars->win = NULL;
	return (0);
}

int	render_rect(t_data *img, t_rect rect)
{
	int		i;
	int		j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			my_mlx_pixel_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

int	draw_rect(t_data *img, t_rect rect)
{
	int		x;
	int		y;

	x = rect.x;
	y = rect.y;
	while (x < rect.x + rect.width)
		my_mlx_pixel_put(img, x++, y, rect.color);
	while (y < rect.y + rect.height)
		my_mlx_pixel_put(img, x, y++, rect.color);
	while (x > rect.x)
		my_mlx_pixel_put(img, x--, y, rect.color);
	while (y > rect.y)
		my_mlx_pixel_put(img, x, y--, rect.color);
	return (0);
}
