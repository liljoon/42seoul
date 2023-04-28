CXX			:=	c++
CXXFLAGS	:=	-Wall -Wextra -Werror -std=c++98
LDFLAGS		:=

SRCS		:=	main.cpp\
				ClapTrap.cpp\
				ScavTrap.cpp\
				FragTrap.cpp\

OBJS		:=	$(SRCS:.cpp=.o)

INCS		:=	ClapTrap.hpp\
				ScavTrap.hpp\
				FragTrap.hpp\

NAME		:=	a.out

.SUFFIXES : .cpp .o
.cpp.o :
	$(CXX) $(CXXFLAGS) -c $< -o $@

all	: $(NAME)

$(NAME)	:	$(OBJS) $(INCS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $@

clean :
	rm -f $(OBJS)

fclean :
	make clean
	rm -f $(NAME)

re :
	make fclean
	make $(NAME)

.PHONY : all clean fclean re
