# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 16:39:59 by isunwoo           #+#    #+#              #
#    Updated: 2023/02/03 01:34:22 by isunwoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	main.c	ft_atoi.c	philo.c	philo_utils.c

INCS	=	philo.h

OBJS	=	$(SRCS:.c=.o)

NAME	=	philo

.SUFFIXES : .c .o
.c.o :
	$(CC) -g -c $(CFLAGS) $< -o $@

$(NAME)	:	$(OBJS)
	$(CC) -g $(OBJS) -lpthread -o $@

all	: $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME) $(OBJS)

re :
	make fclean
	make $(NAME)

.PHONY : all clean fclean re
