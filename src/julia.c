/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:23:46 by azubieta          #+#    #+#             */
/*   Updated: 2024/07/17 18:23:48 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libfractol.h"

/* Julia Set: It is defined using the same iterative equation 
𝑧(𝑛 + 1) = z(n)² + 𝑐 where 𝑧 starts at each point in the complex plane and 
𝑐 is a fixed value. A point belongs to the Julia set associated with 𝑐 if 
the sequence generated does not tend to infinity. */

/* Function to compute the color of each pixel
using Mandelbrot function z = z^2 + c */
int	ft_julia_iterations(double real, double imaginary, t_complex c, int iter)
{
	t_complex	z;
	double		z_real_temp;
	double		z_imag_temp;
	double		z_magnitude_squared;

	iter = 0;
	z.real = real;
	z.imaginary = imaginary;
	z_magnitude_squared = 0.0;
	while (iter < MAX_ITER && z_magnitude_squared <= 4)
	{
		z_real_temp = (z.real * z.real) - (z.imaginary * z.imaginary) + c.real;
		z_imag_temp = (2.0 * (z.real * z.imaginary)) + c.imaginary;
		z.real = z_real_temp;
		z.imaginary = z_imag_temp;
		z_magnitude_squared = (z.real * z.real) + (z.imaginary * z.imaginary);
		iter++;
	}
	return (iter);
}

/* Function to generate an image of the Julia set by iterating over each 
pixel on the screen, calculating the color based on the number of Mandelbrot 
iterations, and then drawing that color onto the image. */
void	ft_render_julia(t_data *data)
{
	data->y = 0;
	while (data->y < data->mlx->height)
	{
		data->x = 0;
		while (data->x < data->mlx->width)
		{
			data->r = data->center_r
				+ (data->x - data->mlx->width / 2)
				* (X_MAX - X_MIN) / (data->mlx->width * data->zoom);
			data->i = data->center_i
				+ (data->y - data->mlx->height / 2)
				* (Y_MAX - Y_MIN) / (data->mlx->height * data->zoom);
			data->iter = ft_julia_iterations(data->r,
					data->i, data->c, data->iter);
			data->color = ft_color_julia(data->iter, data);
			mlx_put_pixel(data->image, data->x, data->y, data->color);
			data->x++;
		}
		data->y++;
	}
	if (mlx_image_to_window(data->mlx, data->image, 0, 0) < 0)
		ft_error();
}
