CC = c++
CFLAGS = -Wall -Wextra -Werror -g -std=c++98

SRCS = Srcs/Bureaucrat.cpp Srcs/main.cpp Srcs/AForm.cpp Srcs/ShrubberyCreationForm.cpp \
Srcs/RobotomyRequestForm.cpp Srcs/PresidentialPardonForm.cpp Srcs/Intern.cpp

OBJS = $(SRCS:.cpp=.o)

INC = Includes/

NAME = bureaucrat

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
