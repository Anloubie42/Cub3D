/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 12:16:12 by anloubie          #+#    #+#             */
/*   Updated: 2019/11/27 17:52:27 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubddd.h"

void			ft_init(t_cub3d *s)
{
	int		i;

	i = 0;
	s->data = (t_data*)malloc(sizeof(t_data));
	s->calc = (t_calc*)malloc(sizeof(t_calc));
	s->key = (t_key*)malloc(sizeof(t_key));
	if (!(s->col_f = (int*)malloc(sizeof(int) * 3)))
		return ;
	if (!(s->col_c = (int*)malloc(sizeof(int) * 3)))
		return ;
	while (i < 3)
		s->col_f[i++] = 0;
	i = 0;
	while (i < 3)
		s->col_c[i++] = 0;
	s->key->up = 0;
	s->key->down = 0;
	s->key->left = 0;
	s->key->right = 0;
}

void			ft_color(char *str, t_cub3d *s, int b)
{
	char	**dest;
	int		len;
	char	**col;
	int		i;

	i = 0;
	dest = ft_split(str, ' ');
	len = ft_buflen(dest);
	if (len == 2)
	{
		col = ft_split(dest[1], ',');
		while (b == 1 && i < 3)
		{
			s->col_c[i] = ft_atoi(col[i]);
			i++;
		}
		while (b == 0 && i < 3)
		{
			s->col_f[i] = ft_atoi(col[i]);
			i++;
		}
	}
	if (len != 2)
		ft_exit(s);
}

char			*ft_path(char *path, char *str, t_cub3d *s)
{
	char	**dest;
	int		len;

	dest = ft_split(str, ' ');
	len = ft_buflen(dest);
	if (len == 2)
		path = ft_strdup(dest[1]);
	ft_del(dest);
	if (len != 2)
		ft_exit(s);
	return (path);
}

void			ft_parse_2(t_cub3d *s, char *str, t_map **map)
{
	if (str && str[0] == 'R')
		ft_resset(s, str);
	else if (str && str[0] == 'S' && str[1] != 'O')
		s->path_sprite = ft_path(s->path_sprite, str, s);
	else if (str && str[0] == 'N' && str[1] == 'O')
		s->path_n = ft_path(s->path_n, str, s);
	else if (str && str[0] == 'S' && str[1] == 'O')
		s->path_s = ft_path(s->path_s, str, s);
	else if (str && str[0] == 'W' && str[1] == 'E')
		s->path_w = ft_path(s->path_w, str, s);
	else if (str && str[0] == 'E' && str[1] == 'A')
		s->path_e = ft_path(s->path_e, str, s);
	else if (str && str[0] == 'F')
		ft_color(str, s, 0);
	else if (str && str[0] == 'C')
		ft_color(str, s, 1);
	else if (str && str[0] == '1')
		ft_map_create(s, str, map);
}

void			ft_parse(t_cub3d *s, char *path)
{
	int		fd;
	char	*line;
	t_map	*map;

	line = NULL;
	map = NULL;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		ft_parse_2(s, line, &map);
	ft_parse_2(s, line, &map);
	ft_map_parse(s, map);
	close(fd);
}
