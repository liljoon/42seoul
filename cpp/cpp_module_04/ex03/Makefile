CXX			:=	c++
CXXFLAGS	:=	-Wall -Wextra -Werror -std=c++98
LDFLAGS		:=

SRCS		:=	AMateria.cpp\
				Cure.cpp\
				Ice.cpp\
				Character.cpp\
				MateriaSource.cpp\
				main.cpp\

OBJS		:=	$(SRCS:.cpp=.o)

INCS		:=	AMateria.hpp\
				Cure.hpp\
				Ice.hpp\
				Character.hpp\
				ICharacter.hpp\
				IMateraiSource.hpp\
				MateriaSource.hpp\

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
