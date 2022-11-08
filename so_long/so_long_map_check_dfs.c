/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_check_dfs.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:28:58 by isunwoo           #+#    #+#             */
/*   Updated: 2022/11/08 21:51:51 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dfs(int y, int x, t_so_long *app, t_cnt_map *cnt)
{

}

void	check_map_valid(t_so_long *app)
{
	char	**map;
	char	**visited;
	int		i;
	int		j;

	visited = malloc(sizeof(char *) * app->height);
	i = 0;
	while (i < app->height)
	{
		visited[i] = malloc(sizeof(char) * app->width);
		j = 0;
		while (j < app->width)
		{
			visited[i][j] = 0;
			j++;
		}
		i++;
	}
	map = app->map.map_data;


}
