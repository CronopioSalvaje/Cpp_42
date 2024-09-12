CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Account.cpp tests.cpp

OBJS = Account.o tests.o

INC = Includes/

NAME = bank

all : $(NAME)


$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -c 

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) 


clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all


