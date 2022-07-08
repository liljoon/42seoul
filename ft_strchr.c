/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:19:45 by isunwoo           #+#    #+#             */
/*   Updated: 2022/07/07 17:37:00 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	p = s;
	while (*p != '\0')
	{
		if (*p == (char)c)
			return (p);
		p++;
	}
	if (c == '\0')
		return (p);
	else
		return (NULL);
}
