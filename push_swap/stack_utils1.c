/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:45:18 by isunwoo           #+#    #+#             */
/*   Updated: 2023/01/25 20:29:31 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	next_idx(t_stack *st, int idx)
{
	return ((idx + 1) % st->total_size);
}

int	before_idx(t_stack *st, int idx)
{
	return ((idx + st->total_size - 1) % st->total_size);
}

void	init_stack(t_stack *st, int size)
{
	st->top = size - 1;
	st->bottom = 0;
	st->data = malloc(size * sizeof(int));
	st->len = 0;
	st->total_size = size;
}

int	pop_back(t_stack *st)
{
	int	temp;

	temp = st->data[st->top];
	st->top = before_idx(st, st->top);
	st->len -= 1;
	return (temp);
}

int	pop_front(t_stack *st)
{
	int	temp;

	temp = st->data[st->bottom];
	st->bottom = next_idx(st, st->bottom);
	st->len -= 1;
	return (temp);
}
