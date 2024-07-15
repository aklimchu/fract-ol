/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 08:48:28 by aklimchu          #+#    #+#             */
/*   Updated: 2024/07/15 15:20:18 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

static int	handle_keypress(int keysym, t_vars *vars)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		vars->win = NULL;
	}
	return (0);
}

static int mouse_hook(int button, int x, int y, t_vars *vars)
{
   	int a, b;
	a = x +1;
	b = y + 1;
	// delete ^^^^
	
	if (button == 4)
	    vars->zoom *= 1.1; // Zoom in
	if (button == 5)
    {
		vars->zoom /= 1.1; // Zoom out
	}
	return (0);
}

int		main(int argc, char *argv[])
{
	t_vars	vars;

	// checking the passed parameters

	if (argc == 1)
		return (0);
	
	//------------------Creating the window---------------------------
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (1);
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	if (vars.win == NULL)
	{
		mlx_destroy_display(vars.mlx);
		free(vars.mlx);
		return (1);
	}
	vars.img.img = mlx_new_image(vars.mlx, 1920, 1080);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, \
		&vars.img.line_length, &vars.img.endian);
	
	//------------------Drawing fractal-----------------------------
	if (ft_strncmp(argv[1], "Mandelbrod", ft_strlen(argv[1])) == 0 || \
		ft_strncmp(argv[1], "M", ft_strlen(argv[1])) == 0)
	{
		vars.zoom = 1.0;
		mlx_loop_hook(vars.mlx, &render_man, &vars);
	}
	if (ft_strncmp(argv[1], "Julia", ft_strlen(argv[1])) == 0 || \
		ft_strncmp(argv[1], "J", ft_strlen(argv[1])) == 0)
	{
		vars.x_jul = ft_atoi_double(argv[2]);
		vars.y_jul = ft_atoi_double(argv[3]);
		vars.zoom = 1.3;
		mlx_loop_hook(vars.mlx, &render_jul, &vars);
	}
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	//------------------Closing the window-------------------------
	mlx_hook(vars.win, KeyPress, KeyPressMask, &handle_keypress, &vars);
	mlx_hook(vars.win, DestroyNotify, StructureNotifyMask, &handle_destroy, &vars);
	mlx_loop(vars.mlx);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
}