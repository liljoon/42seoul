/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:45:14 by isunwoo           #+#    #+#             */
/*   Updated: 2023/01/10 19:52:34 by isunwoo          ###   ########.fr       */
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

void	init_stack(t_stack *st, int size);
int		pop_back(t_stack *st);
int		pop_front(t_stack *st);
void	push_back(t_stack *st, int num);
void	push_front(t_stack *st, int num);
int		ft_atoi(const char *str);
int	before_idx(t_stack *st, int idx);

void	sa(t_stack *a, t_stack *b);
void	sb(t_stack *a, t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a, t_stack *b);
void	rb(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a, t_stack *b);
void	rrb(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);




#endif
