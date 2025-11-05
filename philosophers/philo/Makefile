NAME = philo

CC = cc
CFLGS = -Wall -Wextra -Werror -pthread

SRCS = dinner.c ft_bzero.c ft_isdigit.c ft_strlen.c messege.c ft_atoi.c ft_calloc.c philo.c
OBJS = $(SRCS:%.c=%.o)

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

