#include "fractol.h"

void	ft_putimage(t_sys *sys, int x, int y, uint32_t color)
{
	int	i;

	i = (y * sys->img.line_length + x * (sys->img.bits_per_pixel / 8));
	sys->img.data[i] = color;
	sys->img.data[++i] = color >> 8;
	sys->img.data[++i] = color >> 16;
}

void	ft_render(t_sys *sys)
{
	mlx_put_image_to_window(
		sys->mlx.ptr,
		sys->win.ptr,
		sys->img.ptr,
		0,
		0);
}
