# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/03 18:25:06 by isunwoo           #+#    #+#              #
#    Updated: 2022/08/05 18:18:27 by isunwoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	=	-Wall -Wextra -Werror
NAME	=	libftprintf.a

SRCS	= ft_printf.c	ft_printf_hex.c ft_printf_utils.c

OBJS	=	$(SRCS:.c=.o)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS) -I ./

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME) $(OBJS)

re : fclean all

.PHONY : all clean fclean re
