/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:10:56 by aklimchu          #+#    #+#             */
/*   Updated: 2024/07/15 15:19:22 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

static const char	*whites(const char *str)
{
	while (*str == 32 || (*str > 8 && *str < 14))
		str++;
	if (*str == 43 && *(str + 1) == 45)
		return (str);
	else if (*str == 43)
		str++;
	return (str);
}

static double add_decimals(const char *str, double res)
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

double	ft_atoi_double(const char *str)
{
	double		res;
	int			neg;
	long int	checkl;
	const char	*str_new;

	res = 0;
	neg = 1;
	checkl = 0;
	str_new = whites(str);
	if (*str_new == 45)
	{
		neg = neg * (-1);
		str_new++;
	}
	while (*str_new > 47 && *str_new < 58)
	{
		checkl = checkl * 10 + (*str_new - '0');
		if (checkl < 0 && neg == 1)
			return (-1);
		if (checkl < 0 && neg == -1)
			return (0);
		res = res * 10 + (*str_new - '0');
		str_new++;
	}
	if (*str_new == '.')
		res = add_decimals(str_new + 1, res);
	return (res * neg);
}

/* int main()
{
	printf("-0.01: %f\n", ft_atoi_double("-0.01"));
	printf("%f\n", -0.01);
	printf("0.3: %f\n", ft_atoi_double("0.3"));
	printf("3434.0005: %f\n", ft_atoi_double("3434.0005"));
	printf("-3434.1005: %f\n", ft_atoi_double("-3434.1005"));
} */