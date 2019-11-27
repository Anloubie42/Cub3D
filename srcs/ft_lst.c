/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:57:10 by anloubie          #+#    #+#             */
/*   Updated: 2019/11/27 14:58:06 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubddd.h"

t_map	*ft_lstnewmap(char *str)
{
	t_map	*map;

	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	map->line = str;
	map->next = NULL;
	return (map);
}

void	ft_lstaddmap(t_map **alst, t_map *new)
{
	t_map	*temp;

	if (!alst)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	temp = *alst;
	while (temp && temp->next)
		temp = temp->next;
	temp->next = new;
}

int		ft_mapsize(t_map *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
