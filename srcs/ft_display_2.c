/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:37:00 by anloubie          #+#    #+#             */
/*   Updated: 2019/11/25 18:00:24 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void		ft_get_color(t_color *col, int red, int green, int blue)
{
	col->red = red;
	col->green = green;
	col->blue = blue;
	col->color = 0;
	col->color = col->color | (red << 16);
	col->color = col->color | (green << 8);
	col->color = col->color | (blue << 0);
}

void		ft_create_img(t_Cub3D *s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(s->col = (t_color*)malloc(sizeof(t_color))))
		ft_exit(s);
	s->data->img_ptr = mlx_new_image(s->data->mlx_ptr, s->res_x, s->res_y);
	s->col->tab = (int*)mlx_get_data_addr(s->data->img_ptr, &s->col->bpp,
	&s->col->size, &s->col->endian);
	ft_get_color(s->col, 255, 125, 125);
}

void		ft_proj_cam(t_Cub3D *s)
{
	int		i;

	i = s->calc->draw_start;
	if (s->calc->wall == 0)
		s->calc->size_wall = fabs((s->calc->map_x - s->calc->ray_pos_x
		+ (1 - s->calc->step_x) / 2) / s->calc->ray_dir_x);
	else
		s->calc->size_wall = fabs((s->calc->map_y - s->calc->ray_pos_y
		+ (1 - s->calc->step_y) / 2) / s->calc->ray_dir_y);
	s->calc->wall_h = abs((int)(s->map_h / s->calc->size_wall));
	s->calc->draw_start = (s->calc->wall_h * -1) / 2 + s->map_h / 2;
	if (s->calc->draw_start < 0)
		s->calc->draw_start = 0;
	s->calc->draw_end = s->calc->wall_h / 2 + s->map_h / 2;
	if (s->calc->draw_end >= s->map_h)
		s->calc->draw_end = s->map_h;
	while (i < s->calc->draw_end)
		s->col->tab[s->calc->x * i++] = s->col->color;
}
