/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:29:58 by isunwoo           #+#    #+#             */
/*   Updated: 2023/01/27 18:07:38 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	push_front(a, pop_back(a));
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	push_front(b, pop_back(b));
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}

void	rra(t_stack *a)
{
	push_back(a, pop_front(a));
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	push_back(b, pop_front(b));
	write(1, "rrb\n", 4);
}
