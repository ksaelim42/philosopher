NAME = philo

SRC = input.c main.c philo.c print.c routine.c

CC = cc

CFLAGS = -Wall -Werror -Wextra -g -pthread

OBJ = $(SRC:.c=.o)

%o: %c 
	@$(CC) $(CFLAG) -c $< -o $@ 

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re