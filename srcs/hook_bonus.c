/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:41:05 by kyuki             #+#    #+#             */
/*   Updated: 2021/07/05 12:41:06 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	ft_hook(t_sys *sys)
{
	mlx_mouse_hook(sys->win.ptr, &ft_mouse_hook, sys);
	mlx_key_hook(sys->win.ptr, &ft_key_hook, sys);
	mlx_hook(sys->win.ptr, 6, 1L << 6, &ft_mouse_motion, sys);
	mlx_hook(sys->win.ptr, 17, 1L << 17, ft_close, sys);
	ft_choise_fractol(sys);
	ft_render(sys);
	mlx_loop(sys->mlx.ptr);
}
