/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:38:53 by isunwoo           #+#    #+#             */
/*   Updated: 2023/05/18 22:39:11 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_line(t_cub3d_info *app, int screen_x, double wall_height)
{
	int	y;

	y = app->screen_heigth / 2 - wall_height / 2;
	while (y < app->screen_heigth / 2 + wall_height / 2)
	{
		mlx_pixel_put(app->pmlx, app->pmlx_win, screen_x, y, 0xFF0000);
		y++;
	}
}

void ray_check(t_cub3d_info *app, int ray_count, double ray_angle)
{
	double	y;
	double	x;
	double	dy;
	double	dx;

	dy = sin(ray_angle) / app->precision;
	dx = cos(ray_angle) / app->precision;
	y = app->player_y;
	x = app->player_x;
	while (app->map[(int)y][(int)x] == 0)
	{
		y += dy;
		x += dx;
	}
	double dist = sqrt(pow(app->player_y - y, 2) + pow(app->player_x - x, 2));
	double wall_height = floor((app->screen_heigth / 2) / dist);
	draw_line(app, ray_count, wall_height);
}

int raycasting(t_cub3d_info *app)
{
	double	ray_angle;
	int		ray_count;

	ray_angle = app->player_angle - (app->fov) / 2;
	ray_count = 0;
	while (ray_count < app->screen_width)
	{
		ray_check(app, ray_count, ray_angle);
		ray_count++;
		ray_angle += app->increment_angle;
	}

	return (0);
}
