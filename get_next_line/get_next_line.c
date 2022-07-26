/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:31:32 by isunwoo           #+#    #+#             */
/*   Updated: 2022/07/26 20:02:53 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_buffer	buff;
	char			*res;

	res = NULL;
	while (1)
	{
		if (buff.pos >= buff.read_len)
			buff.pos = 0;
		if (buff.pos == 0)
		{
			buff.read_len = read(fd, buff.content, BUFFER_SIZE);
			if (buff.read_len < 0)
				return (NULL);
			else if (buff.read_len == 0)
				return (res);
		}
		res = str_push_back(res, buff.content + buff.pos, get_length(&buff));
		if (!res)
			return (NULL);
		buff.pos += get_length(&buff);
		if (buff.content[buff.pos - 1] == '\n' || buff.read_len < BUFFER_SIZE)
			break ;
	}
	return (res);
}
