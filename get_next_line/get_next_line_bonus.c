/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:31:32 by isunwoo           #+#    #+#             */
/*   Updated: 2022/07/28 15:57:51 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_buffer	buff[OPEN_MAX];
	char			*res;

	if (fd < 0 || fd >= OPEN_MAX)
		return (NULL);
	res = read_line(fd, &buff[fd]);
	return (res);
}
