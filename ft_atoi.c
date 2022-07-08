/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:32:57 by isunwoo           #+#    #+#             */
/*   Updated: 2022/07/07 18:34:03 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	idx;
	int	sign;
	int	ret;

	sign = 1;
	idx = 0;
	ret = 0;
	while (str[idx] != '\0'
		&& ((str[idx] >= 9 && str[idx] <= 13) || str[idx] == 32))
	{
		idx++;
	}
	while (str[idx] != '\0' && (str[idx] == '+' || str[idx] == '-'))
	{
		if (str[idx] == '-')
			sign *= -1;
		idx++;
	}
	while (str[idx] != '\0' && str[idx] >= '0' && str[idx] <= '9')
	{
		ret *= 10;
		ret += str[idx] - '0';
		idx++;
	}
	return (sign * ret);
}
