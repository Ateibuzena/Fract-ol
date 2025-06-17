#include "../include/fractol.h"

// 1. Obtener y validar la posición del ratón
static int	ft_get_mouse(t_fractol *fractol, t_zoom *zoom)
{
	mlx_get_mouse_pos(fractol->window.mlx, &zoom->mouse_x, &zoom->mouse_y);
	if (zoom->mouse_x < 0 || zoom->mouse_x >= WIDTH || zoom->mouse_y < 0 || zoom->mouse_y >= HEIGHT)
		return (0);  // fuera de ventana
	return (1);
}

// 2. Calcular posiciones normalizadas del ratón
static void	ft_normalized_position(t_zoom *zoom)
{
	zoom->norm_x = (zoom->mouse_x - WIDTH / 2.0) / WIDTH;
	zoom->norm_y = (zoom->mouse_y - HEIGHT / 2.0) / HEIGHT;
}

// 3. Actualizar el zoom según la dirección del scroll
static void	ft_update_zoom(t_fractol *fractol, double scroll_y, t_zoom *zoom)
{
	zoom->pre_zoom = fractol->view.zoom;

	if (scroll_y > 0)
		fractol->view.zoom *= 1.02;
	else if (scroll_y < 0)
		fractol->view.zoom /= 1.02;

	zoom->post_zoom = fractol->view.zoom;
}

// 4. Calcular y aplicar el desplazamiento para que el zoom se centre en el cursor
static void	ft_zoom_offset(t_fractol *fractol, t_zoom *zoom)
{
	zoom->offset_x_before = zoom->norm_x * zoom->pre_zoom;
	zoom->offset_y_before = zoom->norm_y * zoom->pre_zoom;
	zoom->offset_x_after = zoom->norm_x * zoom->post_zoom;
	zoom->offset_y_after = zoom->norm_y * zoom->post_zoom;

	fractol->view.move_x += zoom->offset_x_before - zoom->offset_x_after;
	fractol->view.move_y += zoom->offset_y_before - zoom->offset_y_after;
}

// Función principal que combina todo
static void	ft_scroll_hook(double x, double y, void *param)
{
	t_fractol	*fractol = (t_fractol *)param;
	t_zoom		zoom;

	(void)x;
	if (!ft_get_mouse(fractol, &zoom))
		return ;
	ft_normalized_position(&zoom);
	ft_update_zoom(fractol, y, &zoom);
	ft_zoom_offset(fractol, &zoom);
}

static void	ft_arrows_hook(t_fractol *fractol)
{
	double	move_y;
	double	move_x;

	move_y = -2 * fractol->view.zoom * 0.02;
	move_x =  2 * fractol->view.zoom * 0.02;
	if (mlx_is_key_down(fractol->window.mlx, MLX_KEY_W))
		fractol->view.move_y += move_y;
	if (mlx_is_key_down(fractol->window.mlx, MLX_KEY_S))
		fractol->view.move_y -= move_y;
	if (mlx_is_key_down(fractol->window.mlx, MLX_KEY_D))
		fractol->view.move_x += move_x;
	if (mlx_is_key_down(fractol->window.mlx, MLX_KEY_A))
		fractol->view.move_x -= move_x;
}

void	ft_hook(void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (mlx_is_key_down(fractol->window.mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fractol->window.mlx);
	ft_arrows_hook(fractol);
	mlx_scroll_hook(fractol->window.mlx, &ft_scroll_hook, fractol);
	ft_render_fractal(fractol);
}
