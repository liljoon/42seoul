/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 19:30:36 by isunwoo           #+#    #+#             */
/*   Updated: 2022/08/05 18:14:28 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex(int n, int upper, int *cnt)
{
	char	c;

	if (n <= 9)
	{
		c = n + '0';
		write(1, &c, 1);
	}
	else
	{
		if (upper)
			c = n - 10 + 'A';
		else
			c = n - 10 + 'a';
		write(1, &c, 1);
	}
	(*cnt)++;
}

void	convert_dec_to_hex(unsigned int num, int upper, int *cnt)
{
	if (num <= 15)
		print_hex(num, upper, cnt);
	else
	{
		convert_dec_to_hex(num / 16, upper, cnt);
		print_hex(num % 16, upper, cnt);
	}
}

void	convert_pointer_to_hex_recur(unsigned long num, int *cnt)
{
	if (num <= 15)
		print_hex(num, 0, cnt);
	else
	{
		convert_pointer_to_hex_recur(num / 16, cnt);
		print_hex(num % 16, 0, cnt);
	}
}

int	convert_pointer_to_hex(void *p)
{
	unsigned long	ul;
	int				cnt;

	cnt = 0;
	ul = (unsigned long)p;
	write(1, "0x", 2);
	cnt += 2;
	convert_pointer_to_hex_recur(ul, &cnt);
	return (cnt);
}
