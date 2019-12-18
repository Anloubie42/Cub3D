/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:09:17 by anloubie          #+#    #+#             */
/*   Updated: 2019/12/16 12:59:58 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubddd.h"

int		ft_exit(t_cub3d *s, char *str)
{
	int		i;

	i = -1;
	if (s->data)
		free(s->data);
	if (s->calc)
		free(s->calc);
	if (s->key)
		free(s->key);
	if (s->col_f)
		free(s->col_f);
	if (s->col_c)
		free(s->col_c);
	if (s->path_e)
		free(s->path_e);
	if (s->path_w)
		free(s->path_w);
	if (s->path_s)
		free(s->path_s);
	if (s->path_n)
		free(s->path_n);
	if (s->path_sprite)
		free(s->path_sprite);
	if (s->sprite->zbuffer)
		free(s->sprite->zbuffer);
	if (s->sprite)
		free(s->sprite);
	if (s->sp)
		free(s->sp);
	ft_putstr_fd("\033[31m", 1);
	if (str != NULL)
	{
		ft_putstr_fd("<===============================================>\n", 1);
		ft_putstr_fd("#                    Error                      #\n", 1);
		ft_putstr_fd("#		", 1);
		ft_putstr_fd(str, 1);
		while (++i < 47 - (int)ft_strlen(str) - 15)
			ft_putchar_fd(' ', 1);
		ft_putstr_fd("#\n", 1);
		ft_putstr_fd("<===============================================>\n", 1);
	}
	else
		ft_putstr_fd("Program Ended\n", 1);
	ft_putstr_fd("\033[0m", 1);
	exit(0);
	return (0);
}
