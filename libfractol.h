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

/* Libreries */
# include "/home/azubieta/sgoinfre/azubieta/MLX42/include/MLX42/MLX42.h"
# include "/home/azubieta/sgoinfre/azubieta/libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <unistd.h>

/* Windows params */
# define HEIGHT 2160
# define WIDTH 3840

/* Math params */
# define M_PI 3.14159265358979323846

/* Programs params */
# define MAX_ITER_MANDELBROT 120
# define MAX_ITER 220
# define X_MIN -2.25
# define X_MAX 2
# define Y_MIN -1.25
# define Y_MAX 1.25
# define ZOOM_FACTOR 2
# define MIN_ZOOM 1
# define MAX_ZOOM 1000000.0
# define MANDELBROT "Mandelbrot"
# define JULIA "Julia"

/* Complex number */
typedef struct s_complex
{
	double	real;
	double	imaginary;
}	t_complex;

/* Fractal structure */
typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	char		*fractal_type;
	t_complex	c;
	int			y;
	int			x;
	double		r;
	double		i;
	t_complex	p;
	int			iter;
	int			color;
	int			red;
	int			green;
	int			blue;
	double		zoom;
	double		center_r;
	double		center_i;
	int			cursor_x;
	int			cursor_y;
	int			cursor_enabled;
	int			cursor_moved;
	int			last_x;
	int			last_y;
}	t_data;

/* Functions */
//UTILS.C
void		ft_introduction(void);
void		ft_logo(void);
void		ft_instructions(void);
void		ft_copyright(void);
double		ft_atof(char *str);
//COLORS.C
int			ft_color_julia(int iter, t_data *data);
int			ft_color_mandelbrot(int iter, t_data *data);
//MANDELBROT.C
int			ft_mandelbrot_iterations(double real, double imaginary, int iter);
void		ft_render_mandelbrot(t_data *data);
//JULIA.C
int			ft_julia_iterations(double real, double imaginary, t_complex c,
				int iter);
void		ft_render_julia(t_data *data);
//KEYBOARD_MOUSE_WINDOW.C
void		ft_handle_key(mlx_key_data_t keydata, void *param);
void		ft_handle_scroll(double xdelta, double ydelta, void *param);
void		ft_handle_resize(int width, int height, void *param);
void		ft_handle_cursor(double x, double y, void *param);
void		ft_check_cursor(void *param);
//CONTROL.C
void		ft_update_image(t_data *data);
void		ft_error(void);
int			ft_check(int argc, char **argv, t_data *data);
int			ft_check_color(char **argv, t_data *data);
int			ft_check_c(char **argv, t_data *data);
//MAIN.C
void		ft_init(void *param, char **argv);

#endif
