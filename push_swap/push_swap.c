/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:47:53 by isunwoo           #+#    #+#             */
/*   Updated: 2023/01/11 21:54:08 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a , const void *b)
{
     if( *(int*)a > *(int*)b )
        return 1;
    else if( *(int*)a < *(int*)b )
        return -1;
    else
        return 0;
}

int mid(t_stack *st, int n)
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
	return (arr[n/2]);
}

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

void	B_to_A(t_stack *a, t_stack *b, int n);

void	A_to_B(t_stack *a, t_stack *b, int n)
{
	int pivot;
	int count = 0;
	if(n <= 0)
		return;
	if (n == 1)
	{
		ra(a ,b);
		return ;
	}
	pivot = mid(a, n);
	for(int i=0;i<n;i++)
	{
		if(a->data[a->top] < pivot)
		{
			pb(a, b);
		}
		else
		{
			ra(a, b);
			count++;
		}
	}
	for(int i=0;i<count;i++)
	{
		rra(a, b);
	}

	B_to_A(a, b, n - count);
	A_to_B(a, b, count);

}

void	B_to_A(t_stack *a, t_stack *b, int n)
{
	int pivot;
	int count = 0;

	if (n <= 0)
		return;
	if (n == 1)
	{
		pa(a, b);
		ra(a, b);
		return ;
	}
	pivot = mid(b, n);

	for(int i=0;i<n;i++)
	{
		if(b->data[b->top] >= pivot)
		{
			pa(a, b);
		}
		else
		{
			rb(a, b);
			count++;
		}
	}
	for(int i= 0;i < count; i++)
	{
		//rrb(a, b);
	}

	B_to_A(a, b, count);
	A_to_B(a, b, n - count);
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
	A_to_B(&a, &b, a.total_size);
	info(&a);
	//info(&b);

}
