/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:52:15 by anloubie          #+#    #+#             */
/*   Updated: 2019/11/25 18:04:41 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

/*void		ft_display(t_Cub3D *s)
{
	int	*test;
	int		i = 0;
	int		a;
	int		b;
	int		c;
	int blue, red, green, color;

	s->data.img_ptr = mlx_new_image(s->data.mlx_ptr, s->res_x, s->res_y);
	test = (int*)mlx_get_data_addr(s->data.img_ptr, &a, &b, &c);
	red = 255;
	blue = 125;
	green = 125;
	color = 0;
	color = color | (red << 16);
	color = color | (green << 8);
	color = color | (blue << 0);
	int j = 0;
	b /= 4;
	while (j < s->res_y)
	{
		i = b * j;
		while (i <= b + j * b)
			test[i++] = color;
		j++;
	}
	// printf("%d\n", b);
	// printf("%d\n", c);
	// while (j < s->res_y)
	// {
		// i = b * j;
		// while (i <= b + j * b - 4)
		// {
			// test[i] = blue;
			// test[i + 1] = green;
			// test[i + 2] = red;
			// test[i + 3] = 0;
			// i += 4;
		// }
		// j++;
	// }
	mlx_put_image_to_window (s->data.mlx_ptr, s->data.mlx_win, s->data.img_ptr, 0, 0);
}*/

void		ft_dist_calc_2(t_Cub3D *s)
{
	while (s->calc->key == 0)
	{
		if (s->calc->dist_wall_x < s->calc->dist_wall_y)
		{
			s->calc->dist_wall_x += s->calc->dist2_wall_x;
			s->calc->map_x += s->calc->step_x;
			s->calc->wall = 0;
		}
		else
		{
			s->calc->dist_wall_y += s->calc->dist2_wall_y;
			s->calc->map_y += s->calc->step_y;
			s->calc->wall = 1;
		}
		if (s->map[s->calc->map_x][s->calc->map_y] > '0')
			s->calc->key = 1;
	}
	ft_proj_cam(s);
}

void		ft_dist_calc(t_Cub3D *s)
{
	if (s->calc->ray_dir_x < 0)
	{
		s->calc->step_x = -1;
		s->calc->dist_wall_x = (s->calc->ray_pos_x - s->calc->map_x)
		* s->calc->dist2_wall_x;
	}
	else
	{
		s->calc->step_x = 1;
		s->calc->dist_wall_x = (s->calc->map_x + 1.0 - s->calc->ray_pos_x)
		* s->calc->dist2_wall_x;
	}
	if (s->calc->ray_dir_y < 0)
	{
		s->calc->step_y = -1;
		s->calc->dist_wall_y = (s->calc->ray_pos_y - s->calc->map_y)
		* s->calc->dist2_wall_y;
	}
	else
	{
		s->calc->step_y = 1;
		s->calc->dist_wall_y = (s->calc->map_y + 1.0 - s->calc->ray_pos_y)
		* s->calc->dist2_wall_y;
	}
	ft_dist_calc_2(s);
}

void		ft_init_calc_2(t_Cub3D *s)
{
	s->calc->x = 0;

	while (s->calc->x < s->res_x)
	{
		s->calc->camera_x = (2 * s->calc->x) / (double)s->res_x - 1;
		s->calc->ray_pos_x = s->start_x;
		s->calc->ray_pos_y = s->start_y;
		s->calc->ray_dir_x = s->calc->dir_x + s->calc->plane_x
		* s->calc->camera_x;
		s->calc->ray_dir_y = s->calc->dir_y + s->calc->plane_y
		* s->calc->camera_x;
		s->calc->map_x = (int)s->calc->ray_pos_x;
		s->calc->map_y = (int)s->calc->ray_pos_y;
		s->calc->dist2_wall_x = sqrt(1
		+ (s->calc->ray_dir_y * s->calc->ray_dir_y)
		/ (s->calc->ray_dir_x * s->calc->ray_dir_x));
		s->calc->dist2_wall_y = sqrt(1
		+ (s->calc->ray_dir_x * s->calc->ray_dir_x)
		/ (s->calc->ray_dir_y * s->calc->ray_dir_y));
		ft_dist_calc(s);
		s->calc->x++;
	}
	mlx_put_image_to_window(s->data->mlx_ptr, s->data->mlx_win,
	s->data->img_ptr, 0, 0);
}

void		ft_init_calc(t_Cub3D *s)
{
	s->calc->dir_x = -1;
	s->calc->dir_y = 0;
	s->calc->plane_x = 0;
	s->calc->plane_y = 0.66;
	s->calc->time = 0;
	s->calc->old_time = 0;
	s->calc->key = 0;
	ft_init_calc_2(s);
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
	s->start_x = i;
	s->start_y = j;
	ft_init_calc(s);
}
