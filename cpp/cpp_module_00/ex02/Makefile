CXX			:=	c++
CXXFLAGS	:=	 -std=c++98
#-Wall -Wextra -Werror
SRCS		:=	Account.cpp	tests.cpp print_utils.cpp

INCS		:=	Account.hpp print_utils.hpp

NAME		:= tests


all	: $(NAME)

$(NAME)	:	$(SRCS)
	$(CXX) -o $@ $^

fclean :
	rm -f $(NAME)

re :
	make fclean
	make $(NAME)

.PHONY : all fclean re
