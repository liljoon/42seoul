/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:45:14 by isunwoo           #+#    #+#             */
/*   Updated: 2023/01/27 18:08:08 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack{
	int	*data;
	int	top;
	int	bottom;
	int	len;
	int	total_size;
}	t_stack;

int		select_one(t_stack *a, t_stack *b);
void	operate(t_stack *a, t_stack *b, int b_idx);
void	smallest_to_top(t_stack *a);

void	init_stack(t_stack *st, int size);
int		pop_back(t_stack *st);
int		pop_front(t_stack *st);
void	push_back(t_stack *st, int num);
void	push_front(t_stack *st, int num);
int		before_idx(t_stack *st, int idx);
int		next_idx(t_stack *st, int idx);

void	sort_below_5(t_stack *a, t_stack *b);

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

void	error_exit(void);
void	count_rotation(t_stack *st, int idx, int *ret);
int		find_biggest(t_stack *a);
int		find_smallest(t_stack *a);

void	init_stack_data(t_stack *a, t_stack *b, int argc, char *argv[]);
void	check_already_sorted(t_stack *a);
void	check_duplicates(t_stack *a);

void	partitioning(t_stack *a, t_stack *b);

#endif
