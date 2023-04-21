CXX			:=	c++
CXXFLAGS	:=	-Wall -Wextra -Werror -std=c++98
LDFLAGS		:=

SRCS		:=	main.cpp\
				Animal.cpp\
				Dog.cpp\
				Cat.cpp\
				Brain.cpp\


OBJS		:=	$(SRCS:.cpp=.o)

INCS		:=	Animal.hpp\
				Dog.hpp\
				Cat.hpp\
				Brain.hpp\

NAME		:=	a.out

.SUFFIXES : .cpp .o
.cpp.o : $(INCS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

all	: $(NAME)

$(NAME)	:	$(OBJS)
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
