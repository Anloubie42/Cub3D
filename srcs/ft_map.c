/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:44:17 by anloubie          #+#    #+#             */
/*   Updated: 2019/12/18 13:48:51 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubddd.h"

void		ft_map_valid2(char *str, t_cub3d *s)
{
	if (!s->map_w)
		s->map_w = ft_strlen(str);
	if ((int)ft_strlen(str) != s->map_w)
		ft_exit(s, "Invalid map : map must be a rectangle");
	if (str[0] != '1' || str[(int)ft_strlen(str) - 1] != '1')
		ft_exit(s, "Invalid Map");
}

char		*ft_str_epur(char *str, t_cub3d *s)
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
		ft_exit(s, "Malloc failed");
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			dest[j++] = str[i++];
	}
	dest[j] = '\0';
	ft_map_valid2(dest, s);
	return (dest);
}

void		ft_map_valid(char *str, t_cub3d *s)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if ((str[i] <= '2' && str[i] >= '0') || str[i] == ' ')
		{
			if (str[i] == '2')
				s->obj++;
		}
		else if (str[i] == 'N' || str[i] == 'S'
		|| str[i] == 'W' || str[i] == 'E')
		{
			if (s->dir)
				ft_exit(s, "Multiple spawn points");
			s->dir = str[i];
		}
		else
			ft_exit(s, "Invalid Map");
		i++;
	}
}

void		ft_map_create(t_cub3d *s, char *str, t_map **map)
{
	t_map	*new;

	ft_map_valid(str, s);
	if (!(s->sprite = (t_info*)malloc(sizeof(t_info) * s->obj)))
		ft_exit(s, "Malloc failed");
	if (!(s->sp = (t_sprite*)malloc(sizeof(t_sprite) * s->obj)))
		ft_exit(s, "Malloc failed");
	if (!(s->sprite->zbuffer = (double*)malloc(sizeof(double) * s->res_x)))
		ft_exit(s, "Malloc failed");
	if (!(new = ft_lstnewmap(str)))
		ft_exit(s, "Malloc failed");
	ft_lstaddmap(map, new);
}

void		ft_map_parse(t_cub3d *s, t_map *map)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	s->map_h = ft_mapsize(map);
	if (!(s->map = (char**)malloc(sizeof(char*) * s->map_h)))
		ft_exit(s, "Malloc failed");
	while (map)
	{
		map->line = ft_str_epur(map->line, s);
		sprite_count(s, map->line, count);
		if (!(s->map[i] = (char*)malloc(sizeof(char) * ft_strlen(map->line))))
			ft_exit(s, "Malloc failed");
		s->map[i++] = map->line;
		map = map->next;
		count++;
	}
	if (!(s->map[i] = (char*)malloc(sizeof(char))))
		ft_exit(s, "Malloc failed");
	s->map[i] = NULL;
}
