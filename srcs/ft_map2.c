/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 12:50:59 by anloubie          #+#    #+#             */
/*   Updated: 2020/02/06 14:06:03 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubddd.h"

void		map_valid3(t_cub3d *s)
{
	int		i;

	i = 0;
	while (s->map[0][i])
		if (s->map[0][i++] != '1')
			ft_exit(s, "invalid map");
	i = 0;
	while (s->map[s->map_h - 1][i])
		if (s->map[s->map_h - 1][i++] != '1')
			ft_exit(s, "invalid map");
	if (s->map_h < 3 || s->map_w < 3)
		ft_exit(s, "invalid map : map must be at least 3x3");
}
