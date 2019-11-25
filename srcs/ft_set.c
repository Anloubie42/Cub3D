/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:21:58 by anloubie          #+#    #+#             */
/*   Updated: 2019/11/25 14:35:30 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void	ft_del(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int		ft_buflen(char **buf)
{
	int	i;

	if (!buf)
		return (0);
	i = 0;
	while (buf[i] != NULL)
		i++;
	return (i);
}

void	ft_resset(t_Cub3D *s, char *str)
{
	char	**dest;
	int		len;
	int		i;

	i = 0;
	dest = ft_split(str, ' ');
	len = ft_buflen(dest);
	if (len == 3)
	{
		s->res_x = ft_atoi(dest[1]);
		s->res_y = ft_atoi(dest[2]);
	}
	ft_del(dest);
	if (s->res_x <= 0 || s->res_y <= 0 || len != 3)
		ft_exit(s);
}
