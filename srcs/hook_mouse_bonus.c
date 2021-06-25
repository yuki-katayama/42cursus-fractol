#include "fractol_bonus.h"

int	ft_mouse_motion(int x, int y, t_sys *sys)
{
	if (x > WIN_WIDTH / 2 && y > WIN_HEIGHT / 2 && x % 19 == 0)
		sys->fcl.cm -= 0.05;
	else if (x > WIN_WIDTH / 2 && y < WIN_HEIGHT / 2 && x % 19 == 0)
		sys->fcl.cm += 0.05;
	else if (x < WIN_WIDTH / 2 && y > WIN_HEIGHT / 2 && x % 19 == 0)
		sys->fcl.cn -= 0.05;
	else if (x < WIN_WIDTH / 2 && y < WIN_HEIGHT / 2 && x % 19 == 0)
		sys->fcl.cn += 0.05;
	ft_choise_fractol(sys);
	ft_render(sys);
	return (0);
}

int	ft_mouse_hook(int keycode, int x, int y, t_sys *sys)
{
	if (keycode == 4)
		sys->fcl.zoom += sys->fcl.zoom * sys->fcl.zoom;
	else if (keycode == 5)
		sys->fcl.zoom -= sys->fcl.zoom * sys->fcl.zoom;
	(void)x;
	(void)y;
	ft_choise_fractol(sys);
	ft_render(sys);
	return (0);
}
