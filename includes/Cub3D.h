/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:55:29 by anloubie          #+#    #+#             */
/*   Updated: 2019/11/26 16:12:27 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <mlx.h>
# include "libft.h"
# include <fcntl.h>
# include <math.h>

typedef struct		s_vertex_d
{
	double			x;
	double			y;
}					t_vertex_d;

typedef struct		s_vertex
{
	int				x;
	int				y;
}					t_vertex;

typedef struct		s_data
{	
	void			*mlx_ptr;
	void			*mlx_win;
	void			*img_ptr;
}					t_data;

typedef struct		s_color
{
	int				bpp;
	int				size;
	int				endian;
	int				*tab;
	int				red;
	int				green;
	int				blue;
	int				color;
}					t_color;

typedef struct		s_calc
{
	t_vertex		map;
	t_vertex		step;
	t_vertex_d		dir;
	t_vertex_d		ray_dir;
	t_vertex_d		dist_wall;
	t_vertex_d		delta_dist;
	t_vertex_d		plane;
	double			perp_wall_dist;
	double			camera_x;
	int				hit;
	int				wall;
	int				draw_start;
	int				draw_end;
	int				line_height;
	int				x;
}					t_calc;

typedef struct		s_Cub3D
{
	int				res_x;
	int				res_y;
	char			*path_n;
	char			*path_s;
	char			*path_e;
	char			*path_w;
	char			*path_sprite;
	char			**map;
	int				*col_f;
	int				*col_c;
	int				map_h;
	int				map_w;
	char			dir;
	t_vertex_d		pos;
	t_data			*data;
	t_calc			*calc;
	t_color			*col;
}					t_Cub3D;

typedef struct		s_map
{
	char			*line;
	struct s_map	*next;
}					t_map;

void				ft_parse(t_Cub3D *s, char *path);
void				ft_resset(t_Cub3D *s, char *str);
int					ft_exit(t_Cub3D *s);
int					ft_buflen(char **buf);
void				ft_del(char **tab);
void				ft_map_create(t_Cub3D *s, char *str, t_map **map);
t_map				*ft_lstnewmap(char *str);
void				ft_lstaddmap(t_map **alst, t_map *new);
void				ft_map_parse(t_Cub3D *s, t_map *map);
int					ft_mapsize(t_map *lst);
void				ft_init(t_Cub3D *s);
void				ft_pos_calc(t_Cub3D *s);
void				ft_proj_cam(t_Cub3D *s);
void				ft_create_img(t_Cub3D *s);
int					ft_get_color(int red, int green, int blue);
void				move_foreward(t_Cub3D *s);
void				ft_raycasting(t_Cub3D *s);
void				move_backwards(t_Cub3D *s);
void				rot_right(t_Cub3D *s);
void				rot_left(t_Cub3D *s);

#endif
