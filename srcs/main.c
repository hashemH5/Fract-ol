/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halbit <halbit@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 19:15:00 by halbit            #+#    #+#             */
/*   Updated: 2026/01/27 21:47:28 by halbit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void put_pixel(t_fract *f, int x, int y, int color)
{
    int    *pixel;

    pixel = (int *)(f->addr + (y * f->line_len + x * (f->bpp / 8)));
    *pixel = color;
}

void	init(t_fract *f)
{
    f->mlx = mlx_init();
    f->win = mlx_new_window(f->mlx, 1920, 1080, "Test Window");
    f->img = mlx_new_image(f->mlx, 1920, 1080);
    f->addr  = mlx_get_data_addr(f->img, &f->bpp, &f->line_len, &f->endian);
    f->max_iter = 100;
}

void mandelbrot(t_fract *f)
{
    f->zr = 0.0;
    f->zi = 0.0;
    f->cr = (f->x - 1000.0) * 4.0 / 1500.0;
    f->ci = (f->y - 540.0) * 4.0 / 1500.0;
    f->iter = 0;
    while (f->zr * f->zr + f->zi * f->zi < 4.0 && f->iter < f->max_iter)
    {
        f->temp = f->zr * f->zr - f->zi * f->zi + f->cr;
        f->zi = 2.0 * f->zr * f->zi + f->ci;
        f->zr = f->temp;
        f->iter++;
    }
    f->color = f->iter * 0xFFFFFF / 100;
}

int	main(int argc, char **argv)
{
    t_fract *fractol;

	(void)argc;
	(void)argv;
    
    fractol = malloc(sizeof(t_fract));
    init(fractol);
    fractol->y = 0;
	mlx_hook(fractol->win, 17, 0, key_hook, fractol);
	mlx_hook(fractol->win, 2, 1l << 0, key_hook, fractol);
    while (fractol->y < 1080)
    {
        fractol->x = 0;
        while (fractol->x < 1920)
        {
            mandelbrot(fractol);
                put_pixel(fractol, fractol->x, fractol->y, fractol->color);
            fractol->x++;
        }
        fractol->y++;
    }
    mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
    mlx_loop(fractol->mlx);
	free_mlx(fractol);
	free(fractol);
	return (0);
}

// 810 540
//     for (int y = 0; y < 1000; y++)
//         put_pixel(fractol->addr, (y*1920/1000), y, 0x0000FF);
//     for (int y = 0; y < 1000; y++){
//         put_pixel(fractol->addr, (y*1920/1000), 1000 - y, 0x00FF00);
//         put_pixel(fractol->addr, (y*1920/1000)+1, 1000 - y, 0x00FF00);
//         put_pixel(fractol->addr, (y*1920/1000)+2, 1000 - y, 0x0000FF);
//     }