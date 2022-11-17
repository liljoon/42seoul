# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 14:54:05 by isunwoo           #+#    #+#              #
#    Updated: 2022/11/16 20:38:42 by isunwoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	server.c	client.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	server client

.SUFFIXES : .c .o
.c.o :
	$(CC) -c $(CFLAGS) $< -o $@

all	:	server	client

server	:	server.o
	$(CC) -o $@ server.o

client	:	client.o
	$(CC) -o $@ client.o

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME) $(OBJS)

re : fclean all

.PHONY : all clean fclean re
