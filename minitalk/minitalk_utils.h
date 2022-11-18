/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:59:55 by isunwoo           #+#    #+#             */
/*   Updated: 2022/11/18 14:13:05 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_UTILS_H
# define MINITALK_UTILS_H
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

typedef struct s_char_data
{
	int		idx;
	char	c;
}	t_char_data;

int		ft_atoi(const char *str);
void	ft_putnbr_fd(int n, int fd);

#endif
