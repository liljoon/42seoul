/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:43:49 by isunwoo           #+#    #+#             */
/*   Updated: 2023/05/18 17:40:46 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int key_hook(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int exit_func(void)
{
	exit(0);
}

int main(void)
{
	void *mlx;
	void *mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_key_hook(mlx_win, key_hook, mlx);
	mlx_hook(mlx_win, 17, 0, exit_func, (void *)0);
	mlx_loop(mlx);
}
