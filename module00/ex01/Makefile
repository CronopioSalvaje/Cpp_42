CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = AwPhoneBook.cpp PhoneBook.cpp Contact.cpp

OBJS = AwPhoneBook.o PhoneBook.o Contact.o

INC = Includes/

NAME = phonebook

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


