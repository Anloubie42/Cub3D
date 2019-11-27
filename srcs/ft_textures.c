/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:17:04 by anloubie          #+#    #+#             */
/*   Updated: 2019/11/27 18:12:05 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubddd.h"

void		get_texture(t_cub3d *s)
{
	t_texture	*tab;

	tab = malloc(sizeof(t_texture));
	if (!(tab->ptr = mlx_xpm_file_to_image(s->data->mlx_ptr, s->path_n,
	&tab->len.x, &tab->len.y)))
		ft_exit(s);
	printf("tab[0] = %s\n", (char*)tab->ptr);
}
