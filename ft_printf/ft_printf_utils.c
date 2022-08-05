/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:58:26 by isunwoo           #+#    #+#             */
/*   Updated: 2022/08/05 18:06:11 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

static void	print_recursive(int n, int *cnt)
{
	char	print_char;

	if (n <= 0)
	{
		return ;
	}
	else
	{
		print_recursive(n / 10, cnt);
		print_char = n % 10 + '0';
		write(1, &print_char, 1);
		(*cnt)++;
	}
}

int	ft_putnbr_cnt(int n)
{
	int	dividend;
	int	cnt;

	cnt = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		dividend = -1 * n;
		write(1, "-", 1);
		cnt++;
	}
	else if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
		dividend = n;
	print_recursive(dividend, &cnt);
	return (cnt);
}
