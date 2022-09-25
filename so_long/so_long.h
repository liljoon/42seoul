/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 14:03:06 by isunwoo           #+#    #+#             */
/*   Updated: 2022/09/25 12:48:54 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
#include <fcntl.h>

typedef struct s_player
{
	void	*image_ptr;
	int		x;
	int		y;
	int		size;
}	t_player;

typedef struct s_map
{
	void	*grass_ptr;
	void	*wall_ptr;
	int		size;
	char	map_data[5][13];
}	t_map;

typedef struct s_so_long
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			width;
	int			height;
	t_player	player;
	t_map		map;
}	t_so_long;

void	init_so_long(t_so_long *app);
void	draw_player(t_so_long *app);
void	draw_grass(int x, int y, t_so_long *app);
void	draw_wall(int x, int y, t_so_long *app);
void	player_move(int keycode, t_so_long *app);

#endif
