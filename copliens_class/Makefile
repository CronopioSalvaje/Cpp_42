CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Srcs/main.cpp

OBJS = main.o

INC = Includes/

NAME = class

all : $(NAME)


$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -c 

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS)  $(OBJS) -o $(NAME) 


clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all


