/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:10:56 by aklimchu          #+#    #+#             */
/*   Updated: 2024/07/24 14:49:43 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static const char	*check_white_sp(const char *str);

static double	add_decimals(const char *str, double res);

//The function converts string to double data type

double	ft_atoi_double(const char *str)
{
	double		res;
	int			neg;
	const char	*str_new;

	res = 0;
	neg = 1;
	str_new = check_white_sp(str);
	if (*str_new == 45)
	{
		neg = neg * (-1);
		str_new++;
	}
	while (*str_new > 47 && *str_new < 58)
	{
		res = res * 10 + (*str_new - '0');
		str_new++;
	}
	if (*str_new == '.')
		res = add_decimals(str_new + 1, res);
	return (res * neg);
}

static const char	*check_white_sp(const char *str)
{
	while (*str == 32 || (*str > 8 && *str < 14))
		str++;
	if (*str == 43 && *(str + 1) == 45)
		return (str);
	else if (*str == 43)
		str++;
	return (str);
}

static double	add_decimals(const char *str, double res)
{
	double		i;

	i = 1;
	while (*str > 47 && *str < 58)
	{
		res = res + (*str - '0') / pow(10, i);
		str++;
		i++;
	}
	return (res);
}
