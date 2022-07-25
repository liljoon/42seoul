/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:31:32 by isunwoo           #+#    #+#             */
/*   Updated: 2022/07/25 21:24:31 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_buffer	buff;
	char			*res;
	int				length;

	if (buff.pos == 0)
	{
		if (read(fd, buff.content, BUFFER_SIZE) == -1)
			return (NULL);
	}
	length = get_length(&buff);
	res = malloc(sizeof(char) * (length + 1));
	if (!res)
		return (NULL);
	ft_memcpy(res, buff.content + buff.pos, length);
	buff.pos += length + 1;
	if (buff.pos >= BUFFER_SIZE)
		buff.pos = 0;
	res[length] = '\n';
	return (res);
}
