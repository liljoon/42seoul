# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/28 19:04:32 by isunwoo           #+#    #+#              #
#    Updated: 2023/01/28 19:05:35 by isunwoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	push_swap.c	stack_utils1.c	stack_utils2.c	sort_below_5.c	push_swap_utils.c\
			push_swap_preprocess.c		push_swap_partitioning.c	stack_func1.c	stack_func2.c	stack_func3.c\
			push_swap_func.c

SRCS_BNS=	ft_strncmp_bonus.c	get_next_line_bonus.c	get_next_line_utils_bonus.c	push_swap_bonus.c	push_swap_preprocess_bonus.c\
			push_swap_utils_bonus.c	stack_func1_bonus.c	stack_func2_bonus.c	stack_func3_bonus.c	stack_utils1_bonus.c stack_utils2_bonus.c

INCS	=	push_swap.h

INCS_BNS = push_swap_bonus.h get_next_line_bonus.h

OBJS	=	$(SRCS:.c=.o)

OBJS_BNS	=	$(SRCS_BNS:.c=.o)

NAME	=	push_swap

.SUFFIXES : .c .o
.c.o :
	$(CC) -g -c $(CFLAGS) $< -o $@

$(NAME)	:	$(OBJS)
	$(CC) -g $(OBJS) -o $@

all	: $(NAME) bonus

bonus : $(OBJS_BNS)
	$(CC) -g $(OBJS_BNS) -o checker
	touch bonus

clean :
	rm -f $(OBJS) $(OBJS_BNS) bonus

fclean : clean
	rm -f $(NAME) $(OBJS) $(OBJS_BNS) checker

re :
	make fclean
	make $(NAME)

.PHONY : all clean fclean re
