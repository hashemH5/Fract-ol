/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halbit <halbit@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 21:16:42 by halbit            #+#    #+#             */
/*   Updated: 2026/02/01 00:30:42 by halbit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init(t_fract *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, 1000, 1000, "Fract-ol");
	f->img = mlx_new_image(f->mlx, 1000, 1000);
	f->addr = mlx_get_data_addr(f->img, &f->bpp, &f->line_len, &f->endian);
	f->max_iter = 100;
	f->min_re = -2.0;
	f->max_re = 2.0;
	f->min_im = -2.0;
	f->max_im = 2.0;
	f->redraw = 1;
}

int	get_color(int iter, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter >= max_iter)
		return (0x000000);
	t = (double)iter / max_iter;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

int	exit_f(t_fract *f)
{
	mlx_destroy_image(f->mlx, f->img);
	mlx_destroy_window(f->mlx, f->win);
	free(f->mlx);
	free(f);
	exit(1);
	return (0);
}

int	float_check(char *str)
{
	while (*str)
	{
		if (ft_isdigit(*str) || *str == '.' || *str == '-' || *str == '+')
			str++;
		else
			return (1);
	}
	return (0);
}

void	mass_error(void)
{
	ft_putstr_fd("Error: Invalid arguments.\n", 2);
	ft_putstr_fd("Usage:\n./fractol mandelbrot\n", 2);
	ft_putstr_fd("./fractol julia\n", 2);
	ft_putstr_fd("./fractol julia <float> <float>\n", 2);
}
