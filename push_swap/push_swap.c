/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:47:53 by isunwoo           #+#    #+#             */
/*   Updated: 2023/01/21 23:38:44 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

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

int a_biggest_idx;
int find_biggest(t_stack *a);
void	count_operation(t_stack *a, t_stack *b, int b_idx, int *oper_count)
{
	int put_idx;
	int	data;

	oper_count[0] = (b->top + b->total_size - b_idx) % b->total_size;
	oper_count[1] = (b_idx + b->total_size  - b->bottom + 1) % b->total_size ;
	if (oper_count[0] > oper_count[1])
		oper_count[0] = 0;
	else
		oper_count[1] = 0;

	if (a->len == 0)
	{
		oper_count[2] = 0;
		oper_count[3] = 0;
		return ;
	}
	data = b->data[b_idx];
	put_idx = a_biggest_idx;
	while (1)
	{
		if (a->data[put_idx] < data)
			break;
		if(put_idx == a->top)
			put_idx = a->bottom;
		else
			put_idx = next_idx(a, put_idx);

		if(put_idx == a_biggest_idx)
			break ;
	}
	oper_count[2] = (a->top + a->total_size - put_idx + 1) % a->total_size;
	oper_count[3] = (put_idx + a->total_size - a->bottom) % a->total_size;

	if (oper_count[2] > oper_count[3])
		oper_count[2] = 0;
	else
		oper_count[3] = 0;
}

int	select_one(t_stack *a, t_stack *b)
{
	int	ret;
	int	b_idx;
	int	smallest;
	int	temp;
	int oper_count[4]; // rb, rrb, ra, rra

	b_idx = b->top;
	smallest = 2147483647;
	while (1)
	{
		temp = 0;
		count_operation(a, b, b_idx, oper_count);
		for(int i=0;i<4;i++)
			temp += oper_count[i];
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

int find_biggest(t_stack *a)
{
	int	idx;
	int	ret;

	ret = a->top;
	idx = a->top;
	while (1)
	{
		if (a->data[idx] > a->data[ret])
			ret = idx;
		if (idx == a->bottom)
			break;
		idx = before_idx(a, idx);
	}
	return (ret);
}


void	operate(t_stack *a, t_stack *b, int b_idx)
{
	int oper_count[4];

	count_operation(a, b, b_idx, oper_count);
	for(int i=0;i<oper_count[0];i++)
		rb(a, b);
	for(int i=0;i<oper_count[1];i++)
		rrb(a, b);

	for(int i=0;i<oper_count[2];i++)
		ra(a, b);
	for(int i=0;i<oper_count[3];i++)
		rra(a, b);
	pa(a, b);
	if (a->len == 1)
		a_biggest_idx = a->top;

	a_biggest_idx = find_biggest(a);	//update biggest
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

	for(int i=0;i<b.total_size;i++)
	 	operate(&a, &b, select_one(&a, &b));

	int t = (a.top + a.total_size - a_biggest_idx + 1) % a.total_size;
	if (t > (a_biggest_idx + a.total_size - a.bottom) % a.total_size)
	{
		t = (a_biggest_idx + a.total_size - a.bottom) % a.total_size;
		for(int i=0;i < t;i++)
			rra(&a, &b);
	}
	else
	{
	for(int i=0;i < t;i++)
		ra(&a, &b);
	}

	//info(&a);
	//info(&b);
}
