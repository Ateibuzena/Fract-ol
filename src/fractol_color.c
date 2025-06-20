#include "../include/fractol.h"

static int ft_mandelbrot_color(int iter, int base_red, int base_green, int base_blue)
{
    double frequency = 0.3;
    int red = (int)(sin(frequency * iter + 0) * 127 + base_red);
    int green = (int)(sin(frequency * iter + 4 * M_PI / 3) * 127 + base_green);
    int blue = (int)(sin(frequency * iter + 2 * M_PI / 3) * 127 + base_blue);

    // Clampeo por si sale fuera de 0-255 (por seguridad)
    if (red < 0) red = 0;
    if (red > 255) red = 255;
    if (green < 0) green = 0;
    if (green > 255) green = 255;
    if (blue < 0) blue = 0;
    if (blue > 255) blue = 255;

    return (red << 24) | (green << 16) | (blue << 8) | 225;
}

/*static int ft_color(int iter, int max_iter)
{
    if (iter >= max_iter)
        return 0x000000FF; // Negro para puntos dentro del conjunto

    double t = (double)iter / (double)max_iter;

    int red   = (int)(9 * (1 - t) * t * t * t * 255);
    int green = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
    int blue  = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);

    return (red << 24) | (green << 16) | (blue << 8) | 255;
}*/

void	ft_put_pixel(t_fractol *fractol)
{
	int	color;

	if (fractol->pixel.i >= fractol->view.max_iter)
		color = 0x000000FF;
	else
	{
        //color = fractol->pixel.i * 0x050505;
		color = ft_mandelbrot_color(fractol->pixel.i, 128, 128, 128);
        //color = ft_color(fractol->pixel.i, fractol->view.max_iter);
	}
	mlx_put_pixel(fractol->window.image, fractol->pixel.x, fractol->pixel.y, color);
}

