/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 08:48:49 by aklimchu          #+#    #+#             */
/*   Updated: 2024/07/17 11:34:53 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

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

int	choose_color(int count)
{
	int		i;

	if (count >= 0 && count < MAXCOUNT / 20)
		return (add_shade(0, 0x00ff6d2b));
	i = 1;
	while (i < 11)
	{
		if (count >= MAXCOUNT / 20 * i && count < MAXCOUNT / 20 * (i + 1))
			return (add_shade(0.05 * i, 0x00ff6d2b));
		i++;
	}
	while (i < 21)
	{
		if (count >= MAXCOUNT / 20 * i && count < MAXCOUNT / 20 * (i + 1))
			return (add_shade(0.05 * i, 0x00854442));
		i++;
	}
	return (0);
}
