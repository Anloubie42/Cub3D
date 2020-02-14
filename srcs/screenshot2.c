/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 12:52:48 by anloubie          #+#    #+#             */
/*   Updated: 2020/01/10 14:50:46 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubddd.h"

void	name_screen2(t_cub3d *s, t_screen *shot)
{
	if (!(shot->file_name = ft_strjoinfree(shot->file_name, ":", 1)))
		ft_exit(s, "Malloc failed");
	if (!(shot->file_name = ft_strjoinfree(shot->file_name,
	ft_itoa(shot->timecomp->tm_sec), 3)))
		ft_exit(s, "Malloc failed");
}
