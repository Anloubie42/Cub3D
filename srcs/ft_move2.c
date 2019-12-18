/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 13:51:55 by anloubie          #+#    #+#             */
/*   Updated: 2019/12/18 13:11:58 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubddd.h"

void		move_right(t_cub3d *s)
{
	t_vertex_d	new_dir;
	double		rot_speed;

	rot_speed = (M_PI / 2);
	new_dir.x = s->calc->dir.x * cos(rot_speed) - s->calc->dir.y
	* sin(rot_speed);
	new_dir.y = s->calc->dir.x * sin(rot_speed) + s->calc->dir.y
	* cos(rot_speed);
	if (s->map[(int)(s->pos.x - new_dir.x * MSPEED)][(int)s->pos.y] != '1'
	&& s->map[(int)(s->pos.x - new_dir.x * MSPEED)][(int)s->pos.y] != '2')
		s->pos.x -= new_dir.x * MSPEED;
	if (s->map[(int)s->pos.x][(int)(s->pos.y - new_dir.y * MSPEED)] != '1'
	&& s->map[(int)s->pos.x][(int)(s->pos.y - new_dir.y * MSPEED)] != '2')
		s->pos.y -= new_dir.y * MSPEED;
	ft_raycasting(s);
}
