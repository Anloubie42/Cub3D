/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:44:17 by anloubie          #+#    #+#             */
/*   Updated: 2019/11/26 14:38:39 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

char		*ft_str_epur(char *str, t_Cub3D *s)
{
	int		i;
	int		len;
	char	*dest;
	int		j;

	i = -1;
	len = ft_strlen(str);
	while (str[++i])
	{
		if (str[i] == ' ')
			len--;
	}
	if (!(dest = (char*)malloc(sizeof(char) * len + 1)))
		ft_exit(s);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			dest[j++] = str[i];
		i++;
	}
	dest[j] = '\0';
	// ft_clear(&str);
	return (dest);
}

int			ft_map_valid(char c, t_Cub3D *s)
{
	if ((c <= '2' && c >= '0') || c == ' ')
		return (1);
	else if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		if (s->dir)
			ft_exit(s);
		s->dir = c;
		return (1);
	}
	return (0);
}

void		ft_map_create(t_Cub3D *s, char *str, t_map **map)
{
	t_map	*new;
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_map_valid(str[i], s))
			ft_exit(s);
		i++;
	}
	if (!s->map_w)
		s->map_w = ft_strlen(str);
	if (!(new = ft_lstnewmap(str)))
		ft_exit(s);
	ft_lstaddmap(map, new);
}

void		ft_map_parse(t_Cub3D *s, t_map *map)
{
	int		i;

	i = 0;
	s->map_h = ft_mapsize(map);
	if (!(s->map = (char**)malloc(sizeof(char*) * s->map_h)))
		ft_exit(s);
	while (map)
	{
		map->line = ft_str_epur(map->line, s);
		if (!(s->map[i] = (char*)malloc(sizeof(char) * ft_strlen(map->line))))
			ft_exit(s);
		s->map[i++] = map->line;
		map = map->next;
	}
	if (!(s->map[i] = (char*)malloc(sizeof(char))))
		ft_exit(s);
	s->map[i] = NULL;
}
