/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:08:13 by isunwoo           #+#    #+#             */
/*   Updated: 2022/11/07 14:47:24 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_so_long *app)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
		player_move(keycode, app);
	return (0);
}

int	mouse_hook(int button, int x,int y, void *param)
{
	return (0);
}

int	exit_func(void)
{
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_so_long	app;

	init_so_long(&app, argv[1]);
	mlx_key_hook(app.win_ptr, key_hook, &app);
	mlx_mouse_hook(app.win_ptr, mouse_hook, (void *)0);
	mlx_hook(app.win_ptr, 17, 0, exit_func, (void *)0);
	mlx_loop(app.mlx_ptr);
}
