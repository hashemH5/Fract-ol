/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halbit <halbit@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 22:06:31 by halbit            #+#    #+#             */
/*   Updated: 2026/01/27 21:44:34 by halbit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void free_mlx(t_fract *mlx_ptr)
{
    if (mlx_ptr->win)
        mlx_destroy_window(mlx_ptr->mlx, mlx_ptr->win);
    if (mlx_ptr->mlx)
        mlx_destroy_display(mlx_ptr->mlx);
    free(mlx_ptr->mlx);
}

int	key_hook(int keycode, t_fract *param)
{
	(void)keycode;
	mlx_loop_end(param->mlx);
	return (0);
}
