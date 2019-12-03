/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:37:00 by anloubie          #+#    #+#             */
/*   Updated: 2019/12/03 17:43:14 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubddd.h"

int			ft_get_color(int red, int green, int blue)
{
	int		color;

	color = 1;
	color = color | (red << 16);
	color = color | (green << 8);
	color = color | blue;
	return (color);
}

void		ft_create_img(t_cub3d *s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(s->col = (t_color*)malloc(sizeof(t_color))))
		ft_exit(s);
	s->data->img_ptr = mlx_new_image(s->data->mlx_ptr, s->res_x, s->res_y);
	s->col->tab = (int*)mlx_get_data_addr(s->data->img_ptr, &s->col->bpp,
	&s->col->size, &s->col->endian);
}

void		which_wall(t_cub3d *s)
{
	while (s->calc->hit == 0)
	{
		if (s->calc->dist_wall.x < s->calc->dist_wall.y)
		{
			s->calc->dist_wall.x += s->calc->delta_dist.x;
			s->calc->map.x += s->calc->step.x;
			s->calc->wall = 0;
		}
		else
		{
			s->calc->dist_wall.y += s->calc->delta_dist.y;
			s->calc->map.y += s->calc->step.y;
			s->calc->wall = 1;
		}
		if (s->map[s->calc->map.x][s->calc->map.y] == '1')
			s->calc->hit = 1;
		if (s->map[s->calc->map.x][s->calc->map.y] == '2')
		{
			s->calc->save.x = s->calc->map.x;
			s->calc->save.y = s->calc->map.y;
			s->calc->hit_s = 1;
		}
	}
}

void		set_vertex(double a, double b, t_vertex_d *vertex)
{
	vertex->x = a;
	vertex->y = b;
}
