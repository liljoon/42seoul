/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:48:41 by isunwoo           #+#    #+#             */
/*   Updated: 2022/08/03 22:04:09 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_control(char command, char c);

int	ft_printf(const char *format, ...)
{
	int		idx;
	va_list	vl;

	va_start(vl, format);
	idx = 0;
	while (format[idx] != '\0')
	{
		if(format[idx] != '%')
			write(1, &format[idx], 1);
		else
		{
			char c = va_arg(vl, char);
			print_control(format[idx + 1], c);
			idx++;
		}
		idx++;
	}
	va_end(vl);
	return 0;
}

void print_control(char command, char c)
{
	if (command == 'c')
	{
		ft_putchar_fd(c, 1);
	}
	else if (command == 's')
		return ;
	else if (command == 'p')
		return ;
	else if (command == 'd')
	{
		ft_putnbr_fd(c, 1);
	}
	else if (command == 'i')
		return ;
	else if (command == 'u')
		return ;
	else if (command == 'x')
		return ;
	else if (command == 'X')
		return ;
	else if (command == '%')
		return ;
}

int main()
{
	ft_printf("aaa%c%c%c%d",'v','l', 'k',123);
}
