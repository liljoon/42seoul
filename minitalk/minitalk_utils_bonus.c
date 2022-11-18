/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:59:57 by isunwoo           #+#    #+#             */
/*   Updated: 2022/11/18 14:34:52 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_utils.h"

static int	check_sign(const char *str, int *idx)
{
	int	sign;

	sign = 1;
	if (str[*idx] != '\0' && (str[*idx] == '+' || str[*idx] == '-'))
	{
		if (str[*idx] == '-')
			sign *= -1;
		(*idx)++;
	}
	return (sign);
}

int	ft_atoi(const char *str)
{
	int		idx;
	int		sign;
	long	ret;

	sign = 1;
	idx = 0;
	ret = 0;
	while (str[idx] != '\0'
		&& ((str[idx] >= 9 && str[idx] <= 13) || str[idx] == 32))
		idx++;
	sign = check_sign(str, &idx);
	while (str[idx] != '\0' && str[idx] >= '0' && str[idx] <= '9')
	{
		ret = ret * 10 + str[idx] - '0';
		idx++;
		if (ret > 2147483647 && sign == 1)
			return (-1);
		if (ret > 2147483648 && sign == -1)
			return (0);
	}
	return ((int)(ret * sign));
}

static void	print_recursive(int n, int fd)
{
	char	print_char;

	if (n <= 0)
	{
		return ;
	}
	else
	{
		print_recursive(n / 10, fd);
		print_char = n % 10 + '0';
		write(fd, &print_char, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int		dividend;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		dividend = -1 * n;
		write(fd, "-", 1);
	}
	else if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	else
	{
		dividend = n;
	}
	print_recursive(dividend, fd);
}
