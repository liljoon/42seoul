/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 11:19:58 by isunwoo           #+#    #+#             */
/*   Updated: 2022/09/25 12:50:01 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move_left(t_so_long *app)
{
	if (app->map.map_data[app->player.y / 128][app->player.x / 128 - 1] != '1')
		app->player.x -= 128;
}

void move_right(t_so_long *app)
{
	if (app->map.map_data[app->player.y / 128][app->player.x / 128 + 1] != '1')
		app->player.x += 128;
}

void move_up(t_so_long *app)
{
	if (app->map.map_data[app->player.y / 128 - 1][app->player.x / 128] != '1')
		app->player.y -= 128;
}

void move_down(t_so_long *app)
{
	if (app->map.map_data[app->player.y / 128 + 1][app->player.x / 128] != '1')
		app->player.y += 128;
}

void player_move(int keycode, t_so_long *app)
{
	int	temp_x = app->player.x;
	int	temp_y = app->player.y;

	if (keycode == 0)
		move_left(app);
	else if (keycode == 1)
		move_down(app);
	else if (keycode == 2)
		move_right(app);
	else if (keycode == 13)
		move_up(app);
	draw_grass(temp_x, temp_y, app);
	draw_player(app);
}
