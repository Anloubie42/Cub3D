/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:52:15 by anloubie          #+#    #+#             */
/*   Updated: 2019/12/03 17:55:26 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubddd.h"

void		draw_2(t_cub3d *s)
{
	int		i;

	i = -1;
	while (++i < s->res_y)
	{
		if (i > s->calc->draw_end)
			s->col->tab[s->calc->x + s->res_x * i] = ft_get_color(s->col_f[0],
			s->col_f[1], s->col_f[2]);
		else if ((i <= s->calc->draw_end) && (i >= s->calc->draw_start)
		&& (s->calc->wall == 0))
			(s->calc->ray_dir.x < 0) ? put_pxl_tex(s, i, 1)
			: put_pxl_tex(s, i, 0);
		else if (i <= s->calc->draw_end && i >= s->calc->draw_start &&
		s->calc->wall == 1)
			(s->calc->ray_dir.y < 0) ? put_pxl_tex(s, i, 2)
			: put_pxl_tex(s, i, 3);
		else if (i < s->calc->draw_start)
			s->col->tab[s->calc->x + s->res_x * i] =
			ft_get_color(s->col_c[0], s->col_c[1], s->col_c[2]);
		//if ((i <= s->calc->draw_end) && (i >= s->calc->draw_start)
		//&& (s->map[s->calc->save.x][(int)s->calc->save.y] == '2') && s->calc->hit_s)
		//	put_pxl_tex(s, i, 4);
		//if ((i <= s->calc->draw_end) && (i >= s->calc->draw_start) && s->map[s->calc->save.x][(int)s->calc->save.y] == '2')
		//	s->col->tab[s->calc->x + s->res_x * i] = ft_get_color(255, 0, 0);
	}
}

void		draw(t_cub3d *s)
{
	s->calc->wall_x -= floor((s->calc->wall_x));
	s->calc->line_height = (int)(s->res_y / s->calc->perp_wall_dist);
	s->calc->draw_start = -s->calc->line_height / 2 + s->res_y / 2;
	s->calc->draw_start < 0 ? s->calc->draw_start = 0 : 0;
	s->calc->draw_end = s->calc->line_height / 2 + s->res_y / 2;
	s->calc->draw_end >= s->res_y ? s->calc->draw_end = s->res_y - 1 : 0;
	draw_2(s);
}

void		ft_init_side_dist(t_cub3d *s)
{
	if (s->calc->ray_dir.x < 0)
	{
		s->calc->step.x = -1;
		s->calc->dist_wall.x = (s->pos.x - s->calc->map.x)
		* (s->calc->delta_dist.x);
	}
	else
	{
		s->calc->step.x = 1;
		s->calc->dist_wall.x = (s->calc->map.x + 1.0 - s->pos.x)
		* s->calc->delta_dist.x;
	}
	if (s->calc->ray_dir.y < 0)
	{
		s->calc->step.y = -1;
		s->calc->dist_wall.y = (s->pos.y - s->calc->map.y)
		* s->calc->delta_dist.y;
	}
	else
	{
		s->calc->step.y = 1;
		s->calc->dist_wall.y = (s->calc->map.y + 1.0 - s->pos.y)
		* s->calc->delta_dist.y;
	}
}

void		ft_init_raycasting(t_cub3d *s)
{
	s->calc->camera_x = 2 * s->calc->x / (double)s->res_x - 1;
	s->calc->ray_dir.x = s->calc->dir.x + s->calc->plane.x * s->calc->camera_x;
	s->calc->ray_dir.y = s->calc->dir.y + s->calc->plane.y * s->calc->camera_x;
	s->calc->map.x = (int)s->pos.x;
	s->calc->map.y = (int)s->pos.y;
	s->calc->delta_dist.x = fabs(1 / s->calc->ray_dir.x);
	s->calc->delta_dist.y = fabs(1 / s->calc->ray_dir.y);
	s->calc->hit = 0;
	s->calc->hit_s = 0;
}

void		ft_raycasting(t_cub3d *s)
{
	s->calc->x = 0;
	while (s->calc->x < s->res_x)
	{
		ft_init_raycasting(s);
		ft_init_side_dist(s);
		which_wall(s);
		if (s->calc->wall == 0)
		{
			s->calc->perp_wall_dist = (s->calc->map.x - s->pos.x
			+ (1 - s->calc->step.x) / 2) / s->calc->ray_dir.x;
			s->calc->wall_x = s->pos.y + s->calc->perp_wall_dist
			* s->calc->ray_dir.y;
		}
		else
		{
			s->calc->perp_wall_dist = (s->calc->map.y - s->pos.y
			+ (1 - s->calc->step.y) / 2) / s->calc->ray_dir.y;
			s->calc->wall_x = s->pos.x + s->calc->perp_wall_dist
			* s->calc->ray_dir.x;
		}
		draw(s);
		s->calc->x++;
	}
	mlx_put_image_to_window(s->data->mlx_ptr, s->data->mlx_win,
	s->data->img_ptr, 0, 0);
}
