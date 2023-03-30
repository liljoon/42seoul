CXX			:=	c++
CXXFLAGS	:=	-Wall -Wextra -Werror -g -std=c++98

SRCS		:=	PhoneBook.cpp	Contact.cpp	main.cpp

INCS		:=	PhoneBook.hpp	Contact.hpp

OBJS		:=	$(SRCS:.cpp=.o)

NAME		:=	my_awesome_phonebook



.SUFFIXES : .cpp .o
.cpp.o :
	$(CXX) $(CXXFLAGS) -c $< -o $@

all	: $(NAME)

$(NAME)	:	$(OBJS)
	$(CXX) -o $@ $^

clean :
	rm -f $(OBJS)

fclean :
	make clean
	rm -f $(NAME)

re :
	make fclean
	make $(NAME)

.PHONY : all clean fclean re
