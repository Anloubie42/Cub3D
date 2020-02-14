/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 11:19:42 by anloubie          #+#    #+#             */
/*   Updated: 2020/01/14 13:26:15 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubddd.h"
#include <errno.h>

void		name_screen(t_cub3d *s, t_screen *shot)
{
	if (!(shot->file_name = ft_strjoinfree(shot->file_name,
	ft_itoa(shot->timecomp->tm_mday), 3)))
		ft_exit(s, "Malloc failed");
	if (!(shot->file_name = ft_strjoinfree(shot->file_name, " ", 1)))
		ft_exit(s, "Malloc failed");
	if (!(shot->file_name = ft_strjoinfree(shot->file_name,
	ft_itoa(shot->timecomp->tm_hour), 3)))
		ft_exit(s, "Malloc failed");
	if (!(shot->file_name = ft_strjoinfree(shot->file_name, ":", 1)))
		ft_exit(s, "Malloc failed");
	if (!(shot->file_name = ft_strjoinfree(shot->file_name,
	ft_itoa(shot->timecomp->tm_min), 3)))
		ft_exit(s, "Malloc failed");
	name_screen2(s, shot);
}

void		time_init(t_cub3d *s, t_screen *shot)
{
	time_t		timeact;

	time(&timeact);
	shot->timecomp = localtime(&timeact);
	shot->file_name = ft_strdup("Screenshots/");
	if (!(shot->file_name = ft_strjoinfree(shot->file_name,
	ft_itoa(shot->timecomp->tm_year + 1900), 3)))
		ft_exit(s, "Malloc failed");
	if (!(shot->file_name = ft_strjoinfree(shot->file_name, ":", 1)))
		ft_exit(s, "Malloc failed");
	if (!(shot->file_name = ft_strjoinfree(shot->file_name,
	ft_itoa(shot->timecomp->tm_mon + 1), 3)))
		ft_exit(s, "Malloc failed");
	if (!(shot->file_name = ft_strjoinfree(shot->file_name, ":", 1)))
		ft_exit(s, "Malloc failed");
	name_screen(s, shot);
}

void		screen_init(t_cub3d *s, t_screen *shot)
{
	time_init(s, shot);
	shot->start = 54;
	shot->hold = 54 + 4 * s->res_x * s->res_y;
	shot->size = 40;
	shot->raw_size = 4 * s->res_x * s->res_y;
	shot->res = 2835;
	shot->planes = 1;
	shot->bpp = 32;
	shot->type = 0x4d42;
}

void		screen_header(t_cub3d *s, t_screen *shot)
{
	screen_init(s, shot);
	if (!(shot->file = ft_calloc((s->res_x * s->res_y), sizeof(int))))
		ft_exit(s, "Malloc failed");
	if (!(shot->header = (unsigned char*)malloc(shot->start)))
		ft_exit(s, "Malloc failed");
	ft_bzero(shot->header, shot->start);
	ft_bzero(shot->file, s->res_x * s->res_y);
	ft_memcpy(&shot->header[0], &shot->type, 2);
	ft_memcpy(&shot->header[2], &shot->hold, 4);
	ft_memcpy(&shot->header[10], &shot->start, 4);
	ft_memcpy(&shot->header[14], &shot->size, 4);
	ft_memcpy(&shot->header[18], &s->res_x, 4);
	ft_memcpy(&shot->header[22], &s->res_y, 4);
	ft_memcpy(&shot->header[26], &shot->planes, 2);
	ft_memcpy(&shot->header[28], &shot->bpp, 2);
	ft_memcpy(&shot->header[34], &shot->raw_size, 4);
	ft_memcpy(&shot->header[38], &shot->res, 4);
	ft_memcpy(&shot->header[42], &shot->res, 4);
}

void		screen(t_cub3d *s)
{
	t_screen	shot;
	int			i;
	int			fd;
	int			k;
	int			j;

	screen_header(s, &shot);
	j = 0;
	if ((fd = open(shot.file_name, O_RDWR | O_APPEND | O_CREAT, 0644)) < 0)
		ft_exit(s, "Unable to create screenshot");
	while (j < s->res_y)
	{
		i = 0;
		while (i < s->res_x)
		{
			k = (s->res_y - 1 - j) * s->res_x + i;
			shot.file[k] = s->col->tab[i + (j * s->res_x)];
			i++;
		}
		j++;
	}
	write(fd, shot.header, shot.start);
	write(fd, shot.file, shot.raw_size);
	free_shot(&shot);
	close(fd);
}
