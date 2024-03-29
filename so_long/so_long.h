/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 14:03:06 by isunwoo           #+#    #+#             */
/*   Updated: 2022/11/11 20:57:01 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include "./get_next_line/get_next_line.h"

typedef struct s_cnt_map
{
	int	p;
	int	c;
	int	e;
}	t_cnt_map;

typedef struct s_player
{
	void	*image_ptr;
	int		x;
	int		y;
	int		size;
	int		move_cnt;
}	t_player;

typedef struct s_map
{
	void	*grass_ptr;
	void	*wall_ptr;
	void	*coll_ptr;
	void	*exit_ptr;
	int		size;
	char	**map_data;
	char	*map_path;
	int		col_cnt;
}	t_map;

typedef struct s_so_long
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			width;
	int			height;
	t_player	player;
	t_map		map;
	char		**visited;
}	t_so_long;

void	init_so_long(t_so_long *app, char *map_path);
void	draw_player(t_so_long *app);
void	draw_grass(int x, int y, t_so_long *app);
void	draw_wall(int x, int y, t_so_long *app);
void	draw_exit(int x, int y, t_so_long *app);
void	draw_collectible(int x, int y, t_so_long *app);
void	player_move(int keycode, t_so_long *app);
void	check_map_valid(t_so_long *app);
void	map_check_height(t_so_long *app);
void	check_count(t_so_long *app);

void	map_read(t_so_long *app);
void	map_check(t_so_long *app);

void	check_map_valid(t_so_long *app);
void	exit_with_error(char *message);
#endif
