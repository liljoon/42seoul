/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:39:20 by isunwoo           #+#    #+#             */
/*   Updated: 2023/05/18 22:42:37 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <mlx.h>
# include <math.h>

typedef struct	s_cub3d_info
{
	void	*pmlx;
	void	*pmlx_win;
	int		screen_width;
	int		screen_heigth;
	double	fov;
	double	player_x;
	double	player_y;
	double	player_angle;
	double	increment_angle;
	int		precision;
	int		map[10][10]; // 하드코딩
} t_cub3d_info;

int	init_app(t_cub3d_info *app);
int raycasting(t_cub3d_info *app);

#endif
