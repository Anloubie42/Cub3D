/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:52:15 by anloubie          #+#    #+#             */
/*   Updated: 2019/11/26 16:08:36 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void		draw(t_Cub3D *s)
{
	int	i;

	i = 0;
	s->calc->line_height = (int)(s->res_y / s->calc->perp_wall_dist);
	s->calc->draw_start = -s->calc->line_height / 2 + s->res_y / 2;
	s->calc->draw_start < 0 ? s->calc->draw_start = 0 : 0;
	s->calc->draw_end = s->calc->line_height / 2 + s->res_y / 2;
	s->calc->draw_end >= s->res_y ? s->calc->draw_end = s->res_y - 1 : 0;
	while (i < s->res_y)
	{
		if (i > s->calc->draw_end)
			s->col->tab[s->calc->x + s->res_x * i] =
			ft_get_color(s->col_f[0], s->col_f[1], s->col_f[2]);
		else if (i <= s->calc->draw_end && i >= s->calc->draw_start)
			s->col->tab[s->calc->x + s->res_x * i] = ft_get_color(166, 132, 138);
		else if (i < s->calc->draw_start)
			s->col->tab[s->calc->x + s->res_x * i] =
			ft_get_color(s->col_c[0], s->col_c[1], s->col_c[2]);
		i++;
	}
}

void		ft_init_side_dist(t_Cub3D *s)
{
	if (s->calc->ray_dir.x < 0)
	{
		s->calc->step.x = -1;
		s->calc->dist_wall.x = (s->pos.x - s->calc->map.x)
		* s->calc->delta_dist.x;
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

void		ft_init_raycasting(t_Cub3D *s)
{
	s->calc->camera_x = 2 * s->calc->x / (double)s->res_x - 1;
	s->calc->ray_dir.x = s->calc->dir.x + s->calc->plane.x * s->calc->camera_x;
	s->calc->ray_dir.y = s->calc->dir.y + s->calc->plane.y * s->calc->camera_x;
	s->calc->map.x = (int)s->pos.x;
	s->calc->map.y = (int)s->pos.y;
	s->calc->plane.x = 0;
	s->calc->plane.y = 0.66;
	s->calc->delta_dist.x = fabs(1 / s->calc->ray_dir.x);
	s->calc->delta_dist.y = fabs(1 / s->calc->ray_dir.y);
	s->calc->hit = 0;
}

void		set_vertex(double a, double b, t_vertex_d *vertex)
{
	vertex->x = a;
	vertex->y = b;
}

void		ft_set_dir(t_Cub3D *s)
{
	if (s->dir == 'N')
		set_vertex(-1, 0, &s->calc->dir);
	else if (s->dir == 'S')
		set_vertex(1, 0, &s->calc->dir);
	else if (s->dir == 'E')
		set_vertex(-1, -1, &s->calc->dir);
	else if (s->dir == 'W')
		set_vertex(-1, 1, &s->calc->dir);
	printf("X = %f\nY = %f\n", s->calc->dir.x, s->calc->dir.y);
}

void		ft_raycasting(t_Cub3D *s)
{
	s->calc->x = 0;
	while (s->calc->x < s->res_x)
	{
		ft_init_raycasting(s);
		ft_init_side_dist(s);
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
			if (s->map[s->calc->map.x][s->calc->map.y] != '0' && s->map[s->calc->map.x][s->calc->map.y] != s->dir)
				s->calc->hit = 1;
		}
		if (s->calc->wall == 0)
			s->calc->perp_wall_dist = (s->calc->map.x - s->pos.x
			+ (1 - s->calc->step.x) / 2) / s->calc->ray_dir.x;
		else
			s->calc->perp_wall_dist = (s->calc->map.y - s->pos.y
			+ (1 - s->calc->step.y) / 2) / s->calc->ray_dir.y;
		draw(s);
		s->calc->x++;
	}
	mlx_put_image_to_window(s->data->mlx_ptr, s->data->mlx_win, s->data->img_ptr, 0, 0);
}

void		ft_pos_calc(t_Cub3D *s)
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
	ft_set_dir(s);
	ft_raycasting(s);
}
