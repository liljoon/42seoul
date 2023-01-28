/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_preprocess.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:07:25 by isunwoo           #+#    #+#             */
/*   Updated: 2023/01/28 15:22:21 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_and_atoi(char *s)
{
	long	ret;
	int		sign;

	sign = 1;
	if (*s == '-' || *s == '+')
	{
		sign = 44 - *s;
		s++;
	}
	if (*s == ' ' || *s == 0)
		error_exit();
	ret = 0;
	while (*s && *s != ' ')
	{
		if (*s >= '0' && *s <= '9')
			ret = ret * 10 + *s - '0';
		else
			error_exit();
		if (ret > 2147483648L)
			error_exit();
		s++;
	}
	if (ret == 2147483648 && sign == 1)
		error_exit();
	return ((int)(sign * ret));
}

int	count_words(char *s)
{
	int	ret;

	ret = 0;
	while (*s)
	{
		while (*s && *s == ' ')
			s++;
		if (*s != 0)
			ret += 1;
		while (*s && *s != ' ')
			s++;
	}
	return (ret);
}

void	split_int(t_stack *a, char *s)
{
	int	temp;

	temp = 0;
	while (*s)
	{
		while (*s && *s == ' ')
			s++;
		if (*s != 0)
		{
			temp = check_and_atoi(s);
			push_front(a, temp);
		}
		while (*s && *s != ' ')
			s++;
	}
}

void	check_already_sorted(t_stack *a)
{
	int	i;
	int	is_sorted;

	is_sorted = 1;
	i = a->top;
	while (1)
	{
		if (a->data[i] > a->data[before_idx(a, i)])
		{
			is_sorted = 0;
			break ;
		}
		if (before_idx(a, i) == a->bottom)
			break ;
		i = before_idx(a, i);
	}
	if (is_sorted)
		exit(0);
}

void	init_stack_data(t_stack *a, t_stack *b, int argc, char *argv[])
{
	int	idx;
	int	words_cnt;
	int	temp;

	if (argc >= 2)
	{
		words_cnt = 0;
		idx = 1;
		while (idx < argc)
		{
			temp = count_words(argv[idx++]);
			if (temp == 0)
				error_exit();
			words_cnt += temp;
		}
		init_stack(a, words_cnt);
		init_stack(b, words_cnt);
		idx = 1;
		while (idx < argc)
			split_int(a, argv[idx++]);
	}
	else
		exit(0);
}
