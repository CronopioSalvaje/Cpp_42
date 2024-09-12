CC = g++
CFLAGS = -Wall -Wextra -Werror -g -std=c++98

SRCS = Srcs/main.cpp  Srcs/Animal.cpp Srcs/Dog.cpp Srcs/Cat.cpp Srcs/Brain.cpp

OBJS = $(SRCS:.cpp=.o)

INC = Includes/

NAME = poly

all : $(NAME)

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS) -I INC $(SRCS) -c
	mv *.o Srcs/

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -I INC $(OBJS) -o $(NAME) 

clean :
	rm -rf Srcs/*.o

fclean : clean
	rm -f $(NAME)

re : fclean all
