/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 14:08:41 by isunwoo           #+#    #+#             */
/*   Updated: 2022/09/25 12:05:38 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_player(t_so_long *app)
{
	app->player.size = 128;
	draw_player(app);
}

void map_read(t_so_long *app)
{
	int fd;

	fd = open("./map.ber", O_RDONLY); // argv로 변경 필요
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<14;j++)
		{

			char c;
			read(fd, &c, 1);
			if(j==13)
				continue;
			app->map.map_data[i][j] = c;
		}
	}
}

void map_init(t_so_long *app)
{
	map_read(app);
	app->map.size = 128;
	for(int i=0;i<13;i++)
	{
		for(int j=0;j<5;j++)
		{
			draw_grass(i * 128, j * 128, app);
			if(app->map.map_data[j][i] == '1')
				draw_wall(i * 128, j * 128, app);
			else if (app->map.map_data[j][i] == 'P')
			{
				app->player.x = i * 128;
				app->player.y = j * 128;
			}

		}
	}
}



void init_file_image_ptr(t_so_long *app)
{
	app->map.grass_ptr = mlx_xpm_file_to_image(\
		app->mlx_ptr,"./Grass.xpm", &(app->map.size), &(app->map.size));
	app->player.image_ptr = mlx_xpm_file_to_image(\
		app->mlx_ptr, "./player.xpm", &(app->player.size), &(app->player.size));
	app->map.wall_ptr = mlx_xpm_file_to_image(\
		app->mlx_ptr,"./wall.xpm", &(app->map.size), &(app->map.size));
}

void	init_so_long(t_so_long *app)
{
	app->mlx_ptr = mlx_init();
	app->win_ptr = mlx_new_window(\
		app->mlx_ptr, app->width, app->height, "so_long");
	init_file_image_ptr(app);
	map_init(app);
	init_player(app);

}
