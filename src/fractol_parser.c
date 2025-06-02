#include "../include/fractol.h"

/*static double	ft_atof(char *str)
{
	double	res;
	double	res2;
	char	*c;
	int		len;

	c = (char *)str;
	res = (double)ft_atoi(c);
	while (*c && *c != '.')
		c++;
	if (*c == '.')
		c++;
	res2 = (double)ft_atoi(c);
	len = ft_strlen(c);
	while (len--)
		res2 /= 10;
	if (res >= 0)
		return (res + res2);
	else
		return (res + -res2);
}*/

void	ft_instructions(void)
{
	
	exit(0);
}

void	ft_check_args(int argc, char **argv, t_fractol *fractol)
{
	if (!ft_strncmp(argv[1], "1", 1) || !ft_strncmp(argv[1], "mandelbrot", 10))
		fractol->info.index = 1;
	else if (!ft_strncmp(argv[1], "2", 1) || !ft_strncmp(argv[1], "julia", 5))
		fractol->info.index = 2;
	else
		fractol->info.index = 0;
	/*if (fractol->index == 2)
	{
		if (argc == 4)
			fractol->j_args = (t_complex){ft_atof(argv[2]), ft_atof(argv[3])};
		else if (argc != 2)
			ft_instructions();
	}*/
	if (argc != 2)
		ft_instructions(); //quitar
}
