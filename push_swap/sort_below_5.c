/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_below_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 01:06:41 by isunwoo           #+#    #+#             */
/*   Updated: 2023/01/27 18:07:05 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack *a)
{
	if (a->data[a->top] > a->data[before_idx(a, a->top)])
		sa(a);
}

void	sort_3(t_stack *a)
{
	int	biggest_idx;

	biggest_idx = find_biggest(a);
	if (biggest_idx == a->top)
		ra(a);
	else if (biggest_idx != a->bottom)
		rra(a);
	sort_2(a);
}

void	sort_4_5(t_stack *a, t_stack *b, int n)
{
	int	smallest_idx;
	int	count_oper[2];
	int	i;

	smallest_idx = find_smallest(a);
	count_rotation(a, smallest_idx, count_oper);
	if (count_oper[0] > count_oper[1])
		count_oper[0] = 0;
	else
		count_oper[1] = 0;
	i = 0;
	while (i++ < count_oper[0])
		ra(a);
	i = 0;
	while (i++ < count_oper[1])
		rra(a);
	pb(a, b);
	if (n == 4)
		sort_3(a);
	else
		sort_4_5(a, b, n - 1);
	pa(a, b);
}

void	sort_below_5(t_stack *a, t_stack *b)
{
	if (a->len <= 1)
		exit(0);
	if (a->len == 2)
		sort_2(a);
	else if (a->len == 3)
		sort_3(a);
	else
		sort_4_5(a, b, a->len);
}
