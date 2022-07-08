/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:37:45 by isunwoo           #+#    #+#             */
/*   Updated: 2022/07/08 19:06:46 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	idx;

	idx = 0;
	p = malloc(len + 1);
	if (p == NULL)
		return (NULL);
	while (s[start + idx] != '\0' && idx < len)
	{
		p[idx] = s[start + idx];
		idx++;
	}
	p[idx] = '\0';
	return (p);
}
