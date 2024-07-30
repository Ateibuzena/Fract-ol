/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:24:00 by azubieta          #+#    #+#             */
/*   Updated: 2024/07/17 18:24:01 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libfractol.h"

/* Function to give values to my structure */
void	ft_init(void *param, char **argv)
{
	t_data	*data;

	data = (t_data *)param;
	data->zoom = 1;
	data->fractal_type = argv[1];
	data->center_r = (X_MAX + X_MIN) / 2.0;
	data->center_i = (Y_MAX + Y_MIN) / 2.0;
	data->cursor_enabled = 0;
	data->cursor_x = 0;
	data->cursor_y = 0;
	data->cursor_moved = 0;
	data->last_x = -1;
	data->last_y = -1;
}

/* Font code */
int	main(int argc, char *argv[])
{
	t_data	data;

	ft_introduction();
	data.c.real = 0;
	data.c.imaginary = 0;
	if (ft_check(argc, argv, &data) == 0)
	{
		mlx_set_setting(MLX_MAXIMIZED, true);
		data.mlx = mlx_init(WIDTH, HEIGHT, "fractol", true);
		if (!data.mlx)
			return (EXIT_FAILURE);
		ft_init(&data, argv);
		ft_update_image(&data);
		mlx_set_window_size(data.mlx, WIDTH, HEIGHT);
		mlx_set_window_limit(data.mlx, 950, 950, 2160, 3120);
		mlx_key_hook(data.mlx, ft_handle_key, &data);
		mlx_scroll_hook(data.mlx, ft_handle_scroll, &data);
		mlx_resize_hook(data.mlx, ft_handle_resize, &data);
		mlx_cursor_hook(data.mlx, ft_handle_cursor, &data);
		mlx_loop_hook(data.mlx, ft_check_cursor, &data);
		mlx_loop(data.mlx);
	}
	return (EXIT_SUCCESS);
}
