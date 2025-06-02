#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>

# define HEIGHT 750
# define WIDTH 1334
# define PRE 1.022567

typedef struct s_complex
{
	double		real;
	double		imaginary;
}				t_complex;

typedef struct s_rgb
{
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
}				t_rgb;

typedef struct s_window
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	//mlx_image_t	*background;
	int			show_help;
}	t_window;

typedef struct s_fractal_info
{
	char	*name;
	int		index;  // id del fractal (mandelbrot, julia, etc.)
}	t_fractal_info;

typedef struct s_view
{
	double	zoom;
	double	move_x;
	double	move_y;
	int		max_iter;
}	t_view;

typedef struct s_pixel
{
	int			x;
	int			y;
	int			i;   // contador de iteración actual
	t_complex	z;
	t_complex	c;
}	t_pixel;

typedef struct s_zoom
{
	int32_t		mouse_x;
	int32_t		mouse_y;
	double		norm_x;
	double		norm_y;
	double		pre_zoom;
	double		post_zoom;
	double		offset_x_before;
	double		offset_y_before;
	double		offset_x_after;
	double		offset_y_after;
}	t_zoom;


typedef struct s_fractol
{
	t_window			window;
	t_rgb				rgb;
	t_fractal_info		info;
	t_view				view;
	t_pixel				pixel;
}	t_fractol;

/*fractol_parser.c*/
void			ft_instructions(void);
void			ft_check_args(int argc, char **argv, t_fractol *fractol);

/*main.c*/
void			ft_init(t_fractol *fractol);

/*fractal_error.c*/
void			ft_error(t_fractol *fractol);

/*fractal_render.c*/
//void			ft_background(t_fractol *fractol);
void			ft_update_image(t_fractol *fractol);
void			ft_mandelbrot(t_fractol *fractol);
void			ft_render_fractal(t_fractol *fractol);

/*fractol_hooks.c*/
void			ft_hook(void *param);

/*fractal_color.c*/
void			ft_put_pixel(t_fractol *fractol);


#endif
