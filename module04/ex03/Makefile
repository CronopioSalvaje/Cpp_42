CC = c++
CFLAGS = -Wall -Wextra -Werror -g -std=c++98

SRCS = Srcs/AMateria.cpp Srcs/Character.cpp Srcs/Cure.cpp Srcs/Ice.cpp Srcs/ICharacter.cpp Srcs/IMateriaSource.cpp Srcs/main.cpp Srcs/MateriaSource.cpp

OBJS = $(SRCS:.cpp=.o)

INC = Includes/

NAME = materia

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
