/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halbit <halbit@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 22:07:21 by halbit            #+#    #+#             */
/*   Updated: 2026/02/01 00:12:11 by halbit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../include/libft/libft.h"
# include "../include/minilibx-linux/mlx.h"
# include "../include/minilibx-linux/mlx_int.h"

typedef struct s_fract
{
	char	name;
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	double	zr;
	double	zi;
	double	cr;
	double	ci;
	double	temp;
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	double	julia_re;
	double	julia_im;
	int		iter;
	int		max_iter;
	int		color;
	int		redraw;
}			t_fract;
void		julia(t_fract *fractol);
void		calc_julia(t_fract *f);
void		mandelbrot(t_fract *fractol);
void		calc_mandelbrot(t_fract *f);
void		put_pixel(t_fract *f, int x, int y, int color);
void		init(t_fract *f);
void		mass_error(void);
int			float_check(char *str);
int			loop_hook(t_fract *f);
int			mouse_zoom(int button, int x, int y, t_fract *f);
int			key_hook(int keycode, t_fract *f);
int			exit_f(t_fract *f);
int			get_color(int iter, int max_iter);
float		ft_atof(char *str);

#endif