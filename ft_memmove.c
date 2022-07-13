/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:29:46 by isunwoo           #+#    #+#             */
/*   Updated: 2022/07/12 16:53:08 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	idx;

	if (dst < src)
	{
		idx = 0;
		while (idx < len)
		{
			*((unsigned char *)dst + idx) = *((unsigned char *)src + idx);
			idx++;
		}
	}
	else
	{
		idx = len - 1;
		while (idx >= 0)
		{
			*((unsigned char *)dst + idx) = *((unsigned char *)src + idx);
			idx--;
		}
	}
	return (dst);
}
