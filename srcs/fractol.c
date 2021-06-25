#include "fractol.h"

void	ft_choise_fractol(t_sys *sys)
{
	int	len;

	len = ft_strlen(sys->fcl.fractol) + 1;
	if (ft_strncmp(sys->fcl.fractol, "mandelbrot", len) == 0)
		ft_mandelbrot(sys);
	else if (ft_strncmp(sys->fcl.fractol, "julia", len) == 0)
		ft_julia(sys);
}

static void	ft_init(t_sys *sys)
{
	sys->fcl.zoom = 0.50;
	sys->fcl.a = 0;
	sys->fcl.aa = 0;
	sys->fcl.b = 0;
	sys->fcl.bb = 0;
	sys->fcl.cm = 0.285;
	sys->fcl.cn = 0.01;
	sys->mlx.ptr = mlx_init();
	sys->win.ptr = mlx_new_window(sys->mlx.ptr, \
						WIN_WIDTH, WIN_HEIGHT, "fract-ol");
	sys->img.ptr = mlx_new_image(sys->mlx.ptr, WIN_WIDTH, WIN_HEIGHT);
	sys->img.data = (unsigned char *)mlx_get_data_addr(\
						sys->img.ptr, &sys->img.bits_per_pixel, \
						&sys->img.line_length, &sys->img.endian);
}

static int	ft_error_check(t_sys *sys, char **argv)
{
	size_t	len;

	len = ft_strlen(argv[1]) + 1;
	if (!(ft_malloc_p((void **)&sys->fcl.fractol, sizeof(char) * (len + 1))))
		return (1);
	if (ft_strncmp(argv[1], "mandelbrot", len) == 0)
		ft_strncpy(sys->fcl.fractol, argv[1], len);
	else if (ft_strncmp(argv[1], "julia", len) == 0)
		ft_strncpy(sys->fcl.fractol, argv[1], len);
	else
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_sys	sys;

	if (argc == 1 || argc > 2 || ft_error_check(&sys, argv) == 1)
	{
		if (sys.fcl.fractol)
			free(sys.fcl.fractol);
		printf("Fractols:\n1. mandelbrot\n2. julia\n");
		return (1);
	}
	ft_init(&sys);
	ft_hook(&sys);
	return (0);
}
