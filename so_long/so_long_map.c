/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:25:16 by isunwoo           #+#    #+#             */
/*   Updated: 2022/11/08 20:52:00 by isunwoo          ###   ########.fr       */
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
	{
		perror("open");
		exit(1);
	}
	while (i < app->height)
	{
		app->map.map_data[i] = get_next_line(fd);
		if (app->map.map_data[i] == NULL)
		{
			perror("get_next_line");
			exit(1);
		}
		i++;
	}
	close(fd);
}
