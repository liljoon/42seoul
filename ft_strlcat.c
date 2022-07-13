/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:49:25 by isunwoo           #+#    #+#             */
/*   Updated: 2022/07/13 11:14:12 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	length_str(const char *str)
{
	size_t	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		idx++;
	}
	return (idx);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;
	size_t	length_src;
	size_t	length_dst;

	length_src = length_str(src);
	length_dst = length_str(dst);
	if (length_dst >= dstsize)
		return (length_src + dstsize);
	idx = length_dst;
	while (idx < dstsize - 1 && src[idx - length_dst] != '\0')
	{
		dst[idx] = src[idx - length_dst];
		idx++;
	}
	dst[idx] = '\0';
	return (length_src + length_dst);
}
