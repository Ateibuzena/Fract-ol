/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_mouse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:24:31 by azubieta          #+#    #+#             */
/*   Updated: 2024/07/17 18:24:33 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libfractol.h"

/* Function to have escape event */
void	ft_handle_key(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if ((keydata.key == MLX_KEY_ESCAPE)
		&& (keydata.action == MLX_PRESS))
	{
		mlx_close_window(data->mlx);
		exit(0);
	}
	else if ((keydata.key == MLX_KEY_ENTER)
		&& (keydata.action == MLX_PRESS))
		data->cursor_enabled = !data->cursor_enabled;
}

/* Function to have the scroll event */
void	ft_handle_scroll(double xdelta, double ydelta, void *param)
{
	t_data	*data;
	int		mouse_x;
	int		mouse_y;
	double	mouse_r;
	double	mouse_i;

	data = (t_data *)param;
	mlx_get_mouse_pos(data->mlx, &mouse_x, &mouse_y);
	mouse_r = (X_MAX - X_MIN) / (data->mlx->width * data->zoom)
		* (mouse_x - data->mlx->width / 2) + data->center_r;
	mouse_i = (Y_MAX - Y_MIN) / (data->mlx->height * data->zoom)
		* (mouse_y - data->mlx->height / 2) + data->center_i;
	if (ydelta > 0 && xdelta >= 0)
		data->zoom *= ZOOM_FACTOR;
	else
		data->zoom /= ZOOM_FACTOR;
	if (data->zoom < MIN_ZOOM)
		data->zoom = MIN_ZOOM;
	if (data->zoom > MAX_ZOOM)
		data->zoom = MAX_ZOOM;
	data->center_r = mouse_r - (mouse_x - data->mlx->width / 2)
		* ((X_MAX - X_MIN) / (data->mlx->width * data->zoom));
	data->center_i = mouse_i - (mouse_y - data->mlx->height / 2)
		* (Y_MAX - Y_MIN) / (data->mlx->height * data->zoom);
	ft_update_image(data);
}

/* Function to have resize window event */
void	ft_handle_resize(int width, int height, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	data->mlx->width = width;
	data->mlx->height = height;
	ft_update_image(data);
}

/* Function to have cursor event */
void	ft_handle_cursor(double x, double y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data->cursor_enabled == 1)
	{
		data->cursor_x = (int)x;
		data->cursor_y = (int)y;
		data->cursor_moved = 1;
	}
}

/* Function to move the image with the cursor */
void	ft_check_cursor(void *param)
{
	t_data	*data;
	double	scaled_x;
	double	scaled_y;

	data = (t_data *)param;
	if (data->cursor_moved)
	{
		if (data->last_x == data->cursor_x && data->last_y == data->cursor_y)
		{
			scaled_x = (double)data->cursor_x / data->mlx->width;
			scaled_y = (double)data->cursor_y / data->mlx->height;
			data->center_r = (scaled_x - 0.5) * 4.0 / data->zoom;
			data->center_i = (scaled_y - 0.5) * 4.0 / data->zoom;
			ft_update_image(data);
			data->cursor_moved = 0;
		}
		data->last_x = data->cursor_x;
		data->last_y = data->cursor_y;
	}
}
