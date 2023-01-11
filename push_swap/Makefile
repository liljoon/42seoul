# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/28 19:04:32 by isunwoo           #+#    #+#              #
#    Updated: 2023/01/09 21:58:53 by isunwoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	cc
#CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	push_swap.c	stack_func.c	stack_utils.c	ft_atoi.c

INCS	=	push_swap.h

OBJS	=	$(SRCS:.c=.o)

NAME	=	push_swap

.SUFFIXES : .c .o
.c.o :
	$(CC) -g -c $(CFLAGS) $< -o $@

$(NAME)	:	$(OBJS)
	gcc -g $(OBJS) -o $@

all	: $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME) $(OBJS)

re : fclean all

.PHONY : all clean fclean re
