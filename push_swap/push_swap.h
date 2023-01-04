/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:45:14 by isunwoo           #+#    #+#             */
/*   Updated: 2023/01/02 19:51:28 by isunwoo          ###   ########.fr       */
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
void	swap(t_stack *st);
void	toss(t_stack *st1, t_stack *st2);
void	rotate(t_stack *st);
void	reverse_rotate(t_stack *st);
int		ft_atoi(const char *str);
int		next_idx(t_stack *st, int idx);
int		before_idx(t_stack *st, int idx);

#endif
