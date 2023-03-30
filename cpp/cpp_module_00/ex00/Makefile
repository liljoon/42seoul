CXX			:=	c++
CXXFLAGS	:=	-Wall -Wextra -Werror -std=c++98

SRCS		:=	megaphone.cpp

OBJS		:=	$(SRCS:.cpp=.o)

NAME		:=	megaphone

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
