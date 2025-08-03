/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:52:38 by azubieta          #+#    #+#             */
/*   Updated: 2025/06/17 18:52:57 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_handle_pointer(va_list args)
{
	unsigned long	ptr;
	int				count;

	count = 0;
	ptr = (unsigned long)va_arg(args, void *);
	count += write(1, "0x", 2);
	count += ft_puthex_printf(ptr, 0);
	return (count);
}
