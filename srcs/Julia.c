/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halbit <halbit@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 23:54:06 by halbit            #+#    #+#             */
/*   Updated: 2026/02/01 00:42:11 by halbit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calc_julia(t_fract *f)
{
	f->zr = f->min_re + (double)f->x * (f->max_re - f->min_re) / 1000;
	f->zi = f->min_im + (double)f->y * (f->max_im - f->min_im) / 1000;
	f->cr = f->julia_re;
	f->ci = f->julia_im;
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

void	julia(t_fract *f)
{
	f->name = 'j';
	f->redraw = 0;
	f->y = 0;
	while (f->y < 1000)
	{
		f->x = 0;
		while (f->x < 1000)
		{
			calc_julia(f);
			put_pixel(f, f->x, f->y, f->color);
			f->x++;
		}
		f->y++;
	}
}
