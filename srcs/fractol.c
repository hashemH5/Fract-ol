/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halbit <halbit@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 19:15:00 by halbit            #+#    #+#             */
/*   Updated: 2026/02/01 00:31:17 by halbit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_f(t_fract *fractol, char **argv)
{
	if (ft_strncmp((char *)argv[1], "mandelbrot", 10) == 0)
		mandelbrot(fractol);
	else if (ft_strncmp((const char *)argv[1], "julia", 5) == 0)
	{
		if (argv[2] && argv[3])
		{
			fractol->julia_re = ft_atof(argv[2]);
			fractol->julia_im = ft_atof(argv[3]);
		}
		else
		{
			fractol->julia_re = 0.285;
			fractol->julia_im = 0.01;
		}
		julia(fractol);
	}
	else
	{
		mass_error();
		exit_f(fractol);
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_fract	*fractol;

	if (argc != 2 && argc != 4)
	{
		mass_error();
		return (0);
	}
	if (argc == 4 && (float_check(argv[2]) || float_check(argv[3])))
	{
		mass_error();
		return (0);
	}
	fractol = malloc(sizeof(t_fract));
	init(fractol);
	mlx_hook(fractol->win, 17, 0, exit_f, fractol);
	mlx_key_hook(fractol->win, key_hook, fractol);
	mlx_mouse_hook(fractol->win, mouse_zoom, fractol);
	draw_f(fractol, argv);
	mlx_loop_hook(fractol->mlx, loop_hook, fractol);
	mlx_loop(fractol->mlx);
	return (0);
}
