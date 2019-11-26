/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:37:00 by anloubie          #+#    #+#             */
/*   Updated: 2019/11/26 14:10:31 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

int			ft_get_color(int red, int green, int blue)
{
	int		color;

	color = 0;
	color = color | (red << 16);
	color = color | (green << 8);
	color = color | blue;
	return (color);
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
	ft_get_color(255, 125, 125);
}
