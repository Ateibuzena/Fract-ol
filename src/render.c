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
	while (iter < MAX_ITER && z_magnitude_squared <= 4)
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
/*void	ft_render_mandelbrot(t_fractal *fractal)
{
	fractal->y = 0;
	while (fractal->y < fractal->mlx->height)
	{
		fractal->x = 0;
		while (fractal->x < fractal->mlx->width)
		{
			fractal->r = fractal->center_r
				+ (fractal->x - fractal->mlx->width / 2)
				* (X_MAX - X_MIN) / (fractal->mlx->width * fractal->zoom);
			fractal->i = fractal->center_i
				+ (fractal->y - fractal->mlx->height / 2)
				* (Y_MAX - Y_MIN) / (fractal->mlx->height * fractal->zoom);
			fractal->iter = ft_mandelbrot_iterations(fractal->r, fractal->i, fractal->iter);
			fractal->color.combined = ft_psycho_color(fractal->iter, fractal);
			mlx_put_pixel(fractal->image, fractal->x, fractal->y, fractal->color.combined);
			fractal->x++;
		}
		fractal->y++;
	}
}*/

void	ft_render_mandelbrot(t_fractal *fractal)
{
	double	x_step;
	double	y_step;
	double	start_r;
	double	start_i;
	int		max_iter;
	
	fractal->y = 0;
	x_step = (X_MAX - X_MIN) / (fractal->mlx->width * fractal->zoom);
	y_step = (Y_MAX - Y_MIN) / (fractal->mlx->height * fractal->zoom);
	start_r = fractal->center.real - (fractal->mlx->width / 2) * x_step;
	start_i = fractal->center.imaginary - (fractal->mlx->height / 2) * y_step;
	max_iter = MAX_ITER + log(fractal->zoom + 1) * 15;
	while (fractal->y < fractal->mlx->height)
	{
		fractal->x = 0;
		while (fractal->x < fractal->mlx->width)
		{
			if (fractal->y <= fractal->mlx->height / 2)
			{
				if (fractal->x <= fractal->mlx->width / 3)
				{
					fractal->r = start_r + fractal->x * x_step;
					fractal->i = start_i + fractal->y * y_step;
					fractal->iter = ft_mandelbrot_iterations(fractal->r, fractal->i, max_iter);
					fractal->color.combined = ft_psycho_color(fractal->iter, fractal);
					//fractal->color.combined = ft_soft_color(fractal->iter, fractal);
					//fractal->color.combined = ft_tv_color(fractal->iter);
					mlx_put_pixel(fractal->image, fractal->x, fractal->y, fractal->color.combined);
					fractal->x++;
				}
				else if (fractal->x >= fractal->mlx->width / 3 && fractal->x <= fractal->mlx->width * 2 / 3)
				{
					if (fractal->y >= 3*fractal->mlx->height * fractal->x / fractal->mlx->width - fractal->mlx->height)
					{
						if (fractal->y >= -3*fractal->mlx->height * fractal->x / fractal->mlx->width - fractal->mlx->height)
						{
							fractal->r = start_r + fractal->x * x_step;
							fractal->i = start_i + fractal->y * y_step;
							fractal->iter = ft_mandelbrot_iterations(fractal->r, fractal->i, max_iter);
							// fractal->color.combined = ft_psycho_color(fractal->iter, fractal);
							fractal->color.combined = ft_soft_color(fractal->iter, fractal);
							//fractal->color.combined = ft_tv_color(fractal->iter);
							mlx_put_pixel(fractal->image, fractal->x, fractal->y, fractal->color.combined);
							fractal->x++;
						}
						else
						{
							fractal->r = start_r + fractal->x * x_step;
							fractal->i = start_i + fractal->y * y_step;
							fractal->iter = ft_mandelbrot_iterations(fractal->r, fractal->i, max_iter);
							// fractal->color.combined = ft_psycho_color(fractal->iter, fractal);
							fractal->color.combined = ft_soft_color_3(fractal->iter, fractal);
							//fractal->color.combined = ft_tv_color(fractal->iter);
							mlx_put_pixel(fractal->image, fractal->x, fractal->y, fractal->color.combined);
							fractal->x++;
						}
					}
					else
					{
						if (fractal->y >= -3*fractal->mlx->height * fractal->x / fractal->mlx->width - fractal->mlx->height)
						{
							fractal->r = start_r + fractal->x * x_step;
							fractal->i = start_i + fractal->y * y_step;
							fractal->iter = ft_mandelbrot_iterations(fractal->r, fractal->i, max_iter);
							// fractal->color.combined = ft_psycho_color(fractal->iter, fractal);
							fractal->color.combined = ft_soft_color_2(fractal->iter, fractal);
							//fractal->color.combined = ft_tv_color(fractal->iter);
							mlx_put_pixel(fractal->image, fractal->x, fractal->y, fractal->color.combined);
							fractal->x++;
						}
						else
						{
							fractal->r = start_r + fractal->x * x_step;
							fractal->i = start_i + fractal->y * y_step;
							fractal->iter = ft_mandelbrot_iterations(fractal->r, fractal->i, max_iter);
							// fractal->color.combined = ft_psycho_color(fractal->iter, fractal);
							fractal->color.combined = ft_soft_color_4(fractal->iter, fractal);
							//fractal->color.combined = ft_tv_color(fractal->iter);
							mlx_put_pixel(fractal->image, fractal->x, fractal->y, fractal->color.combined);
							fractal->x++;
						}
					}	
				}
				else
				{
					fractal->r = start_r + fractal->x * x_step;
					fractal->i = start_i + fractal->y * y_step;
					fractal->iter = ft_mandelbrot_iterations(fractal->r, fractal->i, max_iter);
					//fractal->color.combined = ft_psycho_color(fractal->iter, fractal);
					//fractal->color.combined = ft_soft_color(fractal->iter, fractal);
					fractal->color.combined = ft_tv_color(fractal->iter);
					mlx_put_pixel(fractal->image, fractal->x, fractal->y, fractal->color.combined);
					fractal->x++;
				}
			}
			else
			{
				if (fractal->x <= fractal->mlx->width / 3)
				{
					fractal->r = start_r + fractal->x * x_step;
					fractal->i = start_i + fractal->y * y_step;
					fractal->iter = ft_mandelbrot_iterations(fractal->r, fractal->i, max_iter);
					//fractal->color.combined = ft_psycho_color(fractal->iter, fractal);
					//fractal->color.combined = ft_soft_color(fractal->iter, fractal);
					fractal->color.combined = ft_tv_color(fractal->iter);
					mlx_put_pixel(fractal->image, fractal->x, fractal->y, fractal->color.combined);
					fractal->x++;
				}
				else if (fractal->x >= fractal->mlx->width / 3 && fractal->x <= fractal->mlx->width * 2 / 3)
				{
					if (fractal->y >= 3*fractal->mlx->height * fractal->x / fractal->mlx->width - fractal->mlx->height)
					{
						if (fractal->y >= -3*fractal->mlx->height * fractal->x / fractal->mlx->width - fractal->mlx->height)
						{
							fractal->r = start_r + fractal->x * x_step;
							fractal->i = start_i + fractal->y * y_step;
							fractal->iter = ft_mandelbrot_iterations(fractal->r, fractal->i, max_iter);
							// fractal->color.combined = ft_psycho_color(fractal->iter, fractal);
							fractal->color.combined = ft_soft_color_2(fractal->iter, fractal);
							//fractal->color.combined = ft_tv_color(fractal->iter);
							mlx_put_pixel(fractal->image, fractal->x, fractal->y, fractal->color.combined);
							fractal->x++;
						}
						else
						{
							fractal->r = start_r + fractal->x * x_step;
							fractal->i = start_i + fractal->y * y_step;
							fractal->iter = ft_mandelbrot_iterations(fractal->r, fractal->i, max_iter);
							// fractal->color.combined = ft_psycho_color(fractal->iter, fractal);
							fractal->color.combined = ft_soft_color_4(fractal->iter, fractal);
							//fractal->color.combined = ft_tv_color(fractal->iter);
							mlx_put_pixel(fractal->image, fractal->x, fractal->y, fractal->color.combined);
							fractal->x++;
						}
					}
					else
					{
						if (fractal->y >= -3*fractal->mlx->height * fractal->x / fractal->mlx->width - fractal->mlx->height)
						{
							fractal->r = start_r + fractal->x * x_step;
							fractal->i = start_i + fractal->y * y_step;
							fractal->iter = ft_mandelbrot_iterations(fractal->r, fractal->i, max_iter);
							// fractal->color.combined = ft_psycho_color(fractal->iter, fractal);
							fractal->color.combined = ft_soft_color(fractal->iter, fractal);
							//fractal->color.combined = ft_tv_color(fractal->iter);
							mlx_put_pixel(fractal->image, fractal->x, fractal->y, fractal->color.combined);
							fractal->x++;
						}
						else
						{
							fractal->r = start_r + fractal->x * x_step;
							fractal->i = start_i + fractal->y * y_step;
							fractal->iter = ft_mandelbrot_iterations(fractal->r, fractal->i, max_iter);
							// fractal->color.combined = ft_psycho_color(fractal->iter, fractal);
							fractal->color.combined = ft_soft_color_3(fractal->iter, fractal);
							//fractal->color.combined = ft_tv_color(fractal->iter);
							mlx_put_pixel(fractal->image, fractal->x, fractal->y, fractal->color.combined);
							fractal->x++;
						}
					}	
				}
				else
				{
					fractal->r = start_r + fractal->x * x_step;
					fractal->i = start_i + fractal->y * y_step;
					fractal->iter = ft_mandelbrot_iterations(fractal->r, fractal->i, max_iter);
					fractal->color.combined = ft_psycho_color(fractal->iter, fractal);
					//fractal->color.combined = ft_soft_color(fractal->iter, fractal);
					//fractal->color.combined = ft_tv_color(fractal->iter);
					mlx_put_pixel(fractal->image, fractal->x, fractal->y, fractal->color.combined);
					fractal->x++;
				}
			}
			
		}
		fractal->y++;
	}
}

