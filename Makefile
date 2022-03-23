NAME	= ft_containers

CC		= clang++ 
CFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS	= main.cpp
OBJS	= $(SRCS:.cpp=.o)


all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS)

%.o : %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	rm -rf $(OBJS) $(DEPS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re