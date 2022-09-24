/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:08:13 by isunwoo           #+#    #+#             */
/*   Updated: 2022/09/24 18:52:06 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_so_long *app)
{
	int	temp_x = app->player.x;
	int	temp_y = app->player.y;

	if (keycode == 53)
		exit(0);
	if (keycode == 0)
		app->player.x -= 128;
	else if (keycode == 1)
		app->player.y += 128;
	else if (keycode == 2)
		app->player.x += 128;
	else if (keycode == 13)
		app->player.y -= 128;
	draw_grass(temp_x, temp_y, app);
	draw_player(app);
	return 0;
}

int mouse_hook(int button, int x,int y, void *param)
{
	printf("%d %d\n",x,y);

	return 0;
}

int exit_func()
{
	exit(0);
}

int	main(void)
{
	t_so_long	app;
	//임시 크기 지정
	app.width = 13 * 128;
	app.height = 5 * 128;
	init_so_long(&app);
	mlx_key_hook(app.win_ptr,key_hook, &app);
	mlx_mouse_hook(app.win_ptr,mouse_hook,(void*)0);
	mlx_hook(app.win_ptr, 17, 0, exit_func, (void*)0);
	mlx_loop(app.mlx_ptr);
}
