/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 14:46:15 by anloubie          #+#    #+#             */
/*   Updated: 2020/01/31 14:01:10 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubddd.h"

void		screen_set(t_cub3d *s)
{
	ft_raycasting(s);
	if (s->screen == 1)
	{
		screen(s);
		exit(1);
	}
}

void		malloc_set(t_cub3d *s)
{
	if (s->obj > 0)
	{
		if (!(s->sprite = (t_info*)malloc(sizeof(t_info) * s->obj)))
			ft_exit(s, "Malloc failed");
		if (!(s->sp = (t_sprite*)malloc(sizeof(t_sprite) * s->obj)))
			ft_exit(s, "Malloc failed");
		if (!(s->sprite->zbuffer = (double*)malloc(sizeof(double) * s->res_x)))
			ft_exit(s, "Malloc failed");
	}
}
