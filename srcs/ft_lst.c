/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:57:10 by anloubie          #+#    #+#             */
/*   Updated: 2020/01/06 15:30:47 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubddd.h"

void	delmap(t_map *map)
{
	if (map)
	{
		free(map);
		map = NULL;
	}
}

t_map	*ft_lstnewmap(char *str)
{
	t_map	*map;

	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	if (!(map->line = ft_strdup(str)))
		return (NULL);
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

int		mapclear(t_cub3d *s, t_map **map, int i)
{
	t_map	*tmp;
	int		count;

	count = 0;
	while (*map && map)
	{
		if (!(s->map[i] = ft_str_epur((*map)->line, s)))
			ft_exit(s, "Malloc failed");
		sprite_count(s, s->map[i], count);
		i++;
		count++;
		tmp = *map;
		*map = (*map)->next;
		delmap(tmp);
	}
	return (i);
}
