/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:48:41 by isunwoo           #+#    #+#             */
/*   Updated: 2022/08/04 20:51:29 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_string(char *s)
{
	write(1, s, ft_strlen(s));
}

void	print_unsigned_int(unsigned int num)
{
	char	c;

	if (num <= 9)
	{
		c = num + '0';
		write (1, &c, 1);
		return ;
	}
	print_unsigned_int(num / 10);
	c = num % 10 + '0';
	write(1, &c, 1);
	return ;
}

void	print_control(char command, va_list *vl)
{
	if (command == 'c')
		ft_putchar_fd((char)va_arg(*vl, int), 1);
	else if (command == 's')
		print_string(va_arg(*vl, char *));
	else if (command == 'p')
		convert_pointer_to_hex(va_arg(*vl, void *));
	else if (command == 'd')
		ft_putnbr_fd(va_arg(*vl, int), 1);
	else if (command == 'i')
		ft_putnbr_fd(va_arg(*vl, int), 1);
	else if (command == 'u')
		print_unsigned_int(va_arg(*vl, unsigned int));
	else if (command == 'x')
		convert_dec_to_hex(va_arg(*vl, unsigned int), 0);
	else if (command == 'X')
		convert_dec_to_hex(va_arg(*vl, unsigned int), 1);
	else if (command == '%')
		write(1, "%", 1);
}

int	ft_printf(const char *format, ...)
{
	int		idx;
	va_list	vl;

	va_start(vl, format);
	idx = 0;
	while (format[idx] != '\0')
	{
		if (format[idx] != '%')
			write(1, &format[idx], 1);
		else
		{
			print_control(format[idx + 1], &vl);
			idx++;
		}
		idx++;
	}
	va_end(vl);
	return (0);
}
