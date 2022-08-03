# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/03 18:25:06 by isunwoo           #+#    #+#              #
#    Updated: 2022/08/03 19:22:09 by isunwoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	=	-Wall -Wextra -Werror
NAME	=	libftprintf.a

SRCS	= ft_printf.c

OBJS	=	$(SRCS:.c=.o)


$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

$(OBJS) : $(SRCS)
	make -C ./libft
	$(CC) $(CFLAGS) -c $(SRCS) -I ./ -L ./libft -l ft

all : $(NAME)

clean :
	make clean -C ./libft
	rm -f $(OBJS)

fclean :
	make fclean -C ./libft
	rm -f $(NAME) $(OBJS)

re : fclean all

.PHONY : all clean fclean re
