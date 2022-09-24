/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:08:13 by isunwoo           #+#    #+#             */
/*   Updated: 2022/09/24 15:06:24 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*mlx_ptr;
void	*win_ptr;
int x=100,y=100;

int	key_hook(int keycode, t_so_long *app)
{
	int	temp_x = app->player.x;
	int	temp_y = app->player.y;

	if (keycode == 0)
		app->player.x -= 128;
	else if (keycode == 1)
		app->player.y += 128;
	else if (keycode == 2)
		app->player.x += 128;
	else if (keycode == 13)
		app->player.y -= 128;
	mlx_put_image_to_window(app->mlx_ptr, app->win_ptr, app->map.grass_ptr, temp_x, temp_y);
	mlx_put_image_to_window( \
		app->mlx_ptr, app->win_ptr, app->player.image_ptr, app->player.x, app->player.y);
	return 0;
}

int mouse_hook(int button, int x,int y, void *param)
{
	write(1,"X",1);

	return 0;
}

int	main(void)
{
	t_so_long	app;
	//임시 크기 지정
	app.width = 13 * 128;
	app.height = 5 * 128;
	init_so_long(&app);
	mlx_key_hook(app.win_ptr,key_hook, &app);
	mlx_loop(app.mlx_ptr);
}
