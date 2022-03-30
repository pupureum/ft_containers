NAME	= ft_containers
FT_NAME = ft_binary
STD_NAME = std_binary

CC		= clang++ 
CFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS	= main.cpp
OBJS	= $(SRCS:.cpp=.o)

FT_SRCS	= ft_main.cpp
FT_OBJS	= $(FT_SRCS:.cpp=.o)

STD_SRCS	= std_main.cpp
STD_OBJS	= $(STD_SRCS:.cpp=.o)

all : $(NAME) $(FT_NAME) $(STD_NAME)

$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS)

$(FT_NAME): $(FT_OBJS)
	$(CC) -o $(FT_NAME) $(CFLAGS) $(FT_OBJS)

$(STD_NAME): $(STD_OBJS)
	$(CC) -o $(STD_NAME) $(CFLAGS) $(STD_OBJS)

%.o : %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	rm -rf $(OBJS) $(FT_OBJS) $(STD_OBJS)

fclean : clean
	rm -rf $(NAME) $(FT_NAME) $(STD_NAME)

re : fclean all

.PHONY : all clean fclean re