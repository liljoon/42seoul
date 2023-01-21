/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_below_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 01:06:41 by isunwoo           #+#    #+#             */
/*   Updated: 2023/01/22 01:14:22 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_2(t_stack *a, t_stack *b)
{
	if(a->data[a->top] > a->data[before_idx(a, a->top)])
		ss(a, b);
}

void sort_3(t_stack *a, t_stack *b)
{
	int biggest_idx;

	biggest_idx = find_biggest(a);
	if (biggest_idx == a->top)
	{
		ra(a, b);
		sort_2(a, b);
	}
	else if (biggest_idx == a->bottom)
		sort_2(a, b);
	else
	{
		rra(a, b);
		sort_2(a, b);
	}
}

void sort_below_5(t_stack *a, t_stack *b)
{
	if (a->len == 2)
		sort_2(a, b);
	if (a->len == 3)
		sort_3(a, b);
}
