/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:44:40 by isunwoo           #+#    #+#             */
/*   Updated: 2022/07/08 17:01:01 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	idx_p;
	size_t	idx;
	char	*p;

	p = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (p == NULL)
		return (NULL);
	idx_p = 0;
	idx = 0;
	while (s1[idx] != '\0')
	{
		p[idx_p] = s1[idx];
		idx++;
		idx_p++;
	}
	idx = 0;
	while (s2[idx] != '\0')
	{
		p[idx_p] = s1[idx];
		idx++;
		idx_p++;
	}
	p[idx_p] = '\0';
	return (p);
}
