// + headers

#include "fract-ol.h"

static void	fractal(t_data *img, double left_f, double top_f, double right_f, double bottom_f)
{
	t_complex	scale;
	t_complex	z;
	t_complex	c;
	double		tmp_real;
	int			x, y;
	int			maxx, maxy, count;
	int			flag_c;
	
	maxx = 1919;
	maxy = 1079;
	scale.real = (right_f - left_f) / maxx;
    scale.imag = (bottom_f - top_f) / maxy;
	draw_rect(img, (t_rect){0, 0, maxx, maxy, GREEN_PIXEL});
	y = 1;
	while (y <= maxy - 1)
	{
		x = 1;
		while (x <= maxx - 1)
		{
			c.real = x * scale.real + left_f;
			c.imag = y * scale.imag + top_f;
			z.real = 0;
			z.imag = 0;
			flag_c = 0;
			count = 0;
			while (count < MAXCOUNT)
			{
				if (z.real * z.real + z.imag * z.imag >= 4)
				{
					my_mlx_pixel_put(img, x, y, choose_color(count));
					flag_c = 1;
					break ;
				}
				tmp_real = z.real * z.real - z.imag * z.imag + c.real;
				z.imag = 2 * z.real * z.imag + c.imag;
				z.real = tmp_real;
				count++;
			}
			if (flag_c == 0)
				my_mlx_pixel_put(img, x, y, GREEN_PIXEL);
			x++;
		}
		y++;
	}
}

static int	render(t_vars *vars)
{
	if (vars->win == NULL)
		return (1);
	double	left_f = -2;
	double	top_f = -1;
	double	right_f = 2;
	double	bottom_f = 1;
	fractal(&vars->img, left_f, top_f, right_f, bottom_f);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
    return (0);
}

int		main()
{
	t_vars	vars;

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
	mlx_loop_hook(vars.mlx, &render, &vars);

	//------------------Closing the window-------------------------
	mlx_hook(vars.win, DestroyNotify, StructureNotifyMask, &handle_destroy, &vars);
	mlx_loop(vars.mlx);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
}