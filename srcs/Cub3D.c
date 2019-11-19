/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:57:54 by anloubie          #+#    #+#             */
/*   Updated: 2019/11/19 16:41:59 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

int		ft_key(int key, t_data *data)
{
	printf("key = %d\n", key);
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		exit(0);
	}
	return (1);
}

int		main(void)
{
	t_data		data;

	if (!(data.mlx_ptr = mlx_init()))
		return (EXIT_FAILURE);
	if ((data.mlx_win = mlx_new_window(data.mlx_ptr, 640, 480, "Cub3D")) == NULL)
		return (EXIT_FAILURE);
	mlx_hook(data.mlx_win, 2, 0, ft_key, &data);
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}
