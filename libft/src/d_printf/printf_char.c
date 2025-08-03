/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:52:30 by azubieta          #+#    #+#             */
/*   Updated: 2025/06/17 18:52:31 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_putchar_printf(char c)
{
	return (write(1, &c, 1));
}

int	ft_handle_char(va_list args)
{
	char	c;

	c = va_arg(args, int);
	return (ft_putchar_printf(c));
}
