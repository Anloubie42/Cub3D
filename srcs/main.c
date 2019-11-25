/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:57:54 by anloubie          #+#    #+#             */
/*   Updated: 2019/11/25 17:25:03 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void		ft_print_se(t_Cub3D *s)
{
	int	i = 0;
	printf("res_x = %d\n", s->res_x);
	printf("res_y = %d\n", s->res_y);
	printf("path_n = %s\n", s->path_n);
	printf("path_s = %s\n", s->path_s);
	printf("path_e = %s\n", s->path_e);
	printf("path_w = %s\n", s->path_w);
	printf("path_sprite = %s\n", s->path_sprite);
	while (i < 3)
	{
		printf("col_f[%d] = %d\n", i, s->col_f[i]);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		printf("col_c[%d] = %d\n", i, s->col_c[i]);
		i++;
	}
	i = 0;
	while (s->map[i])
		printf("%s\n", s->map[i++]);
}

int		ft_key(int key, t_Cub3D *s)
{
	printf("key = %d\n", key);
	if (key == 53)
		ft_exit(s);
	return (1);
}

int		main(int ac, char **av)
{
	t_Cub3D		s;

	(void)ac;
	ft_bzero(&s, sizeof(t_Cub3D));
	ft_init(&s);
	ft_parse(&s, av[1]);
	ft_print_se(&s);
	if (!(s.data->mlx_ptr = mlx_init()))
		return (EXIT_FAILURE);
	if (!(s.data->mlx_win = mlx_new_window(s.data->mlx_ptr, s.res_x, s.res_y,
	"Cub3D")))
		return (EXIT_FAILURE);
	ft_create_img(&s);
	ft_pos_calc(&s);
	mlx_key_hook(s.data->mlx_win, ft_key, &s);
	mlx_hook(s.data->mlx_win, 17, 0, ft_exit, &s);
	mlx_loop(s.data->mlx_ptr);
	return (EXIT_SUCCESS);
}
