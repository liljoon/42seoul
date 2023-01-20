/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:47:53 by isunwoo           #+#    #+#             */
/*   Updated: 2023/01/19 19:15:41 by isunwoo          ###   ########.fr       */
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

int compare(const void *a , const void *b)
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
	info(&a);
	//info(&b);
}
