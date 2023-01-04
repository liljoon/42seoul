/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:45:16 by isunwoo           #+#    #+#             */
/*   Updated: 2023/01/02 19:51:51 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *st, int size)
{
	st->top = -1;
	st->bottom = 0;
	st->data = malloc(size * sizeof(int));
	st->len = 0;
	st->total_size = size;
}


void	swap(t_stack *st)
{
	int	temp;

	if (st->len <= 1)
		return ;
	temp = st->data[st->top];
	st->data[st->top] = st->data[before_idx(st, st->top)];
	st->data[before_idx(st, st->top)] = temp;
}

void	toss(t_stack *st1, t_stack *st2)
{
	if (st2->len == 0)
		return ;
	st1->top = next_idx(st1, st1->top);
	st1->data[st1->top] = st2->data[st2->top];
	st1->len += 1;
	st2->len -= 1;
	st2->top = before_idx(st2, st2->top);
}

void	rotate(t_stack *st)
{
	int	temp;

	temp = st->data[st->top];
	st->top = before_idx(st, st->top);
	st->bottom = before_idx(st, st->bottom);
	st->data[st->bottom] = temp;
}

void	reverse_rotate(t_stack *st)
{
	int	temp;

	temp = st->data[st->bottom];
	st->top = next_idx(st, st->top);
	st->bottom = next_idx(st, st->bottom);
	st->data[st->top] = temp;
}
