/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:45:18 by isunwoo           #+#    #+#             */
/*   Updated: 2023/01/02 19:52:05 by isunwoo          ###   ########.fr       */
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
