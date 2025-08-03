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
		return ((0 << 24) | (0 << 16) | (0 << 8) | 225);
	frequency = 0.3;
	c.red = (int)(sin(frequency * iter + 0) * 127 + fractal->color.red);
	c.green = (int)(sin(frequency * iter + 4 * M_PI / 3)
			* 127 + fractal->color.green);
	c.blue = (int)(sin(frequency * iter + 2 * M_PI / 3) * 127 + fractal->color.blue);
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
		return ((0 << 24) | (0 << 16) | (0 << 8) | (int)alpha);
	c.red = (int)(20 * (1 - t) * (1 - t) * t * t * (fractal->color.red));
	c.green = (int)(20 * (1 - t) * (1 - t) * t * t * (fractal->color.green));
	c.blue = (int)(20 * (1 - t) * (1 - t) * t * t * (fractal->color.blue));
	return ((c.red << 24) | (c.green << 16) | (c.blue << 8) | (int)alpha);
}
