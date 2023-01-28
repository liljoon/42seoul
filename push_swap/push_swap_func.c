/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:18:30 by isunwoo           #+#    #+#             */
/*   Updated: 2023/01/27 18:08:12 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_proper_idx(t_stack *a, int data)
{
	int	put_idx;
	int	smallest_idx;

	smallest_idx = find_smallest(a);
	put_idx = smallest_idx;
	while (1)
	{
		if (a->data[put_idx] > data)
			break ;
		if (put_idx == a->bottom)
			put_idx = a->top;
		else
			put_idx = before_idx(a, put_idx);
		if (put_idx == smallest_idx)
			break ;
	}
	return (put_idx);
}

void	count_operation(t_stack *a, t_stack *b, int b_idx, int *oper_count)
{
	int	put_idx;

	count_rotation(b, b_idx, oper_count);
	if (oper_count[0] > oper_count[1])
		oper_count[0] = 0;
	else
		oper_count[1] = 0;
	if (a->len <= 1)
	{
		oper_count[2] = 0;
		oper_count[3] = 0;
		return ;
	}
	put_idx = find_proper_idx(a, b->data[b_idx]);
	count_rotation(a, put_idx, oper_count + 2);
	if (oper_count[2] > oper_count[3])
		oper_count[2] = 0;
	else
		oper_count[3] = 0;
}

int	select_one(t_stack *a, t_stack *b)
{
	int	ret;
	int	b_idx;
	int	smallest;
	int	temp;
	int	oper_count[4];

	b_idx = b->top;
	smallest = 2147483647;
	while (1)
	{
		count_operation(a, b, b_idx, oper_count);
		temp = oper_count[0] + oper_count[1] + oper_count[2] + oper_count[3];
		if (temp < smallest)
		{
			smallest = temp;
			ret = b_idx;
		}
		if (b_idx == b->bottom)
			break ;
		b_idx = before_idx(b, b_idx);
	}
	return (ret);
}

void	operate(t_stack *a, t_stack *b, int b_idx)
{
	int	oper_count[4];
	int	i;

	count_operation(a, b, b_idx, oper_count);
	i = 0;
	while (i++ < oper_count[0])
		rb(b);
	i = 0;
	while (i++ < oper_count[1])
		rrb(b);
	i = 0;
	while (i++ < oper_count[2])
		ra(a);
	i = 0;
	while (i++ < oper_count[3])
		rra(a);
	pa(a, b);
}

void	smallest_to_top(t_stack *a)
{
	int	smallest_idx;
	int	cnt_oper[2];
	int	i;

	smallest_idx = find_smallest(a);
	count_rotation(a, smallest_idx, cnt_oper);
	i = 0;
	if (cnt_oper[0] > cnt_oper[1])
	{
		while (i++ < cnt_oper[1])
			rra(a);
	}
	else
	{
		while (i++ < cnt_oper[0])
			ra(a);
	}
}
