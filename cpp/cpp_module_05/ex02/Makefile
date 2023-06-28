CXX			:=	c++
CXXFLAGS	:=	-Wall -Wextra -Werror -std=c++98
LDFLAGS		:=

SRCS		:=	Bureaucrat.cpp\
				AForm.cpp\
				main.cpp\
				ShrubberyCreationForm.cpp\
				RobotomyRequestForm.cpp\
			#	PresidentialPardonForm.cpp\



OBJS		:=	$(SRCS:.cpp=.o)

INCS		:=	Bureaucrat.hpp\
				AForm.hpp\
				PresidentialPardonForm.hpp\
				RobotomyRequestForm.hpp\
				ShrubberyCreationForm.hpp\

NAME		:= a.out

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
