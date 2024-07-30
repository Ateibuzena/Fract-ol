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

/* Function to control errors */
void	ft_error(void)
{
	ft_printf("%s\n", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

/* Function to check arguments for my program */
int	ft_check(int argc, char **argv, t_data *data)
{
	if (argc < 2)
		return (ft_instructions(), EXIT_FAILURE);
	if (ft_strncmp(argv[1], MANDELBROT, ft_strlen(MANDELBROT)) == 0)
	{
		if (argc < 5)
			return (ft_instructions(), EXIT_FAILURE);
		return (ft_check_color(argv, data));
	}
	if (ft_strncmp(argv[1], JULIA, ft_strlen(JULIA)) == 0)
	{
		if (argc < 7)
			return (ft_instructions(), EXIT_FAILURE);
		return (ft_check_c(argv, data));
	}
	return (EXIT_FAILURE);
}

/* Function to check arguments for the complex number */
int	ft_check_c(char **argv, t_data *data)
{
	if (ft_check_color(argv, data) == 0)
	{
		data->c.real = ft_atof(argv[5]);
		if (data->c.real == 0
			|| data->c.real < -2.0
			|| data->c.real > 2.0)
			return (ft_instructions(), EXIT_FAILURE);
		data->c.imaginary = ft_atof(argv[6]);
		if (data->c.imaginary == 0
			|| data->c.imaginary < -2.0
			|| data->c.imaginary > 2.0)
			return (ft_instructions(), EXIT_FAILURE);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

/* Function to check arguments for the range of colors */
int	ft_check_color(char **argv, t_data *data)
{
	data->red = ft_atoi(argv[2]);
	if (data->red < 0 || data->red > 255)
		return (ft_instructions(), EXIT_FAILURE);
	data->green = ft_atoi(argv[3]);
	if (data->green < 0 || data->green > 255)
		return (ft_instructions(), EXIT_FAILURE);
	data->blue = ft_atoi(argv[4]);
	if (data->blue < 0 || data->blue > 255)
		return (ft_instructions(), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/* Function to update the image */
void	ft_update_image(t_data *data)
{
	mlx_t	*mlx;
	int		len;

	len = ft_strlen(data->fractal_type);
	mlx = ((t_data *)data)->mlx;
	if (data->image)
		mlx_delete_image(mlx, data->image);
	data->image = mlx_new_image(mlx, mlx->width, mlx->height);
	if (!data->image)
		ft_error();
	if (ft_strncmp(data->fractal_type, MANDELBROT, len) == 0)
		ft_render_mandelbrot(data);
	else if (ft_strncmp(data->fractal_type, JULIA, len) == 0)
		ft_render_julia(data);
}
