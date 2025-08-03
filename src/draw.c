/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:24:20 by azubieta          #+#    #+#             */
/*   Updated: 2024/07/17 18:24:24 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libfractol.h"

void	ft_clear_image(t_fractal *fractal)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_put_pixel(fractal->image, x, y, 0x000000FF);
			x++;
		}
		y++;
	}
}

/* Function to update the image */
void	ft_update_image(t_fractal *fractal)
{
	mlx_t	*mlx;
	int		len;

	mlx = ((t_fractal *)fractal)->mlx;
	len = ft_strlen(fractal->name);
	ft_clear_image(fractal);
	if (ft_strncmp(fractal->name, MANDELBROT, len) == 0)
		ft_render_mandelbrot(fractal);
	else if (ft_strncmp(fractal->name, JULIA, len) == 0)
		ft_render_julia(fractal);
}
