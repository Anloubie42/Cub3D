/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:21:58 by anloubie          #+#    #+#             */
/*   Updated: 2019/11/28 16:23:06 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubddd.h"

void	ft_del(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int		ft_buflen(char **buf)
{
	int	i;

	if (!buf)
		return (0);
	i = 0;
	while (buf[i] != NULL)
		i++;
	return (i);
}

void	ft_resset(t_cub3d *s, char *str)
{
	char	**dest;
	int		len;
	int		i;

	i = 0;
	dest = ft_split(str, ' ');
	len = ft_buflen(dest);
	if (len == 3)
	{
		s->res_x = ft_atoi(dest[1]);
		s->res_y = ft_atoi(dest[2]);
	}
	if (s->res_x > 2560)
		s->res_x = 2560;
	if (s->res_y > 1440)
		s->res_y = 1440;
	ft_del(dest);
	if (s->res_x <= 0 || s->res_y <= 0 || len != 3)
		ft_exit(s);
}

void	ft_set_dir(t_cub3d *s)
{
	if (s->dir == 'S')
		rot_left(s, M_PI);
	else if (s->dir == 'E')
		rot_right(s, (M_PI / 2));
	else if (s->dir == 'W')
		rot_left(s, (M_PI / 2));
}

void	ft_pos_calc(t_cub3d *s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s->map[i] && s->map[i][j] != s->dir)
	{
		j = 0;
		while (s->map[i][j] && s->map[i][j] != s->dir)
			j++;
		if (s->map[i][j] == s->dir)
			break ;
		i++;
	}
	s->pos.x = i + 0.5;
	s->pos.y = j + 0.5;
	set_vertex(-1, 0, &s->calc->dir);
	s->calc->plane.x = 0;
	s->calc->plane.y = 0.66;
	printf("oui\n");
	ft_raycasting(s);
	printf("non\n");
	ft_set_dir(s);
}
