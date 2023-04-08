CXX			:=	c++
CXXFLAGS	:=	-Wall -Wextra -Werror -std=c++98
SRCS		:=	main.cpp\
				Zombie.cpp\
				zombieHorde.cpp\

INCS		:=	Zombie.hpp\

NAME		:=	test


all	: $(NAME)

$(NAME)	:	$(SRCS) $(INCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $@

fclean :
	rm -f $(NAME)

re :
	make fclean
	make $(NAME)

.PHONY : all fclean re
