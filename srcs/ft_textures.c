/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:17:04 by anloubie          #+#    #+#             */
/*   Updated: 2019/11/28 13:40:34 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubddd.h"

void		get_texture(t_cub3d *s)
{
	t_texture	tab;

	if (!(tab.ptr = mlx_xpm_file_to_image(s->data->mlx_ptr, s->path_n,
	&tab.len.x, &tab.len.y)))
		ft_exit(s);
	if (!(tab.addr = (int*)mlx_get_data_addr(s->data->img_ptr, &tab.img.bpp,
	&tab.img.size, &tab.img.endian)))
		ft_exit(s);
	// s->tab = tab;
}
