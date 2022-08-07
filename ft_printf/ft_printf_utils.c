/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:58:26 by isunwoo           #+#    #+#             */
/*   Updated: 2022/08/07 22:14:31 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	return (write(1, &c, 1));
}

static void	print_recursive(int n, int *cnt)
{
	char	c;

	if (n <= 0)
	{
		return ;
	}
	else
	{
		print_recursive(n / 10, cnt);
		c = n % 10 + '0';
		write(1, &c, 1);
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

int	print_string(char *s)
{
	int	idx;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	idx = 0;
	while (s[idx])
	{
		write(1, s + idx, 1);
		idx++;
	}
	return (idx);
}

void	print_unsigned_int(unsigned int num, int *cnt)
{
	char	c;

	if (num <= 9)
	{
		c = num + '0';
		write (1, &c, 1);
		(*cnt)++;
		return ;
	}
	print_unsigned_int(num / 10, cnt);
	c = num % 10 + '0';
	write(1, &c, 1);
	(*cnt)++;
	return ;
}
