CC = cc
SRC = push_swap.c  push_swap_utils.c my_p.c insertion.c command.c steps/pa.c steps/pb.c steps/ra.c steps/rb.c steps/rra.c steps/rrb.c steps/rr.c steps/rrr.c steps/sa.c steps/sb.c steps/ss.c
OBJ = $(SRC:.c=.o)
CFLG = -Wall -Wextra -Werror
LIBFT = libft
NAME = push_swap
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	@make bonus -C $(LIBFT)
	$(CC) $(CFLG) $(OBJ) libft/libft.a -o $@

%.o:%.c Makefile push_swap.h
	$(CC) $(CFLG) -c $< -o $@

clean:
	@make clean -C $(LIBFT)
	$(RM) $(OBJ)

fclean: clean
	@make fclean -C $(LIBFT)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re 
