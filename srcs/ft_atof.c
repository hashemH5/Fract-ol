/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halbit <halbit@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 22:57:46 by halbit            #+#    #+#             */
/*   Updated: 2026/01/31 22:58:16 by halbit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static float	fl_point(char *str, float result)
{
	float	fl;

	fl = 0.1f;
	str++;
	while (*str >= '0' && *str <= '9')
	{
		result += (*str - '0') * fl;
		fl *= 0.1f;
		str++;
	}
	return (result);
}

float	ft_atof(char *str)
{
	float	result;
	float	sign;

	result = 0.0f;
	sign = 1.0f;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-')
	{
		sign = -1.0f;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		result = result * 10.0f + (*str - '0');
		str++;
	}
	if (*str == '.')
		result = fl_point(str, result);
	return (result * sign);
}
