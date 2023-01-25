/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_preprocess.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:07:25 by isunwoo           #+#    #+#             */
/*   Updated: 2023/01/25 21:22:11 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicates(t_stack *a)
{
	int	idx;
	int	compare;

	if (a->len <= 1)
		return ;
	idx = a->top;
	while (idx != a->bottom)
	{
		compare = before_idx(a, idx);
		while (1)
		{
			if (a->data[idx] == a->data[compare])
				error_exit();
			if (compare == a->bottom)
				break ;
			compare = before_idx(a, compare);
		}
		idx = before_idx(a, idx);
	}
}

int	check_and_atoi(char *s)
{
	long	ret;

	ret = 0;
	while (*s)
	{
		if (*s >= '0' && *s <= '9')
			ret = ret * 10 + *s - '0';
		else
			error_exit();
		if (ret > 2147483647L)
			error_exit();
		s++;
	}
	return ((int)ret);
}

void	split_int(t_stack *a, t_stack *b, char *s)
{
	long	temp;
	int		cnt_space;
	char	*str;

	cnt_space = 0;
	str = s;
	while (*str)
	{
		if (*str == ' ')
			cnt_space++;
		str++;
	}
	init_stack(a, cnt_space + 1);
	init_stack(b, cnt_space + 1);
	temp = 0;
	while (*s)
	{
		if (*s >= '0' && *s <= '9')
			temp = temp * 10 + (*s - '0');
		else
			error_exit();
		if (temp > 2147483647L)
			error_exit();
		s++;
		if (*s == ' ')
		{
			push_front(a, (int)temp);
			temp = 0;
			s++;
		}
	}
	push_front(a, (int)temp);
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
	int	temp;

	if (argc > 2)
	{
		init_stack(a, argc - 1);
		init_stack(b, argc - 1);
		idx = 1;
		while (idx < argc)
		{
			temp = check_and_atoi(argv[idx]);
			push_front(a, temp);
			idx++;
		}
	}
	else if (argc == 2)
	{
		split_int(a, b, argv[1]);
	}
	else
		exit(0);
}
