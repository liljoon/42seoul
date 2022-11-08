/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 11:19:58 by isunwoo           #+#    #+#             */
/*   Updated: 2022/11/08 21:27:33 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_recursive(int n, int fd)
{
	char	print_char;

	if (n <= 0)
		return ;
	else
	{
		print_recursive(n / 10, fd);
		print_char = n % 10 + '0';
		write(fd, &print_char, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int		dividend;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		dividend = -1 * n;
		write(fd, "-", 1);
	}
	else if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	else
		dividend = n;
	print_recursive(dividend, fd);
}

void	print_move_add_cnt(t_so_long *app)
{
	app->player.move_cnt++;
	write(1, "number of movements : ", 22);
	ft_putnbr_fd(app->player.move_cnt, 1);
	write(1, "\n", 1);
	return ;
}

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
			print_move_add_cnt(app);
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
	if (temp_x != app->player.x || temp_y != app->player.y)
		print_move_add_cnt(app);
}
