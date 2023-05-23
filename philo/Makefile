NAME = philo

SRCS = input.c main.c philo.c print.c routine.c

CC = cc

CFLAGS = -Wall -Werror -Wextra -g -pthread

OBJS = $(SRCS:.c=.o)

%.o: %.c 
	$(CC) $(CFLAG) -c $< -o $@ 

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re