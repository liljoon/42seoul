/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 14:08:41 by isunwoo           #+#    #+#             */
/*   Updated: 2022/11/04 21:13:54 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_player(t_so_long *app)
{
	app->player.size = 128;
	draw_player(app);
}

void	map_init(t_so_long *app, char *map_path)
{
	app->map.map_path = map_path;
	map_read(app);
	map_check(app);
	app->map.size = 128;
}

void map_draw_init(t_so_long *app)
{
	int	i;
	int	j;
	i = 0;
	while (i < app->width)
	{
		j = 0;
		while (j < app->height)
		{
			draw_grass(i * 128, j * 128, app);
			if(app->map.map_data[j][i] == '1')
				draw_wall(i * 128, j * 128, app);
			else if (app->map.map_data[j][i] == 'P')
			{
				app->player.x = i * 128;
				app->player.y = j * 128;
			}
			else if (app->map.map_data[j][i] == 'C')
				draw_collectible(i * 128, j * 128, app);
			else if (app->map.map_data[j][i] == 'E')
				draw_exit(i * 128, j * 128, app);
			j++;
		}
		i++;
	}
}

void	init_file_image_ptr(t_so_long *app)
{
	app->map.grass_ptr = mlx_xpm_file_to_image(\
		app->mlx_ptr,"./img/Grass.xpm", &(app->map.size), &(app->map.size));
	app->player.image_ptr = mlx_xpm_file_to_image(\
		app->mlx_ptr, "./img/player.xpm", &(app->player.size), &(app->player.size));
	app->map.wall_ptr = mlx_xpm_file_to_image(\
		app->mlx_ptr,"./img/wall.xpm", &(app->map.size), &(app->map.size));
	app->map.coll_ptr = mlx_xpm_file_to_image(\
		app->mlx_ptr,"./img/ChickenLeg.xpm", &(app->map.size), &(app->map.size));
	app->map.exit_ptr = mlx_xpm_file_to_image(\
		app->mlx_ptr,"./img/exit.xpm", &(app->map.size), &(app->map.size));
}

void	init_so_long(t_so_long *app, char *map_path)
{
	app->mlx_ptr = mlx_init();
	map_init(app, map_path);
	app->win_ptr = mlx_new_window(\
		app->mlx_ptr, app->width * app->map.size, app->height * app->map.size, "so_long");
	init_file_image_ptr(app);
	map_draw_init(app);
	init_player(app);
}
