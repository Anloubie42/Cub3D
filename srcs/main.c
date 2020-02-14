/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:57:54 by anloubie          #+#    #+#             */
/*   Updated: 2020/02/06 13:37:26 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubddd.h"

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
	if (key == 126 || key == 13)
		s->key->up = 0;
	if (key == 125 || key == 1)
		s->key->down = 0;
	if (key == 123)
		s->key->rot_left = 0;
	if (key == 124)
		s->key->rot_right = 0;
	if (key == 0)
		s->key->left = 0;
	if (key == 2)
		s->key->right = 0;
	return (1);
}

int		ft_key_press(int key, t_cub3d *s)
{
	if (key == 53)
		ft_exit(s, NULL);
	if (key == 126 || key == 13)
		s->key->up = 1;
	if (key == 125 || key == 1)
		s->key->down = 1;
	if (key == 123)
		s->key->rot_left = 1;
	if (key == 124)
		s->key->rot_right = 1;
	if (key == 0)
		s->key->left = 1;
	if (key == 2)
		s->key->right = 1;
	if (key == 120)
		screen(s);
	return (1);
}

void	init_mlx(t_cub3d *s)
{
	mlx_hook(s->data->mlx_win, 2, 0, ft_key_press, s);
	mlx_hook(s->data->mlx_win, 3, 0, ft_key_release, s);
	mlx_hook(s->data->mlx_win, 17, 0, ft_exit, s);
	mlx_loop_hook(s->data->mlx_ptr, move, s);
	mlx_loop(s->data->mlx_ptr);
}

int		main(int ac, char **av)
{
	t_cub3d		s;

	if (ac == 1)
		ft_exit(&s, "Use : ./Cub3D file.cub (-save)");
	if (ac > 3)
		ft_exit(&s, "Too many arguments");
	ft_bzero(&s, sizeof(t_cub3d));
	ft_bzero(&s.data, sizeof(t_data));
	ft_init(&s);
	if (ac == 3)
		s.screen = (ft_strncmp("--save", av[2], 6)) ? 2 : 1;
	ft_parse(&s, av[1]);
	if (!(s.data->mlx_ptr = mlx_init()))
		ft_exit(&s, "mlx failed");
	if (!(s.data->mlx_win = mlx_new_window(s.data->mlx_ptr, s.res_x,
		s.res_y, "Cub3D")))
		ft_exit(&s, "mlx failed");
	ft_create_img(&s);
	get_texture(&s);
	ft_pos_calc(&s);
	init_mlx(&s);
	return (1);
}
