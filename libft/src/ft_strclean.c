/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:01:45 by azubieta          #+#    #+#             */
/*   Updated: 2025/06/17 19:02:05 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strclean(const char *str, char to_clean)
{
	int		i;
	int		j;
	char	*clean;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	clean = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!clean)
		return (NULL);
	while (str[i])
	{
		if (str[i] != to_clean)
			clean[j++] = str[i];
		i++;
	}
	clean[j] = '\0';
	return (clean);
}
