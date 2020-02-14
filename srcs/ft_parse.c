/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 12:16:12 by anloubie          #+#    #+#             */
/*   Updated: 2020/02/06 13:55:36 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubddd.h"

void			ft_init(t_cub3d *s)
{
	int		i;

	i = 0;
	if (!(s->data = (t_data*)malloc(sizeof(t_data))))
		ft_exit(s, "Malloc failed");
	if (!(s->calc = (t_calc*)malloc(sizeof(t_calc))))
		ft_exit(s, "Malloc failed");
	if (!(s->key = (t_key*)malloc(sizeof(t_key))))
		ft_exit(s, "Malloc failed");
	if (!(s->col_f = (int*)malloc(sizeof(int) * 3)))
		ft_exit(s, "Malloc failed");
	if (!(s->col_c = (int*)malloc(sizeof(int) * 3)))
		ft_exit(s, "Malloc failed");
	while (i < 3)
		s->col_f[i++] = 0;
	i = 0;
	while (i < 3)
		s->col_c[i++] = 0;
	ft_bzero(s->key, sizeof(t_key));
	s->color_c = -1;
	s->color_f = -1;
	s->obj = 0;
	s->screen = 0;
}

void			ft_color(char *str, t_cub3d *s, int b)
{
	char	**dest;
	char	**col;
	int		i;

	i = -1;
	dest = ft_split(str, ' ');
	if (ft_buflen(dest) != 2)
		ft_exit(s, "Invalid color specified");
	if ((b == 1 && s->col_c[0] != 0) || (b == 0 && s->col_f[0] != 0))
		ft_exit(s, "Parameter set twice");
	if (ft_buflen(dest) == 2)
	{
		col = ft_split(dest[1], ',');
		while (b == 1 && ++i < 3)
			s->col_c[i] = ft_atoi(col[i]);
		while (b == 0 && ++i < 3)
			s->col_f[i] = ft_atoi(col[i]);
		ft_del(col);
	}
	ft_del(dest);
	ft_clear(&str);
	if (b == 0)
		s->color_f = ft_get_color(s->col_f[0], s->col_f[1], s->col_f[2]);
	else
		s->color_c = ft_get_color(s->col_c[0], s->col_c[1], s->col_c[2]);
}

char			*ft_path(char *path, char *str, t_cub3d *s)
{
	char	**dest;
	int		len;
	char	*tmp;

	if (!(dest = ft_split(str, ' ')))
		ft_exit(s, "Malloc failed");
	len = ft_buflen(dest);
	if (path)
		ft_exit(s, "Parameter set twice");
	if (len == 2)
	{
		tmp = str;
		if (!(path = ft_strdup(dest[1])))
			ft_exit(s, "Malloc failed");
		ft_clear(&str);
	}
	ft_del(dest);
	if (len != 2)
		ft_exit(s, "Invalid texture path");
	return (path);
}

void			ft_parse_2(t_cub3d *s, char *str, t_map **map)
{
	if (str && str[0] == 'R')
		ft_resset(s, str);
	else if (str && str[0] == 'S' && str[1] == ' ')
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
		ft_color(str, s, 1);
	else if (str && str[0] == 'C')
		ft_color(str, s, 0);
	else if (str && str[0] == '1')
		ft_map_create(s, str, map);
	else if (str && str[0])
		ft_exit(s, "Unknown parameter");
	else
		free(str);
}

void			ft_parse(t_cub3d *s, char *path)
{
	int		fd;
	char	*line;
	t_map	*map;

	line = NULL;
	map = NULL;
	if (s->screen == 2)
		ft_exit(s, "Unkown argument : try --save");
	if (ft_strncmp(path + ft_strlen(path) - 4, ".cub", 4))
		ft_exit(s, "Invalid extension");
	if ((fd = open(path, O_RDONLY)) < 0)
		ft_exit(s, "Unable to open setting file");
	while (get_next_line(fd, &line) > 0)
		ft_parse_2(s, line, &map);
	ft_parse_2(s, line, &map);
	if (s->color_c == -1 || s->color_f == -1)
		ft_exit(s, "Color missing");
	if (!s->res_x && !s->res_y)
		ft_exit(s, "Missing key");
	free_col(s);
	ft_map_parse(s, map);
	map_valid3(s);
	close(fd);
	if (!s->dir)
		ft_exit(s, "No spawn point set");
}
