/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 08:48:28 by aklimchu          #+#    #+#             */
/*   Updated: 2024/07/18 15:14:03 by aklimchu         ###   ########.fr       */
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
		ft_printf("Correct input for ");
		ft_printf("mandelbrot: ./fractol mandelbrot\n");
		ft_printf("Correct input for ");
		ft_printf("julia: ./fractol julia x-value y-value ");
		ft_printf("(x and y values should be between -2 and 2)\n");
		ft_printf("Correct input for ");
		ft_printf("pythagoras: ./fractol pythagoras\n");
		exit (EXIT_FAILURE);
	}	
	create_window(&vars);
	vars.colors.inside = 0x00854442;
	vars.colors.outside = 0x00ff6d2b;
	vars.dim.left_f = -2;
	vars.dim.right_f = 2;
	vars.dim.top_f = -2;
	vars.dim.bottom_f = 2;
	draw_fractal(&vars, argv);
	mlx_hook(vars.win, DestroyNotify, StructureNotifyMask, \
		&handle_destroy, &vars);
	mlx_hook(vars.win, KeyPress, KeyPressMask, &handle_keypress, &vars);
	mlx_loop(vars.mlx);
	exit(EXIT_SUCCESS);
}

static int	handle_keypress(int keysym, t_vars *vars)
{
	if (keysym == XK_q && vars->addtimes < MAXTIMES)
		vars->addtimes += 1;
	if (keysym == XK_Left)
		shift_fract(&vars->dim, 0.1, 0);
	if (keysym == XK_Right)
		shift_fract(&vars->dim, -0.1, 0);
	if (keysym == XK_Up)
		shift_fract(&vars->dim, 0, 0.1);
	if (keysym == XK_Down)
		shift_fract(&vars->dim, 0, -0.1);
	if (keysym == XK_z)
	{
		vars->colors.inside = 0x00854442;
		vars->colors.outside = 0x00ff6d2b;
		printf("%d\n", vars->colors.inside);	// delete
	}
	if (keysym == XK_x)
	{
		vars->colors.inside = 0x00EF8383;
		vars->colors.outside = 0x00B3BD17;
		printf("%d\n", vars->colors.inside);	// delete
	}	
	if (keysym == XK_Escape)
		free_everything(vars->img.img, vars, 0);
	return (0);
}

static int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	/* (void)x;
	(void)y; */
	if (button == 4)
	{
		/* printf("%d %d\n", x, y);	// delete
		printf("%f\n", vars->dim.scale_r);	// delete
		printf("%f\n", vars->dim.left_f);	// delete
		printf("%f\n", vars->dim.right_f);	// delete */
		
	//	if (fabs(x * vars->dim.scale_r + vars->dim.left_f - vars->dim.left_f) <= fabs(vars->dim.right_f - x * vars->dim.scale_r - vars->dim.left_f))
//			vars->shiftx = vars->shiftx - fabs(x * vars->dim.scale_r /* + vars->dim.left_f */ - vars->dim.left_f) / 20 /* * vars->zoom */ ;
//		if (fabs(x * vars->dim.scale_r + vars->dim.left_f - vars->dim.left_f) > fabs(vars->dim.right_f - x * vars->dim.scale_r - vars->dim.left_f))
//			vars->shiftx = vars->shiftx + fabs(x * vars->dim.scale_r /* + vars->dim.left_f */ - vars->dim.right_f) / 20  /* * vars->zoom */ ;
//		if (fabs(y * vars->dim.scale_i + vars->dim.top_f - vars->dim.top_f) <= fabs(vars->dim.bottom_f - y * vars->dim.scale_i - vars->dim.top_f))
//			vars->shifty = vars->shifty - fabs(y * vars->dim.scale_i /* + vars->dim.top_f */ - vars->dim.top_f) / 20  /* * vars->zoom */ ;
//		if (fabs(y * vars->dim.scale_i + vars->dim.top_f - vars->dim.top_f) > fabs(vars->dim.bottom_f - y * vars->dim.scale_i - vars->dim.top_f))
//			vars->shifty = vars->shifty + fabs(y * vars->dim.scale_i /* + vars->dim.top_f */ - vars->dim.bottom_f) / 20  /* * vars->zoom */ ;
	//	vars->zoom /= 1.1;
		mouse_zoom(&vars->dim, x, y, ZOOM);
	}
	if (button == 5)
	{
//		if (fabs(x * vars->dim.scale_r + vars->dim.left_f - vars->dim.left_f) <= fabs(vars->dim.right_f - x * vars->dim.scale_r - vars->dim.left_f))
//			vars->shiftx = vars->shiftx + fabs(x * vars->dim.scale_r /*+ vars->dim.left_f*/ - vars->dim.left_f) / 20;
//		if (fabs(x * vars->dim.scale_r + vars->dim.left_f - vars->dim.left_f) > fabs(vars->dim.right_f - x * vars->dim.scale_r - vars->dim.left_f))
//			vars->shiftx = vars->shiftx - fabs(x * vars->dim.scale_r /*+ vars->dim.left_f*/ - vars->dim.right_f) / 20;
//		if (fabs(y * vars->dim.scale_i + vars->dim.top_f - vars->dim.top_f) <= fabs(vars->dim.bottom_f - y * vars->dim.scale_i - vars->dim.top_f))
//			vars->shifty = vars->shifty + fabs(y * vars->dim.scale_i /*+ vars->dim.top_f*/ - vars->dim.top_f) / 20;
//		if (fabs(y * vars->dim.scale_i + vars->dim.top_f - vars->dim.top_f) > fabs(vars->dim.bottom_f - y * vars->dim.scale_i - vars->dim.top_f))
//			vars->shifty = vars->shifty - fabs(y * vars->dim.scale_i /*+ vars->dim.left_f*/ - vars->dim.bottom_f) / 20;
	//	vars->zoom *= 1.1;
		mouse_zoom(&vars->dim, x, y, 1 / ZOOM);
	}
	return (0);
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
		mlx_loop_hook(vars->mlx, &render_pyth, vars);
	}
	mlx_mouse_hook(vars->win, mouse_hook, vars);
}
