/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freedouble_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:02:17 by azubieta          #+#    #+#             */
/*   Updated: 2025/06/17 19:02:22 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_freedouble_array(int **array, int len)
{
	int		j;

	if (!array)
		return ;
	j = 0;
	while (j < len)
	{
		if (array[j])
		{
			free(array[j]);
			array[j] = 0;
		}
		j++;
	}
	free(array);
	array = 0;
}
