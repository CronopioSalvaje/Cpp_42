CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp

OBJS = main.o HumanA.o HumanB.o Weapon.o

INC = Includes/

NAME = violence

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


