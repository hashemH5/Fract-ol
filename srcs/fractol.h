/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halbit <halbit@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 22:07:21 by halbit            #+#    #+#             */
/*   Updated: 2026/01/27 21:43:11 by halbit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "../include/libft/libft.h"
#include "../include/minilibx-linux/mlx.h"
#include "../include/minilibx-linux/mlx_int.h"

typedef struct s_fract
{
	void	*mlx;
	void	*win;
    int		x;
	int		y;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;

    double  zr;
    double  zi;
    double  cr;
    double  ci;
    double  temp;
    int     iter;
    int     max_iter;
    int     color;

    
}               t_fract;

void free_mlx(t_fract *mlx_ptr);
int	key_hook(int keycode, t_fract *param);

#endif