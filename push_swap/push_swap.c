/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:47:53 by isunwoo           #+#    #+#             */
/*   Updated: 2023/01/02 21:27:59 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void info(t_stack *st)
{
	printf("total_size : %d\n", st->total_size);
	printf("top : %d\n", st->top);
	printf("bottom : %d\n", st->bottom);
	printf("len : %d\n", st->len);

	int i = st->top;
	while (1)
	{
		if (st->len == 0)
			break;
		printf("%d\n", st->data[i]);
		if (i == st->bottom)
			break ;
		i = (i + st->total_size - 1) % st->total_size;

	}

}

void	solve1(t_stack *a, t_stack *b, int n)
{
	int	fivo;
	int	idx;
	int	count;

	if (n== 0)
		return;
	count = 0;
	fivo = a->data[a->top];

	idx = 0;
	while (idx < n)
	{
		if (a->data[a->top] >= fivo)
		{
			toss(b, a);
			write(1, "pb\n", 3);
			count++;
		}
		else
		{
			rotate(a);
			write(1, "ra\n", 3);
		}
		idx++;
	}
	idx = 0;
	while (idx < n - count)
	{
		reverse_rotate(a);
		write(1, "rra\n", 4);
		idx++;
	}
	solve1(a, b, n - count);
}


int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	int		idx;

	init_stack(&a, argc - 1);
	init_stack(&b, argc - 1);
	idx = 1;
	while (idx < argc)
	{
		a.data[argc - idx - 1] = ft_atoi(argv[idx]);
		idx++;
	}
	a.len = argc - 1;
	a.top = argc - 2;


	solve1(&a, &b, argc - 1);


	info(&a);
	info(&b);
}
