/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 14:57:02 by anloubie          #+#    #+#             */
/*   Updated: 2020/02/06 11:40:56 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubddd.h"

void		free_path(t_cub3d *s)
{
	ft_clear(&s->path_n);
	ft_clear(&s->path_s);
	ft_clear(&s->path_e);
	ft_clear(&s->path_w);
	ft_clear(&s->path_sprite);
}

void		free_col(t_cub3d *s)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		if (s->col_c[i] > 255 || s->col_c[i] < 0)
			ft_exit(s, "invalid color");
		if (s->col_f[i] > 255 || s->col_f[i] < 0)
			ft_exit(s, "invalid color");
		i++;
	}
	free(s->col_c);
	free(s->col_f);
}

void		free_shot(t_screen *shot)
{
	free(shot->file_name);
	free(shot->file);
	free(shot->header);
}
