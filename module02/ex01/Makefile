CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp  Fixed.cpp

OBJS = main.o Fixed.o

INC = Includes/

NAME = fixed

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


