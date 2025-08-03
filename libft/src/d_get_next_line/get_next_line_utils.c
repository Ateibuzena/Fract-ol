/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:40:33 by azubieta          #+#    #+#             */
/*   Updated: 2025/07/08 13:16:55 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strjoin_getnextline(char *s1, char *s2)
{
	char	*join;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	join = malloc((ft_strlen(s1)
				+ ft_strlen(s2) + 1) * sizeof(char));
	if (!join)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		join[i + j] = s2[j];
		j++;
	}
	join[i + j] = '\0';
	return (join);
}

char	*ft_free(char *ptr)
{
	free(ptr);
	ptr = NULL;
	return (ptr);
}

t_fdnode	*ft_newnode(int fd)
{
	t_fdnode	*node;

	node = malloc(sizeof(t_fdnode));
	if (!node)
		return (NULL);
	node->fd = fd;
	node->buffer = malloc(1);
	if (!node->buffer)
	{
		free(node);
		node = NULL;
		return (NULL);
	}
	node->buffer[0] = '\0';
	node->next = NULL;
	return (node);
}

void	ft_free_all_nodes(t_fdnode **list)
{
	t_fdnode	*actual;
	t_fdnode	*tmp;

	if (!list || !*list)
		return ;
	actual = *list;
	while (actual)
	{
		tmp = actual->next;
		free(actual->buffer);
		free(actual);
		actual = tmp;
	}
	*list = NULL;
}

char	*ft_freenode(t_fdnode **list, int fd)
{
	t_fdnode	*actual;
	t_fdnode	*previous;

	if (!list || !*list)
		return (NULL);
	if (fd == -1)
		return (ft_free_all_nodes(list), NULL);
	actual = *list;
	previous = NULL;
	while (actual && actual->fd != fd)
	{
		previous = actual;
		actual = actual->next;
	}
	if (!actual)
		return (NULL);
	if (previous)
		previous->next = actual->next;
	else
		*list = actual->next;
	free(actual->buffer);
	free(actual);
	return (NULL);
}
