/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:42:02 by anloubie          #+#    #+#             */
/*   Updated: 2019/12/03 15:35:09 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubddd.h"

void		move_foreward(t_cub3d *s)
{
	if (s->map[(int)(s->pos.x + s->calc->dir.x * MSPEED)][(int)s->pos.y] != '1')
		s->pos.x += s->calc->dir.x * MSPEED;
	if (s->map[(int)s->pos.x][(int)(s->pos.y + s->calc->dir.y * MSPEED)] != '1')
		s->pos.y += s->calc->dir.y * MSPEED;
	ft_raycasting(s);
}

void		move_backwards(t_cub3d *s)
{
	if (s->map[(int)(s->pos.x - s->calc->dir.x * MSPEED)][(int)s->pos.y] != '1')
		s->pos.x -= s->calc->dir.x * MSPEED;
	if (s->map[(int)s->pos.x][(int)(s->pos.y - s->calc->dir.y * MSPEED)] != '1')
		s->pos.y -= s->calc->dir.y * MSPEED;
	ft_raycasting(s);
}

void		rot_right(t_cub3d *s, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = s->calc->dir.x;
	old_plane_x = s->calc->plane.x;
	s->calc->dir.x = s->calc->dir.x * cos(-rot_speed) - s->calc->dir.y
	* sin(-rot_speed);
	s->calc->dir.y = old_dir_x * sin(-rot_speed) + s->calc->dir.y
	* cos(-rot_speed);
	s->calc->plane.x = s->calc->plane.x * cos(-rot_speed) - s->calc->plane.y
	* sin(-rot_speed);
	s->calc->plane.y = old_plane_x * sin(-rot_speed) + s->calc->plane.y
	* cos(-rot_speed);
	ft_raycasting(s);
}

void		rot_left(t_cub3d *s, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = s->calc->dir.x;
	old_plane_x = s->calc->plane.x;
	s->calc->dir.x = s->calc->dir.x * cos(rot_speed) - s->calc->dir.y
	* sin(rot_speed);
	s->calc->dir.y = old_dir_x * sin(rot_speed) + s->calc->dir.y
	* cos(rot_speed);
	s->calc->plane.x = s->calc->plane.x * cos(rot_speed) - s->calc->plane.y
	* sin(rot_speed);
	s->calc->plane.y = old_plane_x * sin(rot_speed) + s->calc->plane.y
	* cos(rot_speed);
	ft_raycasting(s);
}
