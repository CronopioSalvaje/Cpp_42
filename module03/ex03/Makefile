CC = g++
CFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98

SRCS = main.cpp  ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp

OBJS = main.o ClapTrap.o ScavTrap.o FragTrap.o DiamondTrap.o

INC = Includes/

NAME = clapTrap

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


