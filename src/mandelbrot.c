/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:24:41 by azubieta          #+#    #+#             */
/*   Updated: 2024/07/17 18:24:43 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libfractol.h"

/* Function to calculate the number of iterations needed for the point 
𝑐 (given by real and imaginary) to escape to infinity, or until a maximum 
number of iterations (MAX_ITER_MANDELBROT) is reached, 
using the Mandelbrot iteration formula: z = z² + c */
int	ft_mandelbrot_iterations(double real, double imaginary, int iter)
{
	t_complex	c;
	t_complex	z;
	double		z_real_temp;
	double		z_imag_temp;
	double		z_magnitude_squared;

	iter = 0;
	z.real = 0.0;
	z.imaginary = 0.0;
	c.real = real;
	c.imaginary = imaginary;
	z_magnitude_squared = 0.0;
	while (iter < MAX_ITER_MANDELBROT && z_magnitude_squared <= 4)
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

/* Function to generate an image of the Mandelbrot set by iterating over each 
pixel on the screen, calculating the color based on the number of Mandelbrot 
iterations, and then drawing that color onto the image. */
void	ft_render_mandelbrot(t_data *data)
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
			data->iter = ft_mandelbrot_iterations(data->r, data->i, data->iter);
			data->color = ft_color_mandelbrot(data->iter, data);
			mlx_put_pixel(data->image, data->x, data->y, data->color);
			data->x++;
		}
		data->y++;
	}
	if (mlx_image_to_window(data->mlx, data->image, 0, 0) < 0)
		ft_error();
}

/* Basic Concept of the Mandelbrot Set

The Mandelbrot set is defined for points in the complex plane using a specific 
mathematical iteration. For each point 𝑐 in the complex plane, we want 
to determine if the behavior of the iterative function: 
𝑧(𝑛 + 1) = 𝑧(𝑛)² + 𝑐 is finite or tends to infinity. Here, 𝑧 starts at 0 and 
𝑐 is the value we want to analyze.

Iterations in the Mandelbrot Set

Starting the Iteration:
We start with 𝑧(0) = 0. We iterate using the formula 𝑧(𝑛 + 1) = 𝑧(𝑛)² + 𝑐  
to compute the successive values of 𝑧

Escape Condition:
In each iteration, we calculate 𝑧(𝑛 + 1) = 𝑧(𝑛)² + 𝑐 and check the magnitude of 
𝑧(𝑛 + 1). If 𝑧(𝑛) (or 𝑧(𝑛 + 1)) has a magnitude that becomes greater than a 
certain value, in this case 2 (which means the square of the magnitude 
exceeds 4), the point 𝑐 is considered to have "escaped" and does not belong 
to the Mandelbrot set.

Properties of the Iteration

Magnitude of z:
The magnitude of a complex number z = a + bi is calculated as 
|z| = sqrt{a² + b²}. The magnitude of z becomes relevant in the iteration 
because if |z| becomes sufficiently large, it can be inferred that z  is 
escaping to infinity.

Choice of Threshold:
It has been mathematically proven that if the magnitude of z exceeds 2, 
z will diverge to infinity in subsequent iterations. This is because, 
if |z| becomes greater than 2, the magnitude of z in the next iteration 
will grow by at least the square of the previous value, and so on.

Number of Iterations:
The key to identifying if a point belongs to the Mandelbrot set is to 
observe how many iterations are needed before the value of 𝑧 escapes. 
If after a defined number of iterations (such as MAX_ITER_MANDELBROT), 
the value of 𝑧 has not escaped, we assume that the point 𝑐 probably 
belongs to the Mandelbrot set. */