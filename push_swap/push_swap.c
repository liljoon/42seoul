/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:47:53 by isunwoo           #+#    #+#             */
/*   Updated: 2023/01/27 20:11:41 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	int		i;

	init_stack_data(&a, &b, argc, argv);
	check_duplicates(&a);
	check_already_sorted(&a);
	if (a.len <= 5)
	{
		sort_below_5(&a, &b);
		return (0);
	}
	partitioning(&a, &b);
	i = 0;
	while (i++ < b.total_size)
		operate(&a, &b, select_one(&a, &b));
	smallest_to_top(&a);
	free(a.data);
	free(b.data);
}
