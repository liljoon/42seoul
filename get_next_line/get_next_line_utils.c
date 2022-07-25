/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:32:17 by isunwoo           #+#    #+#             */
/*   Updated: 2022/07/25 21:24:37 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_length(t_buffer *buff)
{
	int	cnt;

	cnt = 0;
	while (buff->content[buff->pos + cnt] != '\n'
		&& buff->pos + cnt < BUFFER_SIZE)
		cnt++;
	return (cnt);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	idx;

	if (!dst || !src)
		return (NULL);
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
