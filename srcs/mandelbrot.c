/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halbit <halbit@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 21:10:38 by halbit            #+#    #+#             */
/*   Updated: 2026/02/01 00:41:57 by halbit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calc_mandelbrot(t_fract *f)
{
	f->zr = 0.0;
	f->zi = 0.0;
	f->cr = f->min_re + (double)f->x * (f->max_re - f->min_re) / 1000;
	f->ci = f->min_im + (double)f->y * (f->max_im - f->min_im) / 1000;
	f->iter = 0;
	while (f->zr * f->zr + f->zi * f->zi < 4.0 && f->iter < f->max_iter)
	{
		f->temp = f->zr * f->zr - f->zi * f->zi + f->cr;
		f->zi = 2.0 * f->zr * f->zi + f->ci;
		f->zr = f->temp;
		f->iter++;
	}
	f->color = get_color(f->iter, f->max_iter);
}

void	mandelbrot(t_fract *fractol)
{
	fractol->name = 'm';
	fractol->redraw = 0;
	fractol->y = 0;
	while (fractol->y < 1000)
	{
		fractol->x = 0;
		while (fractol->x < 1000)
		{
			calc_mandelbrot(fractol);
			put_pixel(fractol, fractol->x, fractol->y, fractol->color);
			fractol->x++;
		}
		fractol->y++;
	}
}
