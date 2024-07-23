/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 08:48:28 by aklimchu          #+#    #+#             */
/*   Updated: 2024/07/23 09:24:00 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_info(void);

static void	create_window(t_vars *vars);

static void	initialize_values(t_vars *vars);

static void	draw_fractal(t_vars *vars, char *argv[]);

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (check_param(argc, argv) == 1)
	{
		print_info();
		exit (EXIT_FAILURE);
	}	
	create_window(&vars);
	vars.colors.inside = 0x00854442;
	vars.colors.outside = 0x00ff6d2b;
	vars.dim.left_f = -2;
	vars.dim.right_f = 2;
	vars.dim.top_f = -2;
	vars.dim.bottom_f = 2;
	initialize_values(&vars);
	draw_fractal(&vars, argv);
	mlx_hook(vars.win, DestroyNotify, StructureNotifyMask, \
		&handle_destroy, &vars);
	mlx_hook(vars.win, KeyPress, KeyPressMask, &handle_keypress, &vars);
	mlx_loop(vars.mlx);
	exit(EXIT_SUCCESS);
}

static void	print_info(void)
{
	ft_printf("Correct input for ");
	ft_printf("mandelbrot: ./fractol mandelbrot\n");
	ft_printf("Correct input for ");
	ft_printf("julia: ./fractol julia x-value y-value ");
	ft_printf("(x and y values should be between -2 and 2)\n");
	ft_printf("Correct input for ");
	ft_printf("pythagoras: ./fractol pythagoras\n\n");
	ft_printf("Controls:\n");
	ft_printf("Use mouse wheel for zooming\n");
	ft_printf("Use arrows for moving the view\n");
	ft_printf("Use z and x buttons for changing the colors ");
	ft_printf("for mandelbrot and julia fractals\n");
	ft_printf("Use q button for expanding the pythagoras tree\n");
	ft_printf("Use r button for changing the color of the pythagoras tree\n");
	ft_printf("Use Esc button or cross in the top right corner ");
	ft_printf("for exiting the program\n");
}

static void	create_window(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		exit (EXIT_FAILURE);
	vars->win = mlx_new_window(vars->mlx, SCREEN_W, SCREEN_H, "fractol");
	if (vars->win == NULL)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit (EXIT_FAILURE);
	}
	vars->img.img = mlx_new_image(vars->mlx, SCREEN_W, SCREEN_H);
	if (vars->img.img == NULL)
		free_everything(NULL, vars, 1);
	vars->img.addr = mlx_get_data_addr(vars->img.img, \
		&vars->img.bits_per_pixel, &vars->img.line_length, &vars->img.endian);
	if (vars->img.addr == NULL)
		free_everything(vars->img.img, vars, 1);
}

static void	initialize_values(t_vars *vars)
{
	vars->a.x = 0;
	vars->a.y = 0;
	vars->b.x = 0;
	vars->b.y = 0;

}

static void	draw_fractal(t_vars *vars, char *argv[])
{
	if (ft_strncmp(argv[1], "mandelbrot", ft_strlen(argv[1])) == 0 || \
		ft_strncmp(argv[1], "m", ft_strlen(argv[1])) == 0)
	{
		mlx_loop_hook(vars->mlx, &render_man, vars);
	}
	if (ft_strncmp(argv[1], "julia", ft_strlen(argv[1])) == 0 || \
		ft_strncmp(argv[1], "j", ft_strlen(argv[1])) == 0)
	{
		vars->x_jul = ft_atoi_double(argv[2]);
		vars->y_jul = ft_atoi_double(argv[3]);
		mlx_loop_hook(vars->mlx, &render_jul, vars);
	}
	if (ft_strncmp(argv[1], "pythagoras", ft_strlen(argv[1])) == 0 || \
		ft_strncmp(argv[1], "p", ft_strlen(argv[1])) == 0)
	{
		vars->addtimes = 0;
		vars->a.x = 700;
		vars->a.y = 1200;
		vars->b.x = 800;
		vars->b.y = 1300;
		vars->startcolor = 0x00562952;
		vars->endcolor = 0x00F8FA70;
		mlx_loop_hook(vars->mlx, &render_pyth, vars);
	}
	mlx_mouse_hook(vars->win, mouse_hook, vars);
}
