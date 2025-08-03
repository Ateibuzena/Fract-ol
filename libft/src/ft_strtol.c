/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                          :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:29:18 by azubieta          #+#    #+#             */
/*   Updated: 2024/12/28 15:23:15 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*ft_skip_spaces(const char *str)
{
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
		|| *str == '\f' || *str == '\v')
		str++;
	return (str);
}

static int	ft_handle_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-')
	{
		sign = -1;
		(*str)++;
	}
	else if (**str == '+')
		(*str)++;
	return (sign);
}

static int	ft_base(const char **str, int base)
{
	if (base == 0)
	{
		if (**str == '0')
		{
			if (*(*str + 1) == 'x' || *(*str + 1) == 'X')
			{
				(*str) += 2;
				return (16);
			}
			else
			{
				(*str)++;
				return (8);
			}
		}
		return (10);
	}
	return (base);
}

static long	ft_conversion(const char **str, int base, int *error, int sign)
{
	long	result;
	int		digit;
	int		has_digits;

	result = 0;
	has_digits = 0;
	while (**str)
	{
		digit = ft_get_digit(**str);
		if (digit == -1 || digit >= base)
			break ;
		has_digits = 1;
		if (ft_check_overflow(result, digit, base, sign))
			return (ft_handle_overflow(error, sign));
		result = result * base + digit;
		(*str)++;
	}
	if (!has_digits && error != 0)
		*error = 3;
	return (result);
}

long	ft_strtol(const char *str, char **endptr, int base, int *error)
{
	int		sign;
	long	result;

	if (error)
		*error = 0;
	if (!str)
	{
		if (error)
			*error = 4;
		if (endptr)
			*endptr = NULL;
		return (0);
	}
	str = ft_skip_spaces(str);
	sign = ft_handle_sign(&str);
	base = ft_base(&str, base);
	result = ft_conversion(&str, base, error, sign);
	if (*str != '\0' && error && *error == 0)
		*error = 5;
	if (endptr)
		*endptr = (char *)str;
	return (result * sign);
}

/*#include <stdio.h>

void	test(const char *input)
{
	int		error;
	char	*endptr;
	long	result;

	result = ft_strtol(input, &endptr, 10, &error);
	printf("Input: \"%s\"\n", input);
	printf("Resultado: %ld\n", result);
	printf("Error code: %d\n", error);
	// Comprobar si está fuera del rango de int
	if (error == 1 || error == 2 || error == 3 || error == 4 || error == 5
		|| result > INT_MAX || result < INT_MIN)
		printf("KO ❌ (out of range of int)\n");
	else
		printf("OK ✅ (out of range of int)\n");
	printf("------------\n");
}

int	main(void)
{
	test("42");                      // OK
	test("-42");                     // OK
	test("2147483647");              // OK (INT_MAX)
	test("-2147483648");             // OK (INT_MIN)
	test("2147483648");              // KO (INT_MAX + 1)
	test("-2147483649");             // KO (INT_MIN - 1)
	test("9223372036854775807");     // KO (LONG_MAX)
	test("-9223372036854775808");    // KO (LONG_MIN)
	test("   +123abc");              // OK (número válido antes de basura)
	test("abc123");                  // KO (no empieza por número)
	test("");                        // KO (cadena vacía)
	test("00000123");                // OK (con ceros delante)
	test("4294967294");					// tiene que ser un error;
	test("-01");
	test("00");
	test("18446744073709551614");	//tiene que ser un error;
	return (0);
}*/
