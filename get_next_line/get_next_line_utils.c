/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:32:17 by isunwoo           #+#    #+#             */
/*   Updated: 2022/07/27 21:35:52 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_length_to_copy(t_buffer *buff)
{
	int	cnt;

	cnt = 0;
	while (buff->pos + cnt < buff->read_len)
	{
		if (buff->content[buff->pos + cnt] == '\n')
		{
			cnt++;
			break ;
		}
		cnt++;
	}
	return (cnt);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	idx;

	idx = 0;
	while (idx < n)
	{
		*((unsigned char *)dst + idx) = *((unsigned char *)src + idx);
		idx++;
	}
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t	idx;

	idx = 0;
	while (s[idx] != '\0')
		idx++;
	return (idx);
}

char	*str_push_back(char *origin, char *content, int length)
{
	char	*res;
	int		origin_length;

	if (origin == NULL)
		origin_length = 0;
	else
		origin_length = ft_strlen(origin);
	res = malloc(origin_length + length + 1);
	if (!res)
	{
		free(origin);
		return (NULL);
	}
	ft_memcpy(res, origin, origin_length);
	ft_memcpy(res + origin_length, content, length);
	res[origin_length + length] = '\0';
	free(origin);
	return (res);
}
