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

/* Function to check arguments for the range of colors */
static int	ft_check_color(char **argv, t_fractal *fractal)
{
	fractal->color.red = ft_atoi(argv[2]);
	if (fractal->color.red < 0 || fractal->color.red > 255)
		return (ft_instructions(), 0);
	fractal->color.green = ft_atoi(argv[3]);
	if (fractal->color.green < 0 || fractal->color.green > 255)
		return (ft_instructions(), 0);
	fractal->color.blue = ft_atoi(argv[4]);
	if (fractal->color.blue < 0 || fractal->color.blue > 255)
		return (ft_instructions(), 0);
	return (1);
}

/* Function to check arguments for the complex number */
static int	ft_check_complex(char **argv, t_fractal *fractal)
{
	if (ft_check_color(argv, fractal))
	{
		fractal->complex.real = ft_atof(argv[5]);
		if (fractal->complex.real == 0
			|| fractal->complex.real < -2.0
			|| fractal->complex.real > 2.0)
			return (ft_instructions(), 0);
		fractal->complex.imaginary = ft_atof(argv[6]);
		if (fractal->complex.imaginary == 0
			|| fractal->complex.imaginary < -2.0
			|| fractal->complex.imaginary > 2.0)
			return (ft_instructions(), 0);
		return (1);
	}
	return (0);
}

/* Function to check arguments for my program */
static int	ft_check(int argc, char **argv, t_fractal *fractal)
{
	if (argc < 2)
		return (ft_instructions(), 0);
	if (ft_strncmp(argv[1], MANDELBROT, ft_strlen(MANDELBROT)) == 0)
	{
		if (argc < 5)
			return (ft_instructions(), 0);
		return (ft_check_color(argv, fractal));
	}
	if (ft_strncmp(argv[1], JULIA, ft_strlen(JULIA)) == 0)
	{
		if (argc < 7)
			return (ft_instructions(), 0);
		return (ft_check_complex(argv, fractal));
	}
	return (0);
}

/* Function to give values to my structure */
static bool	ft_init(t_fractal *fractal, char **argv)
{
	fractal->name = argv[1];
	fractal->zoom = 1;
	fractal->center.real = (X_MAX + X_MIN) / 2.0;
	fractal->center.imaginary = (Y_MAX + Y_MIN) / 2.0;
	fractal->render = 1;
	fractal->mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", false);
	if (!fractal->mlx)
		return (0);
	fractal->image = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->image)
		return (0);
	if (mlx_image_to_window(fractal->mlx, fractal->image, 0, 0) < 0)
		return (0);
	return (1);
}

/* Font code */
int	main(int argc, char *argv[])
{
	t_fractal fractal;

	ft_memset(&fractal, 0, sizeof(t_fractal));
	if (!ft_check(argc, argv, &fractal) || !ft_init(&fractal, argv))
	{
		ft_free_fractal(&fractal);
		return (EXIT_FAILURE);
	}
	mlx_key_hook(fractal.mlx, (void *)ft_handle_key, &fractal);
	mlx_scroll_hook(fractal.mlx, (void *)ft_handle_scroll, &fractal);
	mlx_loop_hook(fractal.mlx, (void *)ft_handle_loop, &fractal);
	mlx_loop(fractal.mlx);
	ft_free_fractal(&fractal);
	return (EXIT_SUCCESS);
}
