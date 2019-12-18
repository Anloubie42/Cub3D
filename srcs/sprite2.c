/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 12:23:06 by anloubie          #+#    #+#             */
/*   Updated: 2019/12/13 15:14:01 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubddd.h"

void		draw_sprite2(t_cub3d *s, int j)
{
	s->sp[j].draw_end.y = s->sp[j].sprite_h / 2
	+ s->res_y / 2 + s->sp[j].v_move_screen;
	if (s->sp[j].draw_end.y >= s->res_y)
		s->sp[j].draw_end.y = s->res_y - 1;
	s->sp[j].sprite_w = abs((int)(s->res_y
	/ (s->sp[j].transform.y))) / UDIV;
	s->sp[j].draw_start.x = -s->sp[j].sprite_w / 2
	+ s->sp[j].sprite_screen_x;
	if (s->sp[j].draw_start.x < 0)
		s->sp[j].draw_start.x = 0;
	s->sp[j].draw_end.x = s->sp[j].sprite_w
	/ 2 + s->sp[j].sprite_screen_x;
	if (s->sp[j].draw_end.x >= s->res_x)
		s->sp[j].draw_end.x = s->res_x - 1;
}

void		aff_sprite(t_cub3d *s, int i, int j)
{
	int		d;
	int		color;

	s->tab[4].tex.x = (int)(256 * (s->calc->x - (-s->sp[j].sprite_w / 2
	+ s->sp[j].sprite_screen_x)) * s->tab[4].len.x / s->sp[j].sprite_w) / 256;
	if (s->sp[j].transform.y > 0 && s->calc->x > 0 && s->calc->x < s->res_x
	&& s->sp[j].transform.y < s->sprite->zbuffer[s->calc->x])
	{
		d = (i - s->sp[j].v_move_screen) * 256 - s->res_y * 128
		+ s->sp[j].sprite_h * 128;
		s->tab[4].tex.y = ((d * s->tab[4].len.y) / s->sp[j].sprite_h) / 256;
		color = s->tab[4].addr[s->tab[4].len.x * s->tab[4].tex.y
		+ s->tab[4].tex.x];
		if ((color & 0x00FFFFFF) != 0)
			s->col->tab[s->calc->x + s->res_x * i] = color;
	}
}

void		sprite_draw(t_cub3d *s, int i)
{
	int		j;

	j = 0;
	while (j < s->obj)
	{
		if (s->calc->x > s->sp[j].draw_start.x
		&& s->calc->x < s->sp[j].draw_end.x && i > s->sp[j].draw_start.y
		&& i < s->sp[j].draw_end.y)
			aff_sprite(s, i, j);
		j++;
	}
}
