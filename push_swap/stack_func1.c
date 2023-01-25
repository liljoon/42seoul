/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:45:16 by isunwoo           #+#    #+#             */
/*   Updated: 2023/01/25 20:38:17 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a, t_stack *b)
{
	int	temp1;
	int	temp2;

	if (a->len <= 1)
		return ;
	temp1 = pop_back(a);
	temp2 = pop_back(a);
	push_back(a, temp1);
	push_back(a, temp2);
	write(1, "sa\n", 3);
}

void	sb(t_stack *a, t_stack *b)
{
	int	temp1;
	int	temp2;

	if (b->len <= 1)
		return ;
	temp1 = pop_back(b);
	temp2 = pop_back(b);
	push_back(b, temp1);
	push_back(b, temp2);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	int	temp1;
	int	temp2;

	if (a->len > 1)
	{
		temp1 = pop_back(a);
		temp2 = pop_back(a);
		push_back(a, temp1);
		push_back(a, temp2);
	}
	if (b->len > 1)
	{
		temp1 = pop_back(b);
		temp2 = pop_back(b);
		push_back(b, temp1);
		push_back(b, temp2);
	}
	write(1, "ss\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	if (b->len == 0)
		return ;
	push_back(a, pop_back(b));
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->len == 0)
		return ;
	push_back(b, pop_back(a));
	write(1, "pb\n", 3);
}
