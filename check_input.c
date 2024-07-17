/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:17:30 by aklimchu          #+#    #+#             */
/*   Updated: 2024/07/17 09:57:51 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	check_double(char *str)
{
	int		flag_dot;

	if (*str == 45 || *str == 43)
		str++;
	if (*str == 46)
		return (1);
	flag_dot = 0;
	while (*str)
	{
		if (*str < 48 || *str > 57)
		{
			if (*str == 46 && flag_dot == 0)
				flag_dot = 1;
			else
				return (1);
		}
		str++;
	}
	return (0);
}

int	check_param(int argc, char *argv[])
{
	if (argc == 1 || argc > 4)
		return (1);
	if ((ft_strncmp(argv[1], "Mandelbrod", ft_strlen(argv[1])) == 0 || \
		ft_strncmp(argv[1], "M", ft_strlen(argv[1])) == 0) && argc == 2)
		return (0);
	if ((ft_strncmp(argv[1], "Julia", ft_strlen(argv[1])) == 0 || \
		ft_strncmp(argv[1], "J", ft_strlen(argv[1])) == 0) && argc == 4)
	{
		if (check_double(argv[2]) == 0 && check_double(argv[3]) == 0 \
		&& ft_atoi_double(argv[2]) >= -2 && ft_atoi_double(argv[2]) <= 2 \
		&& ft_atoi_double(argv[23]) >= -2 && ft_atoi_double(argv[3]) <= 2)
			return (0);
	}
	return (1);
}
