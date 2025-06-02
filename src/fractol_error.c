#include "../include/fractol.h"

void	ft_error(t_fractol *fractol)
{
	ft_printf("%s\n", mlx_strerror(mlx_errno));

	if (fractol->window.image)
		mlx_delete_image(fractol->window.mlx, fractol->window.image);

	/*if (fractol->window.background)
		mlx_delete_image(fractol->window.mlx, fractol->window.background);*/

	if (fractol->window.mlx)
		mlx_terminate(fractol->window.mlx);

	exit(EXIT_FAILURE);
}
