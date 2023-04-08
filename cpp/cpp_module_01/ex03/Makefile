CXX			:=	c++
CXXFLAGS	:=	-Wall -Wextra -Werror -std=c++98
SRCS		:=	main.cpp\
				Weapon.cpp\
				HumanA.cpp\
				HumanB.cpp\

INCS		:=	Weapon.hpp\
				HumanA.hpp\
				HumanB.hpp\

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
