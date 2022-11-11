/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:35:41 by isunwoo           #+#    #+#             */
/*   Updated: 2022/11/11 21:08:33 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_object(char m, t_cnt_map *cnt)
{
	if (m == 'P')
		cnt->p++;
	else if (m == 'E')
		cnt->e++;
	else if (m == 'C')
		cnt->c++;
	return ;
}

void	check_count(t_so_long *app)
{
	int			i;
	int			j;
	t_cnt_map	cnt;

	i = 0;
	cnt.e = 0;
	cnt.c = 0;
	cnt.p = 0;
	while (i < app->height)
	{
		j = 0;
		while (j < app->width)
		{
			count_object(app->map.map_data[i][j], &cnt);
			j++;
		}
		i++;
	}
	if (cnt.p != 1 || cnt.e != 1 || cnt.c < 1)
		exit_with_error("map error : wrong numbers of P or E or C");
	app->map.col_cnt = cnt.c;
}
