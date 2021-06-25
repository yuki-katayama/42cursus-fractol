#include "fractol.h"

int	ft_close(t_sys *sys)
{
	if (sys->win.ptr)
		mlx_destroy_window(sys->mlx.ptr, sys->win.ptr);
	if (sys->img.ptr)
		mlx_destroy_image(sys->mlx.ptr, sys->img.ptr);
	if (sys->mlx.ptr)
	{
		mlx_destroy_display(sys->mlx.ptr);
		free(sys->mlx.ptr);
	}
	if (sys->fcl.fractol)
		free(sys->fcl.fractol);
	exit(0);
	return (0);
}
