#include "../libfractol.h"

void	ft_draw_flower(t_fractal *fractal, int x, int y, int w, int h, int size, int *flag, int ft(int , t_fractal *))
{
    /*if (!flag)
    {*/
    if (*flag == 1)
        return ;
    if(sqrt(w * pow(fractal->y - y, 2) + pow(fractal->x - x, 2) < size)
        || sqrt(pow(fractal->y - y, 2) + h * pow(fractal->x - x, 2) < size))
    {
        fractal->color.combined = ft(fractal->iter, fractal);
        mlx_put_pixel(fractal->image, fractal->x, fractal->y, fractal->color.combined);
        *flag = 1;
    }
    //}
}

void    ft_draw_circle(t_fractal *fractal, int x, int y, int w, int h, int size, int *flag, int ft(int , t_fractal *))
{
    if (*flag == 1)
        return ;
    if(sqrt(w * pow(fractal->y - y, 2) + h * pow(fractal->x - x, 2) < size))
    {
        fractal->color.combined = ft(fractal->iter, fractal);
        mlx_put_pixel(fractal->image, fractal->x, fractal->y, fractal->color.combined);
        *flag = 1;
    }
}

void    ft_draw_super_circle(t_fractal *fractal, int x, int y, int w, int h, int size, int *flag, int ft(int , t_fractal *), int ft_2(int , t_fractal *))
{
    if (*flag == 1)
        return ;
    ft_draw_circle(fractal, x, y + (size / 2), w, h, size / 2, flag, ft);
    ft_draw_circle(fractal, x, y - (size / 2), w, h, size / 2, flag, ft);
    ft_draw_circle(fractal, x + (size / 2), y, w, h, size / 2, flag, ft);
    ft_draw_circle(fractal, x - (size / 2), y, w, h, size / 2, flag, ft_2);
    //ft_draw_circle(fractal, x, y, w, h, size, flag, ft_2);

    ft_draw_circle(fractal, x + 500, y, w, h, size, flag, ft);
}