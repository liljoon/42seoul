CXX			:=	c++
CXXFLAGS	:=	-Wall -Wextra -Werror -std=c++98

SRCS		:=	PhoneBook.cpp	Contact.cpp	main.cpp

INCS		:=	PhoneBook.hpp	Contact.hpp

OBJS		:=	$(SRCS:.cpp=.o)

NAME		:=	my_awesome_phonebook


all	: $(NAME)

$(NAME)	:	$(SRCS) $(INCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $@

fclean :
	rm -f $(NAME)

re :
	make fclean
	make $(NAME)

.PHONY : all fclean re