/*void	ft_render_mandelbrot(t_fractal *fractal)
{
	double	x_step = (X_MAX - X_MIN) / (fractal->mlx->width * fractal->zoom);
	double	y_step = (Y_MAX - Y_MIN) / (fractal->mlx->height * fractal->zoom);
	double	start_r = fractal->center_r - (fractal->mlx->width / 2) * x_step;
	double	start_i = fractal->center_i - (fractal->mlx->height / 2) * y_step;

	for (int y = 0; y < fractal->mlx->height; y++)
	{
		for (int x = 0; x < fractal->mlx->width; x++)
		{
			double r = start_r + x * x_step;
			double i = start_i + y * y_step;
			int max_iter = MAX_ITER + log(fractal->zoom + 1) * 15; // adaptativo
			int iter = ft_mandelbrot_iterations(r, i, max_iter);
			int color = ft_psycho_color(iter, fractal);
			mlx_put_pixel(fractal->image, x, y, color);
		}
	}
}*/

/* Julia Set: It is defined using the same iterative equation 
𝑧(𝑛 + 1) = z(n)² + 𝑐 where 𝑧 starts at each point in the complex plane and 
𝑐 is a fixed value. A point belongs to the Julia set associated with 𝑐 if 
the sequence generated does not tend to infinity. */

