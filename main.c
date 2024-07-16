/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 08:48:28 by aklimchu          #+#    #+#             */
/*   Updated: 2024/07/16 11:57:25 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	handle_keypress(int keysym, t_vars *vars);

static int	mouse_hook(int button, int x, int y, t_vars *vars);

static void	create_window(t_vars *vars);

static void	draw_fractal(t_vars *vars, char *argv[]);

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (check_param(argc, argv) == 1)
	{
		ft_printf("Correct input format for ");
		ft_printf("Mandelbrod fractal: ./fractol Mandelbrod\n");
		ft_printf("Correct input format for ");
		ft_printf("Julia fractal: ./fractol Julia x-coordinate y-coordinate\n");
		return (0);
	}	
	create_window(&vars);
	draw_fractal(&vars, argv);
	mlx_hook(vars.win, KeyPress, KeyPressMask, &handle_keypress, &vars);
	mlx_hook(vars.win, DestroyNotify, StructureNotifyMask, \
		&handle_destroy, &vars);
	mlx_loop(vars.mlx);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
}

static int	handle_keypress(int keysym, t_vars *vars)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		vars->win = NULL;
	}
	return (0);
}

static int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	if (button == 4)
		vars->zoom /= 1.1;
	if (button == 5)
		vars->zoom *= 1.1;
	return (0);
}

static void	create_window(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		exit (EXIT_FAILURE);
	vars->win = mlx_new_window(vars->mlx, 1920, 1080, "Hello world!");
	if (vars->win == NULL)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit (EXIT_FAILURE);
	}
	vars->img.img = mlx_new_image(vars->mlx, 1920, 1080);
	vars->img.addr = mlx_get_data_addr(vars->img.img, \
		&vars->img.bits_per_pixel, &vars->img.line_length, &vars->img.endian);
}

static void	draw_fractal(t_vars *vars, char *argv[])
{
	if (ft_strncmp(argv[1], "Mandelbrod", ft_strlen(argv[1])) == 0 || \
		ft_strncmp(argv[1], "M", ft_strlen(argv[1])) == 0)
	{
		vars->zoom = 1.2;
		mlx_loop_hook(vars->mlx, &render_man, vars);
	}
	if (ft_strncmp(argv[1], "Julia", ft_strlen(argv[1])) == 0 || \
		ft_strncmp(argv[1], "J", ft_strlen(argv[1])) == 0)
	{
		vars->x_jul = ft_atoi_double(argv[2]);
		vars->y_jul = ft_atoi_double(argv[3]);
		vars->zoom = 1.3;
		mlx_loop_hook(vars->mlx, &render_jul, vars);
	}
	mlx_mouse_hook(vars->win, mouse_hook, vars);
}
