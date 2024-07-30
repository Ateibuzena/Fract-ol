/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:23:35 by azubieta          #+#    #+#             */
/*   Updated: 2024/07/17 18:23:37 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libfractol.h"

int	ft_color_mandelbrot(int iter, t_data *data)
{
	double	frequency;
	int		color_red;
	int		color_green;
	int		color_blue;

	if (iter == MAX_ITER_MANDELBROT)
		return ((0 << 24) | (0 << 16) | (0 << 8) | 200);
	frequency = 0.3;
	color_red = (int)(sin(frequency * iter + 0) * 127 + data->red);
	color_green = (int)(sin(frequency * iter + 4 * M_PI / 3)
			* 127 + data->green);
	color_blue = (int)(sin(frequency * iter + 2 * M_PI / 3) * 127 + data->blue);
	return ((color_red << 24) | (color_green << 16) | (color_blue << 8) | 200);
}

int	ft_color_julia(int iter, t_data *data)
{
	int		color_red;
	int		color_green;
	int		color_blue;
	double	alpha;
	double	t;

	alpha = 200;
	t = ((double)iter / 30);
	if (iter == MAX_ITER)
		return ((0 << 24) | (0 << 16) | (0 << 8) | (int)alpha);
	color_red = (int)(20 * (1 - t) * (1 - t) * t * t * (data->red));
	color_green = (int)(20 * (1 - t) * (1 - t) * t * t * (data->green));
	color_blue = (int)(20 * (1 - t) * (1 - t) * t * t * (data->blue));
	return ((color_red << 24) | (color_green << 16) | (color_blue << 8)
		| (int)alpha);
}

/* Number of Iterations:

For each point in the complex plane, the ft_mandelbrot_iterations 
function calculates how many iterations are needed before the value of 𝑧
escapes to infinity. If 𝑧 does not escape after a maximum number of 
iterations (MAX_ITER), it is assumed that the point is in the Mandelbrot set.

Escape and Color:

·Points Inside the Set: If the number of iterations reaches the 
maximum allowed without 𝑧
z escaping, the point is typically colored with a color indicating it is 
inside the set. This is usually a fixed or very dark color.

·Points Outside the Set: If the point escapes during a specific iteration, 
the color is based on how many iterations it took for the escape to happen. 
Points that escape quickly (fewer iterations) might be colored in "hotter" 
or brighter colors, while those that escape more slowly might be colored 
with cooler or darker shades. */