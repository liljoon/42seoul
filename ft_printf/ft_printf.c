/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:48:41 by isunwoo           #+#    #+#             */
/*   Updated: 2022/08/07 22:06:31 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_control(char command, va_list *vl, int *cnt)
{
	if (command == 'c')
		(*cnt) += print_char((char)va_arg(*vl, int));
	else if (command == 's')
		(*cnt) += print_string(va_arg(*vl, char *));
	else if (command == 'p')
		(*cnt) += convert_pointer_to_hex(va_arg(*vl, void *));
	else if (command == 'd')
		(*cnt) += ft_putnbr_cnt(va_arg(*vl, int));
	else if (command == 'i')
		(*cnt) += ft_putnbr_cnt(va_arg(*vl, int));
	else if (command == 'u')
		print_unsigned_int(va_arg(*vl, unsigned int), cnt);
	else if (command == 'x')
		convert_dec_to_hex(va_arg(*vl, unsigned int), 0, cnt);
	else if (command == 'X')
		convert_dec_to_hex(va_arg(*vl, unsigned int), 1, cnt);
	else if (command == '%')
		(*cnt) += print_char('%');
}

int	ft_printf(const char *format, ...)
{
	int		idx;
	int		cnt;
	va_list	vl;

	cnt = 0;
	va_start(vl, format);
	idx = 0;
	while (format[idx] != '\0')
	{
		if (format[idx] != '%')
		{
			cnt++;
			write(1, &format[idx], 1);
		}
		else
		{
			print_control(format[idx + 1], &vl, &cnt);
			idx++;
		}
		idx++;
	}
	va_end(vl);
	return (cnt);
}
