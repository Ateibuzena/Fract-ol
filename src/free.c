#include "../libfractol.h"

void	ft_free_fractal(t_fractal *fractal)
{
	if (!fractal)
		return ;
	if (fractal->image)
	{
		mlx_delete_image(fractal->mlx, fractal->image);
		fractal->image = NULL;
	}
	if (fractal->mlx)
	{
		if (fractal->mlx->window)
			mlx_close_window(fractal->mlx);
		mlx_terminate(fractal->mlx);
		fractal->mlx = NULL;
	}
}
