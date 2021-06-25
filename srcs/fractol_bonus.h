#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000

# define INC_COLOR 5
# define INC_ZOOM 3.0
# define START_ITR 100

# define LEFT_KEY 65361
# define UP_KEY 65362
# define RIGHT_KEY 65363
# define DOWN_KEY 65364
# define ESC_KEY 65307
# define R_KEY 114
# define G_KEY 103
# define B_KEY 98
# define Z_KEY 122
# define X_KEY 120
# define C_KEY 99
# define E_KEY 101
# define D_KEY 100
# define I_KEY 105
# define W_KEY 119
# define S_KEY 115
# define V_KEY 118
# define K_KEY 107
# define L_KEY 108

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
# include <stdint.h> //uint
# include <stdio.h> //printf
# include <stdlib.h> // free exit
# include <math.h> //fabs

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
	char		*fractol;
	uint32_t	color1;
	uint32_t	color2;
	uint32_t	inc_color;
	double		zoom;
	double		movex;
	double		movey;
	double		x;
	double		y;
	double		a;
	double		aa;
	double		b;
	double		bb;
	double		cm;
	double		cn;
	double		twoab;
	int			itr;
	double		em;
}				t_flc;

typedef struct s_sys
{
	t_mlx			mlx;
	t_win			win;
	t_img			img;
	t_flc			fcl;
	unsigned char	chan[3];
}				t_sys;

void	ft_hook(t_sys *sys);
int		ft_close(t_sys *sys);
void	ft_putimage(t_sys *sys, int x, int y, uint32_t color);
void	ft_render(t_sys *sys);
void	ft_mandelbrot(t_sys *sys);
void	ft_julia(t_sys *sys);
void	ft_mandelbrot(t_sys *sys);
void	ft_choise_fractol(t_sys *sys);
void	ft_reset(t_sys *sys);
void	ft_burningship(t_sys *sys);
void	ft_description(void);
int		ft_mouse_motion(int x, int y, t_sys *sys);
int		ft_mouse_hook(int keycode, int x, int y, t_sys *sys);
int		ft_key_hook(int keycode, t_sys *sys);

#endif