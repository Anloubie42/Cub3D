/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:42:02 by anloubie          #+#    #+#             */
/*   Updated: 2019/11/26 16:21:02 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"
#define MSPEED 0.1
#define RSPEED 0.05

void		move_foreward(t_Cub3D *s)
{
	printf("posX = %f\nposY = %f\n", s->pos.x, s->pos.y);
	if (s->map[(int)(s->pos.x + s->calc->dir.x * MSPEED)][(int)s->pos.y] != '1')
		s->pos.x += s->calc->dir.x * MSPEED;
	else if (s->map[(int)s->pos.x][(int)(s->pos.y + s->calc->dir.y * MSPEED)] != '1')
		s->pos.y += s->calc->dir.y * MSPEED;
	ft_raycasting(s);
}

void		move_backwards(t_Cub3D *s)
{
	printf("posX = %f\nposY = %f\n", s->pos.x, s->pos.y);
	if (s->map[(int)(s->pos.x - s->calc->dir.x * MSPEED)][(int)s->pos.y] != '1')
		s->pos.x -= s->calc->dir.x * MSPEED;
	else if (s->map[(int)s->pos.x][(int)(s->pos.y - s->calc->dir.y * MSPEED)] != '1')
		s->pos.y -= s->calc->dir.y * MSPEED;
	ft_raycasting(s);
}

void		rot_right(t_Cub3D *s)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = s->calc->dir.x;
	old_plane_x = s->calc->plane.x;
	s->calc->dir.x = s->calc->dir.x * cos(-RSPEED) - s->calc->dir.y * sin(-RSPEED);
	s->calc->dir.y = old_dir_x * sin(-RSPEED) + s->calc->dir.y * cos(-RSPEED);
	s->calc->plane.x = s->calc->plane.x * cos(-RSPEED) - s->calc->plane.y * sin(-RSPEED);
	s->calc->plane.y = old_plane_x * sin(-RSPEED) + s->calc->plane.y * cos(-RSPEED);
	ft_raycasting(s);
}

void		rot_left(t_Cub3D *s)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = s->calc->dir.x;
	old_plane_x = s->calc->plane.x;
	s->calc->dir.x = s->calc->dir.x * cos(RSPEED) - s->calc->dir.y * sin(RSPEED);
	s->calc->dir.y = old_dir_x * sin(RSPEED) + s->calc->dir.y * cos(RSPEED);
	s->calc->plane.x = s->calc->plane.x * cos(RSPEED) - s->calc->plane.y * sin(RSPEED);
	s->calc->plane.y = old_plane_x * sin(RSPEED) + s->calc->plane.y * cos(RSPEED);
	ft_raycasting(s);
}
