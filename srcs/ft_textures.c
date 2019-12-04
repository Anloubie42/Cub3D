/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:17:04 by anloubie          #+#    #+#             */
/*   Updated: 2019/12/04 17:05:52 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubddd.h"

void		get_texture_2(t_cub3d *s)
{
	if (!(s->tab[3].ptr = mlx_xpm_file_to_image(s->data->mlx_ptr, s->path_w,
	&s->tab[3].len.x, &s->tab[3].len.y)))
		ft_exit(s);
	if (!(s->tab[3].addr = (int*)mlx_get_data_addr(s->tab[3].ptr,
	&s->tab[3].img.bpp, &s->tab[3].img.size, &s->tab[3].img.endian)))
		ft_exit(s);
	if (!(s->tab[4].ptr = mlx_xpm_file_to_image(s->data->mlx_ptr
	, s->path_sprite, &s->tab[4].len.x, &s->tab[4].len.y)))
		ft_exit(s);
	if (!(s->tab[4].addr = (int*)mlx_get_data_addr(s->tab[4].ptr,
	&s->tab[4].img.bpp, &s->tab[4].img.size, &s->tab[4].img.endian)))
		ft_exit(s);
}

void		get_texture(t_cub3d *s)
{
	if (!(s->tab[0].ptr = mlx_xpm_file_to_image(s->data->mlx_ptr, s->path_n,
	&s->tab[0].len.x, &s->tab[0].len.y)))
		ft_exit(s);
	if (!(s->tab[0].addr = (int*)mlx_get_data_addr(s->tab[0].ptr,
	&s->tab[0].img.bpp, &s->tab[0].img.size, &s->tab[0].img.endian)))
		ft_exit(s);
	if (!(s->tab[1].ptr = mlx_xpm_file_to_image(s->data->mlx_ptr, s->path_s,
	&s->tab[1].len.x, &s->tab[1].len.y)))
		ft_exit(s);
	if (!(s->tab[1].addr = (int*)mlx_get_data_addr(s->tab[1].ptr,
	&s->tab[1].img.bpp, &s->tab[1].img.size, &s->tab[1].img.endian)))
		ft_exit(s);
	if (!(s->tab[2].ptr = mlx_xpm_file_to_image(s->data->mlx_ptr, s->path_e,
	&s->tab[2].len.x, &s->tab[2].len.y)))
		ft_exit(s);
	if (!(s->tab[2].addr = (int*)mlx_get_data_addr(s->tab[2].ptr,
	&s->tab[2].img.bpp, &s->tab[2].img.size, &s->tab[2].img.endian)))
		ft_exit(s);
	get_texture_2(s);
}

void		put_pxl_tex(t_cub3d *s, int i, int a)
{
	int	d;

	s->tab[a].tex.x = (int)(s->calc->wall_x * (double)s->tab[a].len.y);
	if (s->calc->wall == 0 && s->calc->ray_dir.x > 0)
		s->tab[a].tex.x = s->tab[a].len.y - s->tab[a].tex.x - 1;
	if (s->calc->wall == 1 && s->calc->ray_dir.y < 0)
		s->tab[a].tex.x = s->tab[a].len.y - s->tab[a].tex.x - 1;
	d = i * 256 - s->res_y * 128 + s->calc->line_height * 128;
	s->tab[a].tex.y = ((d * s->tab[a].len.y) / s->calc->line_height) / 256;
	s->col->tab[s->calc->x + s->res_x * i] = s->tab[a].addr[s->tab[a].len.x
	* s->tab[a].tex.y + s->tab[a].tex.x];
}
