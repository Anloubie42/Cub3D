/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:09:17 by anloubie          #+#    #+#             */
/*   Updated: 2020/01/07 11:02:36 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubddd.h"

int		ft_exit(t_cub3d *s, char *str)
{
	int		i;

	i = -1;
	(void)s;
	ft_putstr_fd("\033[31m", 1);
	if (str != NULL && ft_strncmp(str, "closeNotification:", 18))
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
