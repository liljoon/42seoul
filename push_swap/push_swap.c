/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:47:53 by isunwoo           #+#    #+#             */
/*   Updated: 2023/01/20 15:43:50 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int a_start, a_end;

void info(t_stack *st)
{
	printf("\n");

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
	printf("\n");

}

int	compare(const void *a , const void *b)
{
	if( *(int*)a > *(int*)b )
		return 1;
	else if( *(int*)a < *(int*)b )
		return -1;
	else
		return 0;
}

void division(t_stack *st, int n, int* divs)
{
	int *arr;
	int temp = st->top;
	arr = malloc(n * 4);
	for(int i=0;i<n;i++)
	{
		arr[i] = st->data[temp];
		temp = before_idx(st, temp);
	}
	qsort(arr, n, 4, compare);
	divs[0] = arr[n/3];
	divs[1] = arr[2 * n / 3];
	free(arr);
}

void partitioning(t_stack *a, t_stack *b)
{
	int divs[2];
	int	i;

	division(a, a->len, divs);
	i = 0;
	while (i < a->total_size)
	{
		if (a->data[a->top] < divs[0])
		{
			pb(a, b);
			rb(a, b);
		}
		else if(a->data[a->top] > divs[1])
			ra(a, b);
		else
			pb(a, b);
		i++;
	}
	while (a->len)
	{
		pb(a, b);
	}
}

int	count_operation(t_stack *a, t_stack *b, int b_idx)
{
	int	cnt;
	int rb;
	int rrb;
	int	ra;
	int	rra;
	int a_idx;
	cnt = 0;
	rb = (b->top + b->total_size - b_idx) % b->total_size;
	rrb = (b_idx + b->total_size  - b->bottom) % b->total_size + 1;
	if (rb > rrb)
		cnt+= rrb;
	else
		cnt+= rb;
	a_idx = a_start;
	for(int i=0;i<a->len;i++)
	{
		int before = a_idx;
		if (a_idx == a->top)
			a_idx = a->bottom;
		else
			a_idx = next_idx(a, a_idx);
		if (a->data[a_idx] < b->data[b_idx])
			break;
	}
	ra = (a->top + a->total_size - a_idx) % a->total_size;
	rra = (a_idx + a->total_size  - a->bottom + 1) % a->total_size;
	if (ra > rra)
		cnt+= rra;
	else
		cnt+= ra;

	return cnt;
}

int	select_one(t_stack *a, t_stack *b)
{
	int	ret;
	int	b_idx;
	int	smallest;
	int	temp;

	b_idx = b->top;
	smallest = 2147483647;
	while (1)
	{
		temp = count_operation(a, b, b_idx);
		if (temp < smallest)
		{
			smallest = temp;
			ret = b_idx;
		}
		if (b_idx == b->bottom)
			break;
		b_idx = before_idx(b, b_idx);
	}
	return (ret);
}

void	operate(t_stack *a, t_stack *b, int b_idx)
{
	int	cnt;
	int rb_cnt;
	int rrb_cnt;
	int	ra_cnt;
	int	rra_cnt;
	int a_idx;
	cnt = 0;
	rb_cnt = (b->top + b->total_size - b_idx) % b->total_size;
	rrb_cnt = (b_idx + b->total_size  - b->bottom) % b->total_size + 1;
	if (rb_cnt > rrb_cnt)
	{
		for(int i=0;i<rrb_cnt;i++)
			rrb(a,b);
	}
	else
	{
		for(int i=0;i<rb_cnt;i++)
			rb(a,b);
	}
	a_idx = a_start;
	for(int i=0;i<a->len;i++)
	{
		int before = a_idx;
		if (a_idx == a->top)
			a_idx = a->bottom;
		else
			a_idx = next_idx(a, a_idx);
		if (a->data[a_idx] < b->data[b_idx])
			break;
	}
	ra_cnt = (a->top + a->total_size - a_idx) % a->total_size;
	rra_cnt = (a_idx + a->total_size  - a->bottom + 1) % a->total_size;
	if (ra_cnt > rra_cnt)
	{
		for(int i=0;i<rra_cnt;i++)
		{
			rra(a,b);
			if (a_start == a->bottom)
			{
				a_start = a->top;
			}
			else
				a_start = before_idx(a, a_start);
		}
	}
	else
	{
		for(int i=0;i<ra_cnt;i++)
		{
			ra(a,b);
			if (a_start == a->top)
			{
				a_start = a->bottom;
			}
			else
				a_start = next_idx(a, a_start);
		}
	}

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
		push_front(&a, ft_atoi(argv[idx]));
		idx++;
	}
	partitioning(&a, &b);
	a_start = a.top;
	a_end = a.bottom;
	for(int i=0;i<b.total_size;i++)
	 	operate(&a, &b, select_one(&a, &b));



	info(&a);
	info(&b);
}
