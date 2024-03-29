/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:25:16 by isunwoo           #+#    #+#             */
/*   Updated: 2022/11/11 20:23:56 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_read(t_so_long *app)
{
	int	fd;
	int	i;

	i = 0;
	map_check_height(app);
	fd = open(app->map.map_path, O_RDONLY);
	if (fd == -1)
		exit_with_error("open error");
	while (i < app->height)
	{
		app->map.map_data[i] = get_next_line(fd);
		if (app->map.map_data[i] == NULL)
			exit_with_error("gnl error");
		i++;
	}
	close(fd);
}
