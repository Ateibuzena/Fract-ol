#include "../include/fractol.h"

/*void	ft_background(t_fractol *fractol)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (x == 0 || y == 0 || x == WIDTH - 1 || y == HEIGHT - 1)
				mlx_put_pixel(fractol->window.background, x, y, 0xFFFFFFFF);
			else
				mlx_put_pixel(fractol->window.background, x, y, 0x000000FF);
		}
	}
}*/

void	ft_update_image(t_fractol *fractol)
{
	fractol->window.mlx = mlx_init(WIDTH, HEIGHT, fractol->info.name, false);
	if (!fractol->window.mlx)
		ft_error(fractol);
	fractol->window.image = mlx_new_image(fractol->window.mlx, WIDTH, HEIGHT);
	if (!fractol->window.image || mlx_image_to_window(fractol->window.mlx, fractol->window.image, 0, 0))
		ft_error(fractol);

	/*fractol->window.background = mlx_new_image(fractol->window.mlx, WIDTH, HEIGHT);
	if (!fractol->window.background || mlx_image_to_window(fractol->window.mlx, fractol->window.background, WIDTH, 0))
		ft_error(fractol);*/
}

static void ft_julia_spiral(t_fractol *f)
{
	double x, y;
	double zx, zy, zx2, zy2;
	double cx = /*-0.4;*/0.285;//-0.8;//-0.70176;//0.355; // Prueba también con 0.355 + 0.355i
	double cy = /*0.6;*/0.01;//0.156;//-0.3842;//0.355;
	double theta = 0.1; // ángulo de rotación (ajustable)
	// Parte de la rotación compleja
	double	rot_cos = cos(theta);
	double	rot_sin = sin(theta);

	x = (f->pixel.x - WIDTH / 2.0) * f->view.zoom / WIDTH + f->view.move_x;
	y = (f->pixel.y - HEIGHT / 2.0) * f->view.zoom / WIDTH + f->view.move_y;



	zx = x;
	zy = y;

	int i = 0;
	while (i < f->view.max_iter)
	{
		zx2 = zx * zx - zy * zy + cx;
		zy2 = 2.0 * zx * zy + cy;

		// rotación compleja: (zx2 + i*zy2) * e^{iθ}
		double tmp_zx = zx2 * rot_cos - zy2 * rot_sin;
		double tmp_zy = zx2 * rot_sin + zy2 * rot_cos;

		zx = tmp_zx;
		zy = tmp_zy;

		if ((zx * zx + zy * zy) > 4.0)
			break;
		i++;
	}
	f->pixel.i = i;
	ft_put_pixel(f);
}

void	ft_mandelbrot(t_fractol *fractol)
{
	double	tmp;

	fractol->pixel.c.real = (fractol->pixel.x - WIDTH / 2.0) * fractol->view.zoom / WIDTH + fractol->view.move_x;
	fractol->pixel.c.imaginary = (fractol->pixel.y - HEIGHT / 2.0) * fractol->view.zoom / WIDTH + fractol->view.move_y;
	fractol->pixel.z = (t_complex){0, 0};
	fractol->pixel.i = -1;
	while (++fractol->pixel.i < fractol->view.max_iter)
	{
		if ((fractol->pixel.z.real * fractol->pixel.z.real + fractol->pixel.z.imaginary * fractol->pixel.z.imaginary) >= 4.0)
			break ;
		tmp = 2.0 * fractol->pixel.z.real * fractol->pixel.z.imaginary + fractol->pixel.c.imaginary;
		fractol->pixel.z.real = fractol->pixel.z.real * fractol->pixel.z.real - fractol->pixel.z.imaginary * fractol->pixel.z.imaginary + fractol->pixel.c.real;
		fractol->pixel.z.imaginary = tmp;
	}
	ft_put_pixel(fractol);
}

void	ft_render_fractal(t_fractol *fractol)
{
	fractol->pixel.y = 0;
	while (fractol->pixel.y < HEIGHT)
	{
		fractol->pixel.x = 0;
		while (fractol->pixel.x < WIDTH)
		{
			if (fractol->info.index == 1)
				ft_mandelbrot(fractol);
			if (fractol->info.index == 2)
			{
				ft_julia_spiral(fractol);
			}
			// 	ft_julia(fractol);

			fractol->pixel.x++;
		}
		fractol->pixel.y++;
	}
}