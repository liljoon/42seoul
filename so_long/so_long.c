/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 14:08:41 by isunwoo           #+#    #+#             */
/*   Updated: 2022/09/24 18:32:33 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_player(t_so_long *app)
{
	app->player.size = 128;
	app->player.image_ptr = mlx_xpm_file_to_image(\
		app->mlx_ptr, app->player.image_path, &(app->player.size), &(app->player.size));
	// 임시 위치 중앙.
	app->player.x = 128 * 6;
	app->player.y = 128 * 2;
	mlx_put_image_to_window(\
		app->mlx_ptr, app->win_ptr, app->player.image_ptr, app->player.x, app->player.y);

}

void	draw_player(t_so_long *app)
{
	mlx_put_image_to_window( \
		app->mlx_ptr, app->win_ptr, app->player.image_ptr, app->player.x, app->player.y);
}
void	draw_grass(int x, int y, t_so_long *app)
{
	mlx_put_image_to_window(app->mlx_ptr, app->win_ptr, app->map.grass_ptr, x, y);
}
void	draw_wall(int x, int y, t_so_long *app)
{

}

void map_init(t_so_long *app)
{
	app->map.size = 128;
	app->map.grass_ptr = mlx_xpm_file_to_image(\
		app->mlx_ptr,app->map.grass_path,&(app->map.size),&(app->map.size));
	char temp[5][14] = {
		"1111111111111",
		"10010000000C1",
		"1000011111001",
		"1P0011E000001",
		"1111111111111"
	};
	app->map.map_data = temp;
	for(int i=0;i<13;i++)
	{
		for(int j=0;j<5;j++)
		{
			mlx_put_image_to_window(\
				app->mlx_ptr, app->win_ptr, app->map.grass_ptr, 128  * i, 128  *  j);
		}
	}
}

void	init_so_long(t_so_long *app)
{
	app->mlx_ptr = mlx_init();
	app->win_ptr = mlx_new_window(\
		app->mlx_ptr, app->width, app->height, "so_long");
	app->player.image_path = "./player.xpm";
	app->map.grass_path = "./Grass.xpm";
	map_init(app);
	init_player(app);

}
