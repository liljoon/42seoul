/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 19:42:10 by isunwoo           #+#    #+#             */
/*   Updated: 2022/08/05 18:21:55 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	convert_dec_to_hex(unsigned int num, int upper, int *cnt);
int		convert_pointer_to_hex(void *p);
int		ft_putnbr_cnt(int n);
int		print_char(char c);
#endif
