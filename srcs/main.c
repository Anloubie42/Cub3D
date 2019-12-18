/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:57:54 by anloubie          #+#    #+#             */
/*   Updated: 2019/12/16 15:00:29 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubddd.h"

void	ft_print_se(t_cub3d *s)
{
	int	i;

	i = 0;
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
	i = 0;
	printf("s->obj = %d\n", s->obj);
	while (i < s->obj)
	{
		printf("x = %f\n", s->sprite[i].co.x);
		printf("y = %f\n", s->sprite[i].co.y);
		i++;
	}
	printf("start x = %f\nstart y = %f\n", s->pos.x, s->pos.y);
}

int		move(t_cub3d *s)
{
	if (s->key->up == 1)
		move_foreward(s);
	if (s->key->down == 1)
		move_backwards(s);
	if (s->key->rot_left == 1)
		rot_left(s, RSPEED);
	if (s->key->rot_right == 1)
		rot_right(s, RSPEED);
	if (s->key->left == 1)
		move_left(s);
	if (s->key->right == 1)
		move_right(s);
	return (1);
}

int		ft_key_release(int key, t_cub3d *s)
{
	if (key == 126 || key == 6)
		s->key->up = 0;
	if (key == 125 || key == 1)
		s->key->down = 0;
	if (key == 123)
		s->key->rot_left = 0;
	if (key == 124)
		s->key->rot_right = 0;
	if (key == 12)
		s->key->left = 0;
	if (key == 2)
		s->key->right = 0;
	return (1);
}

int		ft_key_press(int key, t_cub3d *s)
{
	if (key == 53)
		ft_exit(s, NULL);
	if (key == 126 || key == 6)
		s->key->up = 1;
	if (key == 125 || key == 1)
		s->key->down = 1;
	if (key == 123)
		s->key->rot_left = 1;
	if (key == 124)
		s->key->rot_right = 1;
	if (key == 12)
		s->key->left = 1;
	if (key == 2)
		s->key->right = 1;
	return (1);
}

int		main(int ac, char **av)
{
	t_cub3d		s;

	if (ac == 1)
		ft_exit(&s, "Use : ./Cub3D file.cub");
	if (ac > 3)
		ft_exit(&s, "Too many arguments");
	ft_bzero(&s, sizeof(t_cub3d));
	ft_init(&s);
	ft_parse(&s, av[1]);
	if (!(s.data->mlx_ptr = mlx_init()))
		return (0);
	if (!(s.data->mlx_win = mlx_new_window(s.data->mlx_ptr, s.res_x, s.res_y,
	"Cub3D")))
		return (0);
	ft_create_img(&s);
	get_texture(&s);
	ft_pos_calc(&s);
	ft_print_se(&s);
	mlx_hook(s.data->mlx_win, 2, 0, ft_key_press, &s);
	mlx_hook(s.data->mlx_win, 3, 0, ft_key_release, &s);
	mlx_hook(s.data->mlx_win, 17, 0, ft_exit, &s);
	mlx_loop_hook(s.data->mlx_ptr, move, &s);
	mlx_loop(s.data->mlx_ptr);
	return (1);
}
