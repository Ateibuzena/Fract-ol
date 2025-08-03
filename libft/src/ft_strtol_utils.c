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

int	ft_check_overflow(long result, int digit, int base, int sign)
{
	if (sign == 1)
	{
		if (result > (LONG_MAX - digit) / base)
			return (1);
	}
	else
	{
		if (-result < (LONG_MIN + digit) / base)
			return (1);
	}
	return (0);
}

int	ft_get_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 10);
	else if (c >= 'a' && c <= 'z')
		return (c - 'a' + 10);
	else
		return (-1);
}

long	ft_handle_overflow(int *error, int sign)
{
	if (error != 0)
	{
		if (sign == 1)
			*error = 1;
		else
			*error = 2;
	}
	if (sign == 1)
		return (LONG_MAX);
	else
		return (LONG_MIN);
}
