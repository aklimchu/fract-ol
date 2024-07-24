/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 08:48:36 by aklimchu          #+#    #+#             */
/*   Updated: 2024/07/24 15:01:11 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//The function puts pixel to thhe image provided

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

//The function calls the action to free the memory

int	handle_destroy(t_vars *vars)
{
	free_everything(vars->img.img, vars, 0);
	return (0);
}

//The function draws a rectangle

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

//The function frees the memory based on arguments provided

void	free_everything(t_data *img, t_vars *vars, int exit_code)
{
	if (img)
		mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	vars->win = NULL;
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	if (exit_code == 0)
		exit(EXIT_SUCCESS);
	if (exit_code == 1)
		exit(EXIT_FAILURE);
}
