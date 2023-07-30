CXX			:=	c++
CXXFLAGS	:=	-Wall -Wextra -Werror -std=c++98 -g
LDFLAGS		:=

SRCS		:=	main.cpp\
				BitcoinExchange.cpp\



OBJS		:=	$(SRCS:.cpp=.o)

INCS		:=	BitcoinExchange.hpp\

NAME		:=	btc

.SUFFIXES : .cpp .o
.cpp.o :
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
