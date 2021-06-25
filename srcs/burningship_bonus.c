#include "fractol_bonus.h"
static void	ft_choose_put_color(t_sys *sys, double w, double h, int inter)
{
	if (inter < sys->fcl.itr)
		ft_putimage(sys, w, h, sys->fcl.color1 * ((double)inter));
	else
		ft_putimage(sys, w, h, sys->fcl.color2);
}

static void	ft_mandelbrot_calc(t_sys *sys)
{
	sys->fcl.aa = sys->fcl.a;
	sys->fcl.bb = sys->fcl.b;
	sys->fcl.a = sys->fcl.aa * sys->fcl.aa \
				- sys->fcl.bb * sys->fcl.bb - sys->fcl.x;
	sys->fcl.b = fabs(2 * sys->fcl.aa * sys->fcl.bb) + sys->fcl.y;
}

static void	ft_define_place(t_sys *sys, int w, int h)
{
	sys->fcl.x = (w - WIN_WIDTH / 2) / (sys->fcl.zoom * WIN_WIDTH) \
					+ sys->fcl.movex;
	sys->fcl.y = (h - WIN_HEIGHT / 2) / (sys->fcl.zoom * WIN_HEIGHT) \
					+ sys->fcl.movey;
	sys->fcl.a = sys->fcl.x;
	sys->fcl.b = sys->fcl.y;
}

void	ft_burningship(t_sys *sys)
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
			inter = -1;
			while (++inter < sys->fcl.itr)
			{
				ft_mandelbrot_calc(sys);
				if (sys->fcl.aa * sys->fcl.aa + sys->fcl.bb * sys->fcl.bb \
						> sys->fcl.em)
					break ;
			}
			ft_choose_put_color(sys, w, h, inter);
		}
	}
}
