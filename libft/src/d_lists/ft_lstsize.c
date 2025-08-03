/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:08:29 by azubieta          #+#    #+#             */
/*   Updated: 2025/06/17 19:00:37 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_lstsize(t_list *lst)
{
	int			i;
	t_list		*sublist;

	i = 0;
	sublist = lst;
	while (sublist)
	{
		i++;
		sublist = sublist->next;
	}
	return (i);
}
