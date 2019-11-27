/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:09:17 by anloubie          #+#    #+#             */
/*   Updated: 2019/11/27 16:48:13 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubddd.h"

int		ft_exit(t_cub3d *s)
{
	(void)s;
	if (s->data->mlx_ptr && s->data->mlx_win)
		mlx_destroy_window(s->data->mlx_ptr, s->data->mlx_win);
	free(s->data);
	exit(0);
	return (0);
}
