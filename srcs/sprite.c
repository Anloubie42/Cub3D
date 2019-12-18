/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:19:59 by anloubie          #+#    #+#             */
/*   Updated: 2019/12/13 15:13:59 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubddd.h"

void		draw_sprite(t_cub3d *s)
{
	int		j;

	j = 0;
	while (j < s->obj)
	{
		s->sp[j].co.x = s->sprite[s->sp[j].sprite_order].co.x - s->pos.x;
		s->sp[j].co.y = s->sprite[s->sp[j].sprite_order].co.y - s->pos.y;
		s->sp[j].inv_det = 1.0 / (s->calc->plane.x * s->calc->dir.y
		- s->calc->dir.x * s->calc->plane.y);
		s->sp[j].transform.x = s->sp[j].inv_det * (s->calc->dir.y
		* s->sp[j].co.x - s->calc->dir.x * s->sp[j].co.y);
		s->sp[j].transform.y = s->sp[j].inv_det * (-s->calc->plane.y
		* s->sp[j].co.x + s->calc->plane.x * s->sp[j].co.y);
		s->sp[j].sprite_screen_x = (int)((s->res_x / 2)
		* (1 + s->sp[j].transform.x / s->sp[j].transform.y));
		s->sp[j].v_move_screen = (int)(VMOVE / s->sp[j].transform.y);
		s->sp[j].sprite_h = abs((int)(s->res_y / s->sp[j].transform.y)) / VDIV;
		s->sp[j].draw_start.y = -s->sp[j].sprite_h / 2
		+ s->res_y / 2 + s->sp[j].v_move_screen;
		if (s->sp[j].draw_start.y < 0)
			s->sp[j].draw_start.y = 0;
		draw_sprite2(s, j);
		j++;
	}
}

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

void		sprite_swap(t_cub3d *s, int j)
{
	t_sprite	tmp;

	tmp = s->sp[j];
	s->sp[j] = s->sp[j + 1];
	s->sp[j + 1] = tmp;
}

void		sort_sprite2(t_cub3d *s)
{
	t_vertex_d	div;
	double		res[s->obj];
	int			j;
	double		tmp;

	j = -1;
	while (++j < s->obj)
	{
		div.x = fabs(s->pos.x - s->sprite[j].co.x);
		div.y = fabs(s->pos.y - s->sprite[j].co.y);
		res[j] = div.x + div.y;
	}
	j = -1;
	while (++j < s->obj)
	{
		if (res[j] < res[j + 1])
		{
			tmp = res[j];
			res[j] = res[j + 1];
			res[j + 1] = tmp;
			sprite_swap(s, j);
			j = -1;
		}
	}
}

void		sort_sprite(t_cub3d *s)
{
	int	j;

	j = 0;
	s->sprite->zbuffer[s->calc->x] = s->calc->perp_wall_dist;
	while (j < s->obj)
	{
		s->sp[j].sprite_order = j;
		s->sp[j].sprite_distance = ((s->pos.x - s->sprite[j].co.x)
		* (s->pos.x - s->sprite[j].co.x) + (s->pos.y - s->sprite[j].co.y)
		* (s->pos.y - s->sprite[j].co.y));
		j++;
	}
	draw_sprite(s);
	sort_sprite2(s);
}
