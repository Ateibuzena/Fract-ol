/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:26:27 by azubieta          #+#    #+#             */
/*   Updated: 2024/07/17 18:26:29 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFRACTOL_H
# define LIBFRACTOL_H

# include "MLX42/MLX42.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <unistd.h>

# define HEIGHT 750
# define WIDTH 1334

# define M_PI 3.14159265358979323846

# define X_MIN -2.25
# define X_MAX 2
# define Y_MIN -1.25
# define Y_MAX 1.25

# define MAX_ITER 120

# define ZOOM_FACTOR 1.1
# define MIN_ZOOM 1.0
# define MAX_ZOOM 10000000000000000.0

# define MANDELBROT "Mandelbrot"
# define JULIA "Julia"

typedef struct s_complex
{
	double	real;
	double	imaginary;
}	t_complex;

typedef struct s_color
{
	int		red;
	int		green;
	int		blue;
	int		combined;
}	t_color;

typedef struct s_zoom
{
	int		mouse_x;
	int		mouse_y;
	double	scale_x;
	double	scale_y;
	double	mouse_r;
	double	mouse_i;
	double	prev_zoom;
}	t_zoom;

typedef struct s_fractal
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	char		*name;
	int			x;
	int			y;
	int			iter;
	double		zoom;
	double		r;
	double		i;
	t_complex	center;
	t_complex	complex;
	t_color		color;
	bool		render;
}	t_fractal;

/*Utils.c*/
void	ft_introduction(void);
void	ft_logo(void);
void	ft_instructions(void);
void	ft_copyright(void);
double	ft_atof(char *str);

/*handlers.c*/
void	ft_key_press(t_fractal *fractal, int key);
void	ft_handle_key(mlx_key_data_t keydata, void *param);
void	ft_handle_scroll(double xdelta, double ydelta, void *param);
void	ft_handle_loop(void *param);

/*draw.c*/
void	ft_clear_image(t_fractal *fractal);
void	ft_update_image(t_fractal *fractal);

/*render.c*/
int		ft_mandelbrot_iterations(double real, double imaginary, int iter);
void	ft_render_mandelbrot(t_fractal *fractal);
int		ft_julia_iterations(double real, double imaginary, t_complex c,
			int iter);
void	ft_render_julia(t_fractal *fractal);

/*color.c*/
int		ft_psycho_color(int iter, t_fractal *fractal);
int		ft_soft_color(int iter, t_fractal *fractal);

/*free.c*/
void	ft_free_fractal(t_fractal *fractal);

#endif
