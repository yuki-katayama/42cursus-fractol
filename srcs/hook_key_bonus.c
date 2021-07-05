/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:41:07 by kyuki             #+#    #+#             */
/*   Updated: 2021/07/05 12:41:08 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	ft_change_color(t_sys *sys, int keycode)
{
	if (keycode == R_KEY)
	{
		sys->fcl.color1 += sys->fcl.inc_color << 16;
		sys->fcl.color2 += sys->fcl.inc_color << 16;
	}
	else if (keycode == G_KEY)
	{
		sys->fcl.color1 += sys->fcl.inc_color << 8;
		sys->fcl.color2 += sys->fcl.inc_color << 8;
	}
	else if (keycode == B_KEY)
	{
		sys->fcl.color1 += sys->fcl.inc_color;
		sys->fcl.color2 += sys->fcl.inc_color;
	}
}

static void	ft_control_julia_param(t_sys *sys, int keycode)
{
	if (keycode == Z_KEY)
		sys->fcl.cm += 0.05;
	else if (keycode == X_KEY)
		sys->fcl.cm -= 0.05;
	else if (keycode == C_KEY)
		sys->fcl.cn += 0.05;
	else if (keycode == V_KEY)
		sys->fcl.cn -= 0.05;
}

static void	ft_arrow_param(t_sys *sys, int keycode)
{
	if (keycode == LEFT_KEY)
		sys->fcl.movex -= 0.05;
	else if (keycode == RIGHT_KEY)
		sys->fcl.movex += 0.05;
	else if (keycode == DOWN_KEY)
		sys->fcl.movey += 0.05;
	else if (keycode == UP_KEY)
		sys->fcl.movey -= 0.05;
}

static int	ft_another_param(int keycode, t_sys *sys)
{
	if (keycode == W_KEY)
		sys->fcl.itr += 10;
	else if (keycode == S_KEY)
		sys->fcl.itr -= 10;
	else if (keycode == E_KEY)
		sys->fcl.em += 1;
	else if (keycode == D_KEY)
		sys->fcl.em -= 0.5;
	else if (keycode == K_KEY)
		sys->fcl.zoom += sys->fcl.zoom * sys->fcl.zoom / 2;
	else if (keycode == L_KEY)
		sys->fcl.zoom -= sys->fcl.zoom * sys->fcl.zoom / 2;
	return (1);
}

int	ft_key_hook(int keycode, t_sys *sys)
{
	if (keycode == LEFT_KEY || keycode == RIGHT_KEY \
		|| keycode == DOWN_KEY || keycode == UP_KEY)
		ft_arrow_param(sys, keycode);
	else if (keycode == ESC_KEY)
		ft_close(sys);
	else if (keycode == I_KEY)
		ft_reset(sys);
	else if (keycode == R_KEY || keycode == G_KEY || keycode == B_KEY)
		ft_change_color(sys, keycode);
	else if (keycode == Z_KEY || keycode == X_KEY \
				|| keycode == C_KEY || keycode == V_KEY)
		ft_control_julia_param(sys, keycode);
	else if (keycode == W_KEY || keycode == S_KEY || keycode == E_KEY \
				|| keycode == D_KEY || keycode == K_KEY || keycode == L_KEY)
		ft_another_param(keycode, sys);
	ft_choise_fractol(sys);
	ft_render(sys);
	return (0);
}
