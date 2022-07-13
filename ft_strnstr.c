/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:13:53 by isunwoo           #+#    #+#             */
/*   Updated: 2022/07/13 11:17:13 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	idx;
	size_t	idx2;
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	idx = 0;
	while (haystack[idx] != '\0' && idx < len - needle_len + 1)
	{
		idx2 = 0;
		while (*(haystack + idx + idx2) != '\0' && *(needle + idx2) != '\0')
		{
			if (*(haystack + idx + idx2) != *(needle + idx2))
				break ;
			idx2++;
		}
		if (idx2 == ft_strlen(needle))
			return ((char *)(haystack + idx));
		idx++;
	}
	return (NULL);
}
