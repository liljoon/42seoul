# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/24 14:26:17 by isunwoo           #+#    #+#              #
#    Updated: 2023/05/14 20:30:30 by isunwoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= 	cc
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	so_long

SRCS	=	main.c	so_long.c	so_long_draw.c	so_long_move.c \
			get_next_line/get_next_line.c		get_next_line/get_next_line_utils.c	so_long_map.c \
			so_long_map_count.c	so_long_map_check.c	so_long_map_check_dfs.c	so_long_utils.c

OBJS	=	$(SRCS:.c=.o)

INCS	=	get_next_line/get_next_line.h	so_long.h

$(NAME) : $(OBJS) $(INCS)
	$(CC) $(OBJS) -o $(NAME) -L./minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit

.SUFFIXES : .c .o
.c.o :
	$(CC) -c $(CFLAGS) $< -o $@ -I./minilibx_opengl_20191021

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME) $(OBJS)

re : fclean all

.PHONY : all clean fclean re
