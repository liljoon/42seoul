/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:25:16 by isunwoo           #+#    #+#             */
/*   Updated: 2022/11/07 14:53:26 by isunwoo          ###   ########.fr       */
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
	{
		perror("open");
		exit(1);
	}
	while (read(fd, &ch, 1))
	{
		if (ch == '\n')
			count++;
	}
	app->height = count;
	app->map.map_data = malloc(sizeof(*(app->map.map_data)) * count); // free
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
		{
			perror("map error");
			exit(1);
		}
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
		{
			perror("map error3");
			exit(1);
		}
		i++;
	}
	i = 0;
	while (i < app->height)
	{
		if (app->map.map_data[i][0] != '1' || \
			app->map.map_data[i][app->width - 1] != '1')
		{
			perror("map error3");
			exit(1);
		}
		i++;
	}
}

void	check_count(t_so_long *app)
{
	int	i;
	int	j;
	int	e_cnt;
	int	c_cnt;
	int	p_cnt;

	i = 0;
	e_cnt = 0;
	c_cnt = 0;
	p_cnt = 0;
	while (i < app->height)
	{
		j = 0;
		while (j < app->width)
		{
			if (app->map.map_data[i][j] == 'P')
				p_cnt++;
			else if (app->map.map_data[i][j] == 'E')
				e_cnt++;
			else if (app->map.map_data[i][j] == 'C')
				c_cnt++;
			j++;
		}
		i++;
	}
	if (p_cnt != 1 || e_cnt != 1)
	{
		perror("P,C map error");
		exit(1);
	}
	app->map.col_cnt = c_cnt;
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
		{
			perror("map error2");
			exit(1);
		}
		width = temp_width;
		i++;
	}
	app->width = width;
	check_edge(app);
	check_count(app);
}

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
