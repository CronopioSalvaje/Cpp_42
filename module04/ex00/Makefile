CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp  Animal.cpp Dog.cpp Cat.cpp WrongCat.cpp WrongAnimal.cpp

OBJS = main.o Animal.o Dog.o Cat.o WrongCat.o WrongAnimal.o

INC = Includes/

NAME = poly

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


