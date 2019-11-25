/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:09:17 by anloubie          #+#    #+#             */
/*   Updated: 2019/11/25 14:43:25 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

int		ft_exit(t_Cub3D *s)
{
	(void)s;
	if (s->data->mlx_ptr && s->data->mlx_win)
		mlx_destroy_window(s->data->mlx_ptr, s->data->mlx_win);
	free(s->data);
	exit(0);
	return (0);
}
