/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:51:46 by isunwoo           #+#    #+#             */
/*   Updated: 2022/11/13 16:46:50 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_check_height(t_so_long *app)
{
	int		fd;
	char	ch;
	int		count;

	count = 0;
	fd = open(app->map.map_path, O_RDONLY);
	if (fd == -1)
		exit_with_error("open");
	while (read(fd, &ch, 1))
	{
		if (ch == '\n')
			count++;
	}
	app->height = count;
	app->map.map_data = malloc(sizeof(*(app->map.map_data)) * count);
	if (app->map.map_data == NULL)
		exit_with_error("malloc");
	close(fd);
}

int	line_check(char *line)
{
	int	cnt;

	cnt = 0;
	while (line)
	{
		if (*line == '\n')
			break ;
		else if (*line != '1' && *line != '0' && \
			*line != 'P' && *line != 'E' && *line != 'C')
			exit_with_error("map error : undefined character");
		cnt++;
		line++;
	}
	return (cnt);
}

void	check_edge(t_so_long *app)
{
	int	i;

	i = 0;
	while (i < app->width)
	{
		if (app->map.map_data[0][i] != '1' || \
			app->map.map_data[app->height - 1][i] != '1')
			exit_with_error("map error : no wall at edge");
		i++;
	}
	i = 0;
	while (i < app->height)
	{
		if (app->map.map_data[i][0] != '1' || \
			app->map.map_data[i][app->width - 1] != '1')
			exit_with_error("map error : no wall at edge");
		i++;
	}
}

void	map_check(t_so_long *app)
{
	int	width;
	int	i;
	int	temp_width;

	i = 0;
	width = -1;
	while (i < app->height)
	{
		temp_width = line_check(app->map.map_data[i]);
		if (width != -1 && width != temp_width)
			exit_with_error("map error : map is not retangular");
		width = temp_width;
		i++;
	}
	app->width = width;
	check_edge(app);
	check_count(app);
	check_map_valid(app);
}
