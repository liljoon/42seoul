# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 14:54:05 by isunwoo           #+#    #+#              #
#    Updated: 2022/11/18 14:46:26 by isunwoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	server.c	client.c	minitalk_utils.c

INCS	=	minitalk_utils.h

OBJS	=	$(SRCS:.c=.o)

NAME	=	server client

.SUFFIXES : .c .o
.c.o :
	$(CC) -c $(CFLAGS) $< -o $@

all	:	server	client

server	:	server.o $(INCS) minitalk_utils.o
	$(CC) -o $@ server.o minitalk_utils.o

client	:	client.o $(INCS) minitalk_utils.o
	$(CC) -o $@ client.o minitalk_utils.o

bonus	:	server_bonus.o client_bonus.o minitalk_utils_bonus.o minitalk_utils_bonus.h
	$(CC) -o server server_bonus.o minitalk_utils_bonus.o
	$(CC) -o client client_bonus.o minitalk_utils_bonus.o

clean :
	rm -f $(OBJS) server_bonus.o client_bonus.o minitalk_utils_bonus.o

fclean : clean
	rm -f $(NAME) $(OBJS)

re : fclean all

.PHONY : all clean fclean re
