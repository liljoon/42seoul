/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_app.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:23:20 by isunwoo           #+#    #+#             */
/*   Updated: 2023/05/20 17:25:57 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void player_move(int keycode, t_cub3d_info *app)
{
	if (keycode == 0)
		app->player_x -= 1;
	else if (keycode == 1)
		app->player_y += 1;
	else if (keycode == 2)
		app->player_x += 1;
	else if (keycode == 13)
		app->player_y -= 1;
	printf("pushed\n");

	raycasting(app);
}

void player_rotate(int keycode, t_cub3d_info *app)
{
	double rotSpeed = 0.5;

	if (keycode == 123)
	{

	}
	else if (keycode == 124)
	{
		double oldDirX = app->dirX;
		app->dirX = app->dirX * cos(rotSpeed) - app->dirY * sin(rotSpeed);
		app->dirY = oldDirX * sin(rotSpeed) + app->dirY * cos(rotSpeed);
		double oldPlaneX = app->planeX;
		app->planeX = app->planeX * cos(rotSpeed) - app->planeY * sin(rotSpeed);
		app->planeY = oldPlaneX * sin(rotSpeed) + app->planeY * cos(rotSpeed);
		printf("right pushed\n");
		//mlx_clear_window(app->pmlx, app->pmlx_win);
		//raycasting(app);
	}
}

int key_hook(int keycode, t_cub3d_info *app)
{
	if (keycode == 53)
		exit(0);
	// if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
	// 	player_move(keycode, app);
	if (keycode == 123 || keycode == 124)
		player_rotate(keycode, app);
	return (0);
}

int exit_func(void)
{
	exit(0);
}

void init_info(t_cub3d_info *app)
{
	// 테스트용 하드코딩
	app->screen_width = 720;
	app->screen_heigth = 480;
	//app->fov = 60 * (M_PI / 180);
	app->planeX = 0;
	app->planeY = 0.66;
	app->player_x = 2;
	app->player_y = 2;
	//app->player_angle = 90 * (M_PI / 180);  // 0도 오른쪽 기준
	app->dirX = 1;
	app->dirY = 0;

	//app->precision = 64;
	int map[10][10] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 1, 1, 0, 1, 0, 0, 1},
		{1, 0, 0, 1, 0, 0, 1, 0, 0, 1},
		{1, 0, 0, 1, 0, 0, 1, 0, 0, 1},
		{1, 0, 0, 1, 0, 1, 1, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
			app->map[i][j] = map[i][j];
	}
	// 하드코딩 끝

	//app->increment_angle = app->fov / app->screen_width;
	app->pmlx = mlx_init();
	app->pmlx_win = mlx_new_window(app->pmlx, app->screen_width, app->screen_heigth, "cub3D");
}

int init_app(t_cub3d_info *app)
{
	init_info(app);
	mlx_loop_hook(app->pmlx, raycasting, &app);
	mlx_key_hook(app->pmlx_win, key_hook, app->pmlx);
	mlx_hook(app->pmlx_win, 17, 0, exit_func, (void *)0);
	//raycasting(app);
	return (0);
}
