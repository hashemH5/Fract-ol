/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halbit <halbit@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 23:29:10 by halbit            #+#    #+#             */
/*   Updated: 2026/02/01 00:32:47 by halbit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	loop_hook(t_fract *f)
{
	if (f->redraw)
	{
		if (f->name == 'm')
			mandelbrot(f);
		else if (f->name == 'j')
			julia(f);
		mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
		f->redraw = 0;
	}
	return (0);
}

int	key_hook(int keycode, t_fract *f)
{
	if (keycode == 65307)
	{
		mlx_destroy_image(f->mlx, f->img);
		mlx_destroy_window(f->mlx, f->win);
		free(f->mlx);
		free(f);
		exit(1);
	}
	return (0);
}

int	mouse_zoom(int button, int x, int y, t_fract *f)
{
	double	factor;

	(void)x;
	(void)y;
	if (button == 4)
		factor = 0.8;
	else if (button == 5)
		factor = 1.25;
	else
		return (0);
	f->min_re *= factor;
	f->max_re *= factor;
	f->min_im *= factor;
	f->max_im *= factor;
	f->redraw = 1;
	return (0);
}

void	put_pixel(t_fract *f, int x, int y, int color)
{
	int	*pixel;

	pixel = (int *)(f->addr + (y * f->line_len + x * (f->bpp / 8)));
	*pixel = color;
}
