/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:30:54 by azubieta          #+#    #+#             */
/*   Updated: 2025/07/17 12:52:07 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libfractol.h"

void	ft_key_press(t_fractal *fractal, int key)
{
	double	move_step_x;
	double	move_step_y;

	move_step_x = (X_MAX - X_MIN) / (fractal->mlx->width * fractal->zoom) * 20;
	move_step_y = (Y_MAX - Y_MIN) / (fractal->mlx->height * fractal->zoom) * 20;
	if (key == MLX_KEY_UP)
	{
		fractal->render = 1;
		fractal->center.imaginary -= move_step_y;
	}
	else if (key == MLX_KEY_DOWN)
	{
		fractal->render = 1;
		fractal->center.imaginary += move_step_y;
	}
	else if (key == MLX_KEY_LEFT)
	{
		fractal->render = 1;
		fractal->center.real -= move_step_x;
	}
	else if (key == MLX_KEY_RIGHT)
	{
		fractal->render = 1;		
		fractal->center.real += move_step_x;
	}
	else if (key == MLX_KEY_ESCAPE)
	{
		ft_free_fractal(fractal);
		exit(EXIT_SUCCESS);
	}
}

void	ft_handle_key(mlx_key_data_t keydata, void *param)
{
	t_fractal   *fractal;

	fractal = (t_fractal *)param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
		ft_key_press(fractal, keydata.key);
}

/* Function to have the scroll event */
void	ft_handle_scroll(double xdelta, double ydelta, void *param)
{
	t_fractal	*fractal;
	t_zoom		z;

	fractal = (t_fractal *)param;
	mlx_get_mouse_pos(fractal->mlx, &z.mouse_x, &z.mouse_y);
	z.scale_x = (X_MAX - X_MIN) / (fractal->mlx->width * fractal->zoom);
	z.scale_y = (Y_MAX - Y_MIN) / (fractal->mlx->height * fractal->zoom);
	z.mouse_r = fractal->center.real + (z.mouse_x - fractal->mlx->width / 2) * z.scale_x;
	z.mouse_i = fractal->center.imaginary + (z.mouse_y - fractal->mlx->height / 2) * z.scale_y;
	z.prev_zoom = fractal->zoom;
	if (ydelta > 0 && xdelta >= 0)
		fractal->zoom *= ZOOM_FACTOR;
	else
		fractal->zoom /= ZOOM_FACTOR;
	if (fractal->zoom < MIN_ZOOM)
		fractal->zoom = MIN_ZOOM;
	else if (fractal->zoom > MAX_ZOOM)
		fractal->zoom = MAX_ZOOM;
	if (z.prev_zoom != fractal->zoom)
	{
		z.scale_x = (X_MAX - X_MIN) / (fractal->mlx->width * fractal->zoom);
		z.scale_y = (Y_MAX - Y_MIN) / (fractal->mlx->height * fractal->zoom);
		fractal->center.real = z.mouse_r - (z.mouse_x - fractal->mlx->width / 2) * z.scale_x;
		fractal->center.imaginary = z.mouse_i - (z.mouse_y - fractal->mlx->height / 2) * z.scale_y;
		fractal->render = 1;
	}
}

void	ft_handle_loop(void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	if (fractal->render)
	{
		ft_update_image(fractal);
		fractal->render = 0;
	}
}
