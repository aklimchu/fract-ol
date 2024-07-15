/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 08:48:49 by aklimchu          #+#    #+#             */
/*   Updated: 2024/07/15 08:48:50 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

static int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

static int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

static int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

static int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

static int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static int	add_shade(double distance, int color)
{
	int	newcolor = 0;
	int	t, r, g ,b;

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
	
	/*if (count >= 0 && count < MAXCOUNT / 5)
		return (add_shade(0.2, RED_PIXEL));
	if (count >= MAXCOUNT / 5 && count < MAXCOUNT / 5 * 2)
		return (add_shade(0.4, RED_PIXEL));
	if (count >= MAXCOUNT / 5 * 2 && count < MAXCOUNT / 5 * 3)
		return (add_shade(0.6, RED_PIXEL));
	if (count >= MAXCOUNT / 5 * 3 && count < MAXCOUNT / 5 * 4)
		return (add_shade(0.8, RED_PIXEL));
	if (count >= MAXCOUNT / 5 * 4 && count <= MAXCOUNT)
		return (add_shade(1, RED_PIXEL));*/
	if (count >= 0 && count < MAXCOUNT / 20)
		return (add_shade(0, RED_PIXEL));
	i = 1;
	while (i < 21)
	{
		if (count >= MAXCOUNT / 20 * i && count < MAXCOUNT / 20 * (i + 1))
			return (add_shade(0.05 * i, RED_PIXEL));
		i++;
	}
	return (0); 
}