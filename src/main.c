#include "../include/fractol.h"

void	ft_init(t_fractol *fractol)
{
	// Nombre del fractal (lo puedes dejar vacío si lo asignas luego según el índice)
	fractol->info.name = "";

	// Opciones de color
	fractol->window.show_help = false;

	// Configuración de vista inicial
	fractol->view.zoom = 4.0;
	fractol->view.max_iter = 120;
	fractol->view.move_x = 0.0;
	fractol->view.move_y = 0.0;
	/*if (fractol->info.index == 2)
	{
		fractol->view.max_iter = 2000;
		fractol->view.zoom = 3.0;        // Zoom más alto para que se vea bien centrado
	}*/

	// Ajustes específicos según el tipo de fractal
	if (fractol->info.index == 1) // mandelbrot
		fractol->view.move_x = -0.5;

	// Si en algún momento vuelves a usar Julia:
	/*
	if (fractol->info.index == 2)
	{
		fractol->j_nm = 0.0;
		if (!(fractol->j_args.real || fractol->j_args.imaginary))
			fractol->j_args = (t_complex){-0.8, 0.156};
	}
	*/
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (argc < 2)
		ft_instructions();
	ft_check_args(argc, argv, &fractol);
	ft_init(&fractol);
	ft_update_image(&fractol);
	mlx_loop_hook(fractol.window.mlx, ft_hook, &fractol);
	mlx_loop(fractol.window.mlx);
	mlx_delete_image(fractol.window.mlx, fractol.window.image);
	//mlx_delete_image(fractol.window.mlx, fractol.window.background);
	mlx_terminate(fractol.window.mlx);
	return (0);
}
