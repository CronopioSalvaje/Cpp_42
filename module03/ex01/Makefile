CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp  ClapTrap.cpp ScavTrap.cpp

OBJS = main.o ClapTrap.o ScavTrap.o

INC = Includes/

NAME = scavTrap

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


