/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:19:59 by anloubie          #+#    #+#             */
/*   Updated: 2019/12/04 17:55:49 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubddd.h"

void		sprite_count(t_cub3d *s, char *str, int count)
{
	static int	j = 0;
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '2')
		{
			s->sprite[j].co.x = count + 0.5;
			s->sprite[j].co.y = i + 0.5;
			j++;
		}
		i++;
	}
}

void		sort_sprite(t_cub3d *s)
{
	int	i;

	i = 0;
	while (i < s->obj)
	{
		s->sp.sprite_order[i] = i;
		s->sp.sprite_distance[i] = ((s->pos.x - s->sprite[i].co.x)
		* (s->pos.x - s->sprite[i].co.x) + (s->pos.y - s->sprite[i].co.y)
		* (s->pos.y - s->sprite[i].co.y));
	}
}

void		tex_sprite_init2(t_cub3d *s)
{
	int		y;

	y = s->calc->draw_end + 1;
	while (y < s->res_y)
	{
		s->sp.current_dist = s->res_y / (2.0 * y - s->res_y);
		s->sp.weight = (s->sp.current_dist - s->sp.dist_player)
		/ (s->sp.dist_wall - s->sp.dist_player);
		s->sp.current_floor.x = s->sp.weight
		* s->sp.floor_wall.x + (1.0 - s->sp.weight) * s->pos.x;
		s->sp.current_floor.y = s->sp.weight
		* s->sp.floor_wall.y + (1.0 - s->sp.weight) * s->pos.y;
		s->sp.floor_tex.x = ((int)(s->sp.current_floor.x * s->tab[4].len.x)
		% s->tab[4].len.x);
		s->sp.floor_tex.y = ((int)(s->sp.current_floor.y * s->tab[4].len.y)
		% s->tab[4].len.y);
		y++;
	}
	sort_sprite(s);
}

void		tex_sprite_init(t_cub3d *s)
{
	s->sp.zbuffer[s->calc->x] = s->calc->perp_wall_dist;
	if (s->calc->wall == 0 && s->calc->ray_dir.x > 0)
	{
		s->sp.floor_wall.x = s->calc->map.x;
		s->sp.floor_wall.y = s->calc->map.y + s->calc->wall_x;
	}
	else if (s->calc->wall == 0 && s->calc->ray_dir.x < 0)
	{
		s->sp.floor_wall.x = s->calc->map.x + 1.0;
		s->sp.floor_wall.y = s->calc->map.y + s->calc->wall_x;
	}
	else if (s->calc->wall == 1 && s->calc->ray_dir.y > 0)
	{
		s->sp.floor_wall.x = s->calc->map.x + s->calc->wall_x;
		s->sp.floor_wall.y = s->calc->map.y;
	}
	else if (s->calc->wall == 1 && s->calc->ray_dir.y < 0)
	{
		s->sp.floor_wall.x = s->calc->map.x + s->calc->wall_x;
		s->sp.floor_wall.y = s->calc->map.y + 1.0;
	}
	s->sp.dist_wall = s->calc->perp_wall_dist;
	s->sp.dist_player = 0.0;
	tex_sprite_init2(s);
}
