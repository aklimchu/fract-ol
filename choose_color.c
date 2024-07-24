/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 08:48:49 by aklimchu          #+#    #+#             */
/*   Updated: 2024/07/24 14:47:01 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	create_trgb(int t, int r, int g, int b);

static int	add_shade(double distance, int color);

static int	ft_round(double num);

//The function calcilates the extent of shading based on the
///number of iterations we made to draw a point

int	choose_color(t_vars *vars, int count, int color_in, int color_out)
{
	int		i;

	if (count >= 0 && count < vars->max_count / 20)
		return (add_shade(0, color_out));
	i = 1;
	while (i < 9)
	{
		if (count >= vars->max_count / 20 * i && \
			count < vars->max_count / 20 * (i + 1))
			return (add_shade(0.05 * i, color_out));
		i++;
	}
	while (i < 21)
	{
		if (count >= vars->max_count / 20 * i && \
			count < vars->max_count / 20 * (i + 1))
			return (add_shade(0.05 * i, color_in));
		i++;
	}
	return (0);
}

//The function creates gradients for given colors

int	gradient(int startcolor, int endcolor, int len, int pos)
{
	float	increment[3];
	int		new[3];
	int		newcolor;

	increment[0] = (float)((get_r(endcolor)) - \
		(get_r(startcolor))) / (float)len;
	increment[1] = (float)((get_g(endcolor)) - \
		(get_g(startcolor))) / (float)len;
	increment[2] = (float)((get_b(endcolor)) - \
		(get_b(startcolor))) / (float)len;
	new[0] = (get_r(startcolor)) + ft_round(pos * increment[0]);
	new[1] = (get_g(startcolor)) + ft_round(pos * increment[1]);
	new[2] = (get_b(startcolor)) + ft_round(pos * increment[2]);
	newcolor = create_trgb(0, new[0], new[1], new[2]);
	return (newcolor);
}

//The program creates hexadecimal representation of color

static int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

//The function is adding shade to given color

static int	add_shade(double distance, int color)
{
	int		newcolor;
	int		t;
	int		r;
	int		g;
	int		b;

	newcolor = 0;
	if (distance == 0)
		return (color);
	t = get_t(color);
	r = get_r(color) * (1.01 - distance);
	g = get_g(color) * (1.01 - distance);
	b = get_b(color) * (1.01 - distance);
	newcolor = create_trgb(t, r, g, b);
	return (newcolor);
}

static int	ft_round(double num)
{
	int		rounded;

	rounded = (int)num;
	if (num - rounded >= .5)
		rounded++;
	return (rounded);
}
