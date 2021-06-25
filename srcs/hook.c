#include "fractol.h"

static int	ft_mouse_hook(int keycode, int x, int y, t_sys *sys)
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

static int	ft_key_hook(int keycode, t_sys *sys)
{
	if (keycode == ESC_KEY)
		ft_close(sys);
	return (0);
}

static int	ft_mouse_motion(int x, int y, t_sys *sys)
{
	if (x > WIN_WIDTH / 2 && y > WIN_HEIGHT / 2 && x % 19 == 0)
		sys->fcl.cm -= 0.05;
	else if (x > WIN_WIDTH / 2 && y < WIN_HEIGHT / 2 && x % 19 == 0)
		sys->fcl.cn += 0.05;
	else if (x < WIN_WIDTH / 2 && y > WIN_HEIGHT / 2 && x % 19 == 0)
		sys->fcl.cn -= 0.05;
	else if (x < WIN_WIDTH / 2 && y < WIN_HEIGHT / 2 && x % 19 == 0)
		sys->fcl.cm += 0.05;
	ft_choise_fractol(sys);
	ft_render(sys);
	return (0);
}

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
