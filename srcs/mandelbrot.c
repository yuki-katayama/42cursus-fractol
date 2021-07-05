/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:41:37 by kyuki             #+#    #+#             */
/*   Updated: 2021/07/05 12:41:38 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
static void	ft_choose_put_color(t_sys *sys, double w, double h, int inter)
{
	if (inter < ITR_MAX)
	{
		if (sys->fcl.x < 0 && sys->fcl.y < 0)
			ft_putimage(sys, w, h, RED * ((double)inter) / 0.05);
		else if (sys->fcl.x < 0 && sys->fcl.y > 0)
			ft_putimage(sys, w, h, BLUE * ((double)inter) / 0.05);
		else if (sys->fcl.x > 0 && sys->fcl.y < 0)
			ft_putimage(sys, w, h, GREEN * ((double)inter) / 0.05);
		else if (sys->fcl.x > 0 && sys->fcl.y > 0)
			ft_putimage(sys, w, h, YELLOW * ((double)inter) / 0.05);
	}
	else
		ft_putimage(sys, w, h, HAI);
}

static void	ft_mandelbrot_calc(t_sys *sys)
{
	sys->fcl.aa = sys->fcl.a * sys->fcl.a;
	sys->fcl.bb = sys->fcl.b * sys->fcl.b;
	sys->fcl.twoab = 2 * sys->fcl.a * sys->fcl.b;
	sys->fcl.a = sys->fcl.aa - sys->fcl.bb + sys->fcl.x;
	sys->fcl.b = sys->fcl.twoab + sys->fcl.y;
}

static void	ft_define_place(t_sys *sys, int w, int h)
{
	sys->fcl.x = (w - WIN_WIDTH / 2) / (sys->fcl.zoom * WIN_WIDTH);
	sys->fcl.y = (h - WIN_HEIGHT / 2) / (sys->fcl.zoom * WIN_HEIGHT);
}

void	ft_mandelbrot(t_sys *sys)
{
	int		w;
	int		h;
	int		inter;

	h = -1;
	while (++h < WIN_HEIGHT)
	{
		if (sys->fcl.zoom * WIN_WIDTH < -1)
			break ;
		w = -1;
		while (++w < WIN_WIDTH)
		{
			ft_define_place(sys, w, h);
			sys->fcl.a = sys->fcl.x;
			sys->fcl.b = sys->fcl.y;
			inter = -1;
			while (++inter < ITR_MAX)
			{
				ft_mandelbrot_calc(sys);
				if (sys->fcl.aa * sys->fcl.aa + sys->fcl.bb * sys->fcl.bb > 4)
					break ;
			}
			ft_choose_put_color(sys, w, h, inter);
		}
	}
}
