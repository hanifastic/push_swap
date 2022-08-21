NAME	:= push_swap.a

APP		:= push_swap

CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror
FILES	:= $(wildcard *.c)
OBJ		:= $(FILES:%.c=%.o)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)
	$(CC) -o $(APP) $(NAME)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME) $(APP)

re: fclean all

.PHONY: all clean fclean re 
