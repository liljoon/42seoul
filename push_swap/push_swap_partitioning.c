/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_partitioning.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:18:47 by isunwoo           #+#    #+#             */
/*   Updated: 2023/01/27 22:32:37 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(int *arr, int n)
{
	int	i;
	int	j;
	int	temp;

	i = n - 1;
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i--;
	}
}

void	division(t_stack *st, int n, int *divs)
{
	int	*arr;
	int	temp;
	int	i;

	temp = st->top;
	arr = malloc(n * sizeof(int));
	if (!arr)
		exit(1);
	i = 0;
	while (i < n)
	{
		arr[i] = st->data[temp];
		temp = before_idx(st, temp);
		i++;
	}
	bubble_sort(arr, n);
	divs[0] = arr[n / 3];
	divs[1] = arr[2 * n / 3];
	free(arr);
}

void	partitioning(t_stack *a, t_stack *b)
{
	int	divs[2];
	int	i;

	division(a, a->len, divs);
	i = 0;
	while (i < a->total_size)
	{
		if (a->data[a->top] < divs[0])
		{
			pb(a, b);
			rb(b);
		}
		else if (a->data[a->top] > divs[1])
			ra(a);
		else
			pb(a, b);
		i++;
	}
	while (a->len)
	{
		pb(a, b);
	}
}
