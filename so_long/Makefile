# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/24 14:26:17 by isunwoo           #+#    #+#              #
#    Updated: 2022/09/24 14:33:47 by isunwoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= 	cc
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	so_long

SRCS	=	main.c	so_long.c

OBJS	=	$(SRCS:.c=.o)

$(NAME) : $(SRCS)
	$(CC) $(SRCS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

#$(OBJS) : $(SRCS)
#	$(CC) $(CFLAGS) -c $(SRCS)

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME) $(OBJS)

re : fclean all

.PHONY : all clean fclean re
