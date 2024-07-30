/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:04:43 by azubieta          #+#    #+#             */
/*   Updated: 2024/07/17 18:12:11 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libfractol.h"

void	ft_copyright(void)
{
	ft_printf("\nDisclaimer:\n");
	ft_printf("program is for educational purposes only.\n");
	ft_printf("All ASCII art used in this program is generated and modified ");
	ft_printf("from public domain sources or created by the author.\nIf you ");
	ft_printf("believe any content in this program infringes upon your ");
	ft_printf("copyright, please contact the author to resolve the issue.");
	ft_printf("\nNo commercial use of this program is permitted without ");
	ft_printf("explicit permission from the author.\nThe author makes no");
	ft_printf(" warranties, express or implied, regarding the accuracy");
	ft_printf(" or completeness of the content in this program.\n");
}

void	ft_logo(void)
{
	ft_printf("     /\\   |______ | | | | |  _ \\  | | |  __||__   __|  /\\\n");
	ft_printf("    /        / /  | | | | | |_| | | | | |_     | |    /  \\ \n");
	ft_printf("   / /\\     / /   | | | | |  _ <  | | | __|    | |   / /   \n");
	ft_printf("  / ____   / /___ | |_| | | |_| | | | | |__    | |  / /___ \n");
	ft_printf(" /_/    \\_|______||_____| |_____/ |_| |____|   |_| /_/     \n");
}

void	ft_instructions(void)
{
	ft_printf("\nProgram Instructions:\n");
	ft_printf("To run this fractal generation program, you need to execute");
	ft_printf("it with specific parameters based on the type of fractal");
	ft_printf(" you want to generate.\nThe parameters include the fractal");
	ft_printf("type (Mandelbrot, Julia, or Trip) and the RGB color ranges.\n");
	ft_printf("For the Julia set, you also need to provide the real and ");
	ft_printf("imaginary parts of the complex number c in the function");
	ft_printf(" z = z² + c.\n");
}

void	ft_introduction(void)
{
	ft_logo();
	ft_copyright();
	ft_printf("Here are the details:\n\n");
	ft_printf("Mandelbrot Set\n");
	ft_printf("To generate a Mandelbrot fractal, use the following command:\n");
	ft_printf("./fractol Mandelbrot <Red_Range> ");
	ft_printf("<Green_Range> <Blue_Range>\n\n");
	ft_printf("Julia Set\n");
	ft_printf("To generate a Julia fractal, ");
	ft_printf("the following command:\n");
	ft_printf("./fractol Julia <Red_Range> <Green_Range> ");
	ft_printf("<Blue_Range> <Real_C> ");
	ft_printf("<Imaginary_C>\n\nTrip Fractal\n");
	ft_printf("Notes:\n");
	ft_printf("- Ensure you provide all the ");
	ft_printf("parameters for the fractal");
	ft_printf(" type you choose.\n- The ranges for the RGB colors must be ");
	ft_printf("between 0 and 255.\n");
	ft_printf("- For the Julia fractal, the real and imaginary ");
	ft_printf("parts of the complex number c should be within the range of ");
	ft_printf("-2.0 to 2.0 for the most visually interesting results.\n");
}

double	ft_atof(char *str)
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
}
