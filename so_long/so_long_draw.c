/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 10:35:39 by isunwoo           #+#    #+#             */
/*   Updated: 2022/09/25 10:54:51 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	mlx_put_image_to_window(app->mlx_ptr, app->win_ptr, app->map.wall_ptr, x, y);

}
