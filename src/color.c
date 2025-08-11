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

int	ft_psycho_color(int iter, t_fractal *fractal)
{
	double	frequency;
	t_color	c;

	if (iter == MAX_ITER)
	{
		return ((0 << 24) | (0 << 16) | (0 << 8) | 225);
	}
	frequency = 0.3;
	c.red = (int)(sin(frequency * iter + 0) * 127 + fractal->color.red);
	c.green = (int)(sin(frequency * iter + 4 * M_PI / 3)
			* 127 + fractal->color.green);
	c.blue = (int)(sin(frequency * iter + 2 * M_PI / 3) * 127 + fractal->color.blue);
	return ((c.red << 24) | (c.green << 16) | (c.blue << 8) | 225);
}

int	ft_tv_color(int iter)
{
	static double	time = 0.0;
	double			frequency = 0.15;
	t_color			c;

	if (iter != MAX_ITER)
		return ((0 << 24) | (0 << 16) | (0 << 8) | 225);
	time += 0.005;
	c.red = (int)(sin(frequency * iter + time + 0) * 127 + 128);
	c.green = (int)(sin(frequency * iter + time + 2 * M_PI / 3) * 127 + 128);
	c.blue = (int)(sin(frequency * iter + time + 4 * M_PI / 3) * 127 + 128);
	if (c.red > 255)
		c.red = 255;
	if (c.red < 0)
		c.red = 0;
	if (c.green > 255)
		c.green = 255;
	if (c.green < 0)
		c.green = 0;
	if (c.blue > 255)
		c.blue = 255;
	if (c.blue < 0)
		c.blue = 0;
	return ((c.red << 24) | (c.green << 16) | (c.blue << 8) | 225);
}


int	ft_soft_color(int iter, t_fractal *fractal)
{
	t_color	c;
	double	alpha;
	double	t;

	alpha = 225;
	t = ((double)iter / 30);
	if (iter == MAX_ITER)
	{
		return ((255 << 24) | (255 << 16) | (255 << 8) | 225);

	}
	c.red = (int)(20 * (1 - t) * (1 - t) * t * t * (fractal->color.red));
	c.green = (int)(20 * (1 - t) * (1 - t) * t * t * (fractal->color.green));
	c.blue = (int)(20 * (1 - t) * (1 - t) * t * t * (fractal->color.blue));
	return ((c.red << 24) | (c.green << 16) | (c.blue << 8) | (int)alpha);
}

int	ft_soft_color_2(int iter, t_fractal *fractal)
{
	t_color	c;
	double	alpha;
	double	t;

	alpha = 225;
	t = ((double)iter / 30);
	t = 1/t;
	if (iter == MAX_ITER)
	{
		return ((0 << 24) | (0 << 16) | (0 << 8) | 225);

	}
	c.red = (int)(20 * (1 - t) * (1 - t) * t * t * (fractal->color.red));
	c.green = (int)(20 * (1 - t) * (1 - t) * t * t * (fractal->color.green));
	c.blue = (int)(20 * (1 - t) * (1 - t) * t * t * (fractal->color.blue));
	return ((c.red << 24) | (c.green << 16) | (c.blue << 8) | (int)alpha);
}

int	ft_soft_color_3(int iter, t_fractal *fractal)
{
	t_color	c;
	double	alpha;
	double	t;

	alpha = 225;
	t = ((double)iter / 30);
	if (iter == MAX_ITER)
	{
		return ((255 << 24) | (255 << 16) | (255 << 8) | 225);

	}
	c.red = (int)(20 * (1 - t) * (1 - t) * t * t * (fractal->color.red));
	c.green = (int)(20 * (1 - t) * (1 - t) * t * t * (fractal->color.green));
	c.blue = (int)(20 * (1 - t) * (1 - t) * t * t * (fractal->color.blue));
	return ((c.red << 24) | (c.green << 16) | (c.blue << 8) | (int)alpha);
}

int	ft_soft_color_4(int iter, t_fractal *fractal)
{
	t_color	c;
	double	alpha;
	double	t;

	alpha = 225;
	t = ((double)iter / 30);
	t = 1/t;
	if (iter == MAX_ITER)
	{
		return ((0 << 24) | (0 << 16) | (0 << 8) | 225);

	}
	c.red = (int)(20 * (1 - t) * (1 - t) * t * t * (fractal->color.red));
	c.green = (int)(20 * (1 - t) * (1 - t) * t * t * (fractal->color.green));
	c.blue = (int)(20 * (1 - t) * (1 - t) * t * t * (fractal->color.blue));
	return ((c.red << 24) | (c.green << 16) | (c.blue << 8) | (int)alpha);
}
