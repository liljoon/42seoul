/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:08:13 by isunwoo           #+#    #+#             */
/*   Updated: 2022/11/13 16:58:09 by isunwoo          ###   ########.fr       */
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

int	exit_func(void)
{
	exit(0);
}

void	check_argc(int argc)
{
	if (argc != 2)
		exit_with_error("wrong number of arguments");
}

void	check_extension(char *path)
{
	int	i;

	if (!path)
		exit_with_error("file name");
	i = 0;
	while (path[i] != '\0')
		i++;
	if (i < 4)
		exit_with_error("file name");
	if (path[i - 4] != '.' || path[i - 3] != 'b' \
		|| path[i - 2] != 'e' || path[i - 1] != 'r')
		exit_with_error("file name");
}

int	main(int argc, char *argv[])
{
	t_so_long	app;

	check_argc(argc);
	check_extension(argv[1]);
	init_so_long(&app, argv[1]);
	mlx_key_hook(app.win_ptr, key_hook, &app);
	mlx_hook(app.win_ptr, 17, 0, exit_func, (void *)0);
	mlx_loop(app.mlx_ptr);
}
