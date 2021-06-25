#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_WIDTH 300
# define WIN_HEIGHT 300
# define ITR_MAX 100
# define LEFT_KEY 65361
# define UP_KEY 65362
# define RIGHT_KEY 65363
# define DOWN_KEY 65364
# define ESC_KEY 65307
# define RED 0xFF0000
# define ORANGE 0x640000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define SKY_BLUE 0x000090
# define SKY 0x000072
# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define PURPLE 0xFF00FF
# define KAMONOHA 0x685B00
# define HAI 0x1E1E1E
# define YELLOW 0xFFFF00
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_mlx
{
	void	*ptr;
}				t_mlx;

typedef struct s_win
{
	void	*ptr;
}				t_win;

typedef struct s_img
{
	void			*ptr;
	unsigned char	*data;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}				t_img;

typedef struct s_fcl
{
	char	*fractol;
	double	zoom;
	double	x;
	double	y;
	double	a;
	double	aa;
	double	b;
	double	bb;
	double	twoab;
	double	cm;
	double	cn;
}				t_flc;

typedef struct s_sys
{
	t_mlx			mlx;
	t_win			win;
	t_img			img;
	t_flc			fcl;
	unsigned char	chan[3];
}				t_sys;

void	ft_mandelbrot(t_sys *sys);
void	ft_putimage(t_sys *sys, int x, int y, uint32_t color);
void	ft_render(t_sys *sys);
void	ft_hook(t_sys *sys);
void	ft_choise_fractol(t_sys *sys);
void	ft_julia(t_sys *sys);
int		ft_close(t_sys *sys);
void	ft_burningship(t_sys *sys);

#endif