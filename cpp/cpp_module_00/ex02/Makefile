CXX			:=	c++
CXXFLAGS	:=	-Wall -Wextra -Werror -std=c++98
SRCS		:=	Account.cpp	tests.cpp print_utils.cpp

INCS		:=	Account.hpp print_utils.hpp

NAME		:= tests


all	: $(NAME)

$(NAME)	:	$(SRCS) $(INCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $@

fclean :
	rm -f $(NAME)

re :
	make fclean
	make $(NAME)

.PHONY : all fclean re
