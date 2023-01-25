/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:29:07 by isunwoo           #+#    #+#             */
/*   Updated: 2023/01/25 20:29:32 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back(t_stack *st, int num)
{
	st->top = next_idx(st, st->top);
	st->data[st->top] = num;
	st->len += 1;
}

void	push_front(t_stack *st, int num)
{
	st->bottom = before_idx(st, st->bottom);
	st->data[st->bottom] = num;
	st->len += 1;
}
