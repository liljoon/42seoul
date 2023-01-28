/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:34:05 by isunwoo           #+#    #+#             */
/*   Updated: 2023/01/27 17:47:30 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	find_biggest(t_stack *a)
{
	int	idx;
	int	ret;

	ret = a->top;
	idx = a->top;
	while (1)
	{
		if (a->data[idx] > a->data[ret])
			ret = idx;
		if (idx == a->bottom)
			break ;
		idx = before_idx(a, idx);
	}
	return (ret);
}

int	find_smallest(t_stack *a)
{
	int	idx;
	int	ret;

	ret = a->top;
	idx = a->top;
	while (1)
	{
		if (a->data[idx] < a->data[ret])
			ret = idx;
		if (idx == a->bottom)
			break ;
		idx = before_idx(a, idx);
	}
	return (ret);
}

void	count_rotation(t_stack *st, int idx, int *ret)
{
	ret[0] = (st->top + st->total_size - idx) % st->total_size;
	ret[1] = (idx + st->total_size - st->bottom + 1) % st->total_size;
}

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
