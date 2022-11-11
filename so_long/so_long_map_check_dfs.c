/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_check_dfs.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:28:58 by isunwoo           #+#    #+#             */
/*   Updated: 2022/11/11 20:26:05 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dfs(int y, int x, t_so_long *app, t_cnt_map *cnt)
{
	if (y >= app->height || y < 0 || x >= app->width || x < 0 || \
		app->visited[y][x] || app->map.map_data[y][x] == '1')
		return ;
	app->visited[y][x] = 1;
	if (app->map.map_data[y][x] == 'E')
		cnt->e += 1;
	else if (app->map.map_data[y][x] == 'C')
		cnt->c += 1;
	dfs(y + 1, x, app, cnt);
	dfs(y - 1, x, app, cnt);
	dfs(y, x + 1, app, cnt);
	dfs(y, x - 1, app, cnt);
}

void	start_dfs(t_so_long *app)
{
	int			i;
	int			j;
	t_cnt_map	cnt;

	cnt.c = 0;
	cnt.e = 0;
	i = 0;
	while (i < app->height)
	{
		j = 0;
		while (j < app->width)
		{
			if (app->map.map_data[i][j] == 'P')
				dfs(i, j, app, &cnt);
			j++;
		}
		i++;
	}
	if (app->map.col_cnt != cnt.c || cnt.e != 1)
		exit_with_error("invalid map\n");
}

void	free_visited(t_so_long *app)
{
	int	i;

	i = 0;
	while (i < app->height)
	{
		free(app->visited[i]);
		i++;
	}
	free(app->visited);
}

void	check_map_valid(t_so_long *app)
{
	int			i;
	int			j;

	app->visited = malloc(sizeof(char *) * app->height);
	i = 0;
	while (i < app->height)
	{
		app->visited[i] = malloc(sizeof(char) * app->width);
		j = 0;
		while (j < app->width)
		{
			app->visited[i][j] = 0;
			j++;
		}
		i++;
	}
	start_dfs(app);
	free_visited(app);
}
