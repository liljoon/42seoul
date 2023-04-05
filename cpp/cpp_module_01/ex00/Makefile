CXX			:=	c++
CXXFLAGS	:=	-Wall -Wextra -Werror -std=c++98
SRCS		:=	main.cpp\
				newZombie.cpp\
				randomChump.cpp\
				Zombie.cpp\

INCS		:=	Zombie.hpp\

NAME		:=	test


all	: $(NAME)

$(NAME)	:	$(SRCS) $(INCS)
	$(CXX) $(SRCS) -o $@

fclean :
	rm -f $(NAME)

re :
	make fclean
	make $(NAME)

.PHONY : all fclean re
