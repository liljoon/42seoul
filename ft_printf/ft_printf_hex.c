/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 19:30:36 by isunwoo           #+#    #+#             */
/*   Updated: 2022/08/04 20:58:45 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex(int n, int upper)
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
}

void	convert_dec_to_hex(unsigned int num, int upper)
{
	if (num <= 15)
		print_hex(num, upper);
	else
	{
		convert_dec_to_hex(num / 16, upper);
		print_hex(num % 16, upper);
	}
}

void	convert_pointer_to_hex_recur(unsigned long num)
{
	if (num <= 15)
		print_hex(num, 0);
	else
	{
		convert_pointer_to_hex_recur(num / 16);
		print_hex(num % 16, 0);
	}
}

void	convert_pointer_to_hex(void *p)
{
	unsigned long	ul;

	ul = (unsigned long)p;
	write(1, "0x", 2);
	convert_pointer_to_hex_recur(ul);
}
