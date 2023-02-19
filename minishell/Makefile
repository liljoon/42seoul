# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 13:47:44 by isunwoo           #+#    #+#              #
#    Updated: 2023/02/19 20:33:14 by isunwoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	=	#-Wall -Wextra -Werror

SRCS	=	main.c	sig_handle.c	exec_command.c	ft_split.c	ft_memcpy.c	ft_strncmp.c \
			ft_strjoin.c	ft_itoa.c builtins1.c builtins2.c

INCS	=	minishell.h

OBJS	=	$(SRCS:.c=.o)

NAME	=	minishell

READLINE_I = -I${HOME}/.brew/opt/readline/include

READLINE_L = -lreadline -L${HOME}/.brew/opt/readline/lib


.SUFFIXES : .c .o
.c.o :
	$(CC) -g -c $(CFLAGS) $(READLINE_I) $< -o $@

$(NAME)	:	$(OBJS)
	$(CC) -g $(OBJS) $(READLINE_L) -o $@

all	: $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME) $(OBJS)

re :
	make fclean
	make $(NAME)

.PHONY : all clean fclean re