/* Function to compute the color of each pixel
using Mandelbrot function z = z^2 + c */
int	ft_julia_iterations(double real, double imaginary, t_complex c, int iter)
{
	t_complex	z;
	double		z_real_temp;
	double		z_imag_temp;
	double		z_magnitude_squared;

	iter = 0;
	z.real = real;
	z.imaginary = imaginary;
	z_magnitude_squared = 0.0;
	while (iter < MAX_ITER && z_magnitude_squared <= 4)
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

/* Function to generate an image of the Julia set by iterating over each 
pixel on the screen, calculating the color based on the number of Mandelbrot 
iterations, and then drawing that color onto the image. */
void	ft_render_julia(t_fractal *fractal)
{
	fractal->y = 0;
	while (fractal->y < fractal->mlx->height)
	{
		fractal->x = 0;
		while (fractal->x < fractal->mlx->width)
		{
			fractal->r = fractal->center.real
				+ (fractal->x - fractal->mlx->width / 2)
				* (X_MAX - X_MIN) / (fractal->mlx->width * fractal->zoom);
			fractal->i = fractal->center.imaginary
				+ (fractal->y - fractal->mlx->height / 2)
				* (Y_MAX - Y_MIN) / (fractal->mlx->height * fractal->zoom);
			fractal->iter = ft_julia_iterations(fractal->r,
					fractal->i, fractal->complex, fractal->iter);
			fractal->color.combined = ft_soft_color(fractal->iter, fractal);
			mlx_put_pixel(fractal->image, fractal->x, fractal->y, fractal->color.combined);
			fractal->x++;
		}
		fractal->y++;
	}
}
