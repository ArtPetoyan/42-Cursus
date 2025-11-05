CC = cc
SRC = pipex.c utils.c
OBJ = $(SRC:.c=.o)
CFLG = -Wall -Wextra -Werror
LIBFT = libft
NAME = pipex
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	@make all -C $(LIBFT)
	$(CC) $(CFLG) $(OBJ) libft/libft.a -o $@

%.o:%.c Makefile pipex.h
	$(CC) $(CFLG) -c $< -o $@

clean:
	@make clean -C $(LIBFT)
	$(RM) $(OBJ) 

fclean: clean
	@make fclean -C $(LIBFT)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re 
