CXX			:=	c++
CXXFLAGS	:=	-Wall -Wextra -Werror -std=c++98

SRCS		:=	Fixed.cpp\
				main.cpp\

INCS		:=	Fixed.hpp\

NAME		:=	a.out


all	: $(NAME)

$(NAME)	:	$(SRCS) $(INCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $@

fclean :
	rm -f $(NAME)

re :
	make fclean
	make $(NAME)

.PHONY : all fclean re
