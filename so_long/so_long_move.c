/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 11:19:58 by isunwoo           #+#    #+#             */
/*   Updated: 2022/11/07 14:55:37 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_so_long *app, int dy, int dx)
{
	if (app->map.map_data \
	[app->player.y / 128 + dy][app->player.x / 128 + dx] == '1')
		return ;
	if (app->map.map_data
		[app->player.y / 128 + dy][app->player.x / 128 + dx] == 'C')
	{
		draw_grass(app->player.x + 128 * dx, app->player.y + 128 * dy, app);
		app->map.col_cnt--;
		app->map.map_data \
			[app->player.y / 128 + dy][app->player.x / 128 + dx] = 0;
	}
	else if (app->map.map_data \
		[app->player.y / 128 + dy][app->player.x / 128 + dx] == 'E')
	{
		if (app->map.col_cnt == 0)
		{
			printf("WIN!!\n");
			exit(0);
		}
	}
	app->player.x += 128 * dx;
	app->player.y += 128 * dy;
}

void	player_move(int keycode, t_so_long *app)
{
	int	temp_x;
	int	temp_y;

	temp_x = app->player.x;
	temp_y = app->player.y;
	if (keycode == 0)
		move(app, 0, -1);
	else if (keycode == 1)
		move(app, 1, 0);
	else if (keycode == 2)
		move(app, 0, 1);
	else if (keycode == 13)
		move(app, -1, 0);
	draw_grass(temp_x, temp_y, app);
	if (app->map.map_data[temp_y / 128][temp_x / 128] == 'E')
		draw_exit(temp_x, temp_y, app);
	draw_player(app);
}
