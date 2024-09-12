CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp

OBJS = main.o newZombie.o randomChump.o Zombie.o

INC = Includes/

NAME = zombie

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


